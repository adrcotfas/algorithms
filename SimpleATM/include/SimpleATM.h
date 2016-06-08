#include <map>
#include <list>

/** brief map of (banknote type, banknote amount)*/ 
typedef std::map<int, int> Banknotes;
typedef std::pair<bool, Banknotes> ATMResult;

class SimpleATM {

public:

    /** brief Inserts money into this ATM.
     *  param[in] type - the type of banknote, for example 10, 50 or 100.
     *  param[in] quantity - the amount of banknotes.
     *  returns void
     */
    void Insert(const int type, const int quantity);

    /** brief Extracts money from this ATM. The largest notes are preferred.
     *  param[in] quantity - the ammount of desired money to be extracted from this ATM.
     *  returns true and Banknotes object corresponding to the requested amount for a successful operation,
                false and Banknotes object not corresponding to the requeste amount but hinting the user
                for a new possible extraction which would be successful.
     */
    ATMResult Extract(int quantity);
    
    /** brief Returns the available amount of money in this ATM.
     *  returns the total amount of money according to available banknote types and quantity.
     */
    int GetTotalAmount() const;
    
private:

    /** brief Subtacts the given type and amount of banknotes from the ones available.
     *  param[in] notes - the notes to be subtracted.
     *  returns void
     */
    void SubtractFromNotes(const Banknotes& notes);
    
    Banknotes mBancnotes;
};