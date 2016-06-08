#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>


std::size_t merge(std::vector<int>& vec, const std::vector<int>& left, const std::vector<int>& right) {
    
    vec.clear();
    std::size_t inversions = 0;
    std::vector<int>::const_iterator leftIter = left.begin();
    std::vector<int>::const_iterator rightIter = right.begin();

    while (leftIter != left.end() && rightIter != right.end()) {
        if (*leftIter < *rightIter) {
            vec.push_back(*leftIter);
            ++leftIter;
        }
        else {
            vec.push_back(*rightIter);
            ++rightIter;
            inversions += std::distance(leftIter, left.end());
        }
    }

    while (leftIter != left.end()) {
        vec.push_back(*leftIter);
        ++leftIter;
    }

    while (rightIter < right.end()) {
        vec.push_back(*rightIter);
        ++rightIter;
    }

    return inversions;
}


std::size_t mergeSort(std::vector<int>& input) {
    std::size_t inversions = 0;
    std::size_t length = input.size();
    if (length <= 1) {
        return inversions;
    }

    std::vector<int> left(input.begin(), input.begin() + length / 2);
    std::vector<int> right(input.begin() + length / 2, input.end());

    inversions += mergeSort(left);
    inversions += mergeSort(right);
    inversions += merge(input, left, right);

    return inversions;
}

int main() {
    std::ifstream inputFile( "C:/IntegerArray.txt");
    std::istream_iterator<int> start(inputFile);
    std::istream_iterator<int> end;
    std::vector<int> externalData(start, end);

    std::size_t inversions = mergeSort(externalData);
    return 0;
}