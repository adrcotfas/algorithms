/**
 * source: https://leetcode.com/problems/bulls-and-cows/
 *
 * For example:
 *
 * Secret number:  "1807"
 * Friend's guess: "7810"
 * Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
 * Write a function to return a hint according to the secret number and friend's guess,
 * use A to indicate the bulls and B to indicate the cows. In the above example,
 * your function should return "1A3B".
*/

class Solution {
public:
    string getHint(string secret, string guess) 
    {
        short cows = 0;
        short bulls = 0;
        
        short vecS[10] = {0};
        short vecG[10] = {0};
        
        for (short i = 0; i < secret.size(); ++i)
        {
            if (guess.at(i) == secret.at(i)) {
                ++bulls;
            } else {
                ++vecG[guess.at(i) - '0'];
                ++vecS[secret.at(i) - '0'];
            }
        }
        
        for (int i = 0; i < 10; ++i){
            cows += min(vecG[i], vecS[i]);
        }
        
        return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
    }
};

/*
Explanation of - '0'
- Character encodings(ASCII, UTF-x etc) for digits are all in order from 48 (for '0') to 57 (for '9')
- - '0' is equivalent to - 48
*/