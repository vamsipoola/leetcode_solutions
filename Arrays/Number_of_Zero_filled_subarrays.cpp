/*
Problem:2348. Number of Zero-Filled Subarrays
LeetCode URL:https://leetcode.com/problems/number-of-zero-filled-subarrays/description/?envType=daily-question&envId=2025-08-19
Difficulty: Medium
Language: C++


Description:Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 Example 1:

Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation: 
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.
*/
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long i = 0;
        long long count = 0;
        while(i<n){
            if(nums[i]==0){
                count = count +1;
            }
            else {
                sum += (count*(count+1))/2;
                count=0;
            }
            i++;
            
        }
        sum += (count*(count+1))/2;
        
        return sum;
        
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/