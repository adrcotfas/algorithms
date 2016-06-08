#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <iterator>

enum PivotType {
    FIRST_ELEMENT,
    LAST_ELEMENT,
    MEDIAN_ELEMENT,
    RANDOM_ELEMENT
};

template<typename Iter>
void quickSort(Iter begin, Iter end, PivotType pivotType) {
    
    if (begin == end)
        return;

    std::iterator_traits<Iter>::value_type pivot = 0;
    switch (pivotType) {
        default:
        case FIRST_ELEMENT:
        case RANDOM_ELEMENT: /// TODO: implement random pivot
            pivot = *begin;
            break;
        case LAST_ELEMENT:
            pivot = *(end - 1);
            break;
        case MEDIAN_ELEMENT:
            pivot = *std::next(begin, std::distance(begin, end) / 2);
            break;
    }

    Iter middle1 = std::partition(begin, end, [pivot](const auto& em) { return em < pivot; });
    Iter middle2 = std::partition(middle1, end, [pivot](const auto& em) { return !(pivot < em); });
    
    quickSort(begin, middle1, pivotType);
    quickSort(middle2, end, pivotType);
}

int main() {
    std::ifstream inputFile("C:/QuickSort.txt");
    std::istream_iterator<int> start(inputFile);
    std::istream_iterator<int> end;
    std::vector<int> externalData(start, end);
    
    quickSort(externalData.begin(), externalData.end(), PivotType::FIRST_ELEMENT);
    return 0;
}