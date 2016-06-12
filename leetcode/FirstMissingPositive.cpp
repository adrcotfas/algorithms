/**
 * source: https://leetcode.com/problems/first-missing-positive/
 *
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 */

class Solution {
public:

    static bool isNegative (int i) {
        return i <= 0;
    }
    int firstMissingPositive(vector<int>& nums) {
        
        // sort and erase duplicates and negative numbers
        sort(nums.begin(), nums.end());
        nums.erase( unique(nums.begin(), nums.end() ), nums.end() );
        nums.erase( remove_if(nums.begin(), nums.end(), isNegative), nums.end() );
        
        if (nums.size() == 0)
        {
            return 1;
        }
        
        int curentIdx = 1;
        while (curentIdx < nums.back())
        {
            for (int i = 0; i < nums.size(); ++i)
            {
                if ( find(nums.begin(), nums.end(), curentIdx) == nums.end())
                    return curentIdx;
                else
                    ++curentIdx;
            }
        }
        return nums.back() + 1;
    }
};