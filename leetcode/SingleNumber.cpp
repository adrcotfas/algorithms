/**
 * source: https://leetcode.com/problems/single-number/
 *
 * Given an array of integers, every element appears twice except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity.
 * Could you implement it without using extra memory?
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // XOR solution
        return nums.size() == 0 ? 0 
                                : accumulate(nums.begin(),
                                             nums.end(),
                                             0,
                                             bit_xor<int>());
    }
};