#include "SimpleATM.h"

void SimpleATM::Insert(const int type, const int quantity) {
    mBancnotes.find(type) != mBancnotes.end() ? mBancnotes[type]  = quantity
                                              : mBancnotes[type] += quantity;
}

int SimpleATM::GetTotalAmount() const
{
    int result = 0;
    for (auto i : mBancnotes) {
        result += (i.first * i.second);
    }
    return result;
}

ATMResult SimpleATM::Extract(int quantity) {
    
    Banknotes result;
    /* reverse iterate through all note types until the requested sum is completely covered.*/
    for (auto i = mBancnotes.rbegin(); i != mBancnotes.rend(); ++i) {
        int quotient = quantity / i->first;
        if (quotient < i->second) {
            result[i->first] = quotient;
            quantity -= quotient * i->first;
        }
        else {
            result[i->first] = i->second;
            quantity -= i->first * i->second;
        }
        if (0 == quantity) {
            break;
        }
    }
    if (quantity == 0){
        SubtractFromNotes(result);
    }
    return ATMResult((0 == quantity), result);
}

void SimpleATM::SubtractFromNotes(const Banknotes& notes)
{
    for (auto i : notes) {
        mBancnotes[i.first] -= i.second;
    }
}