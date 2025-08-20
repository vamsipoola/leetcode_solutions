/*
Problem:2348. count square submatrices with all ones
LeetCode URL:https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/?envType=daily-question&envId=2025-08-20
Difficulty: Medium
Language: C++


Description:Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
*/
class Solution {
public:
    int mini(int & a,int &b,int&c){
        int d = min(a,b);
        int e = min(c,d);
        return e;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n =matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int sum = 0;
        for(int i =0;i<n;i++){
            dp[i][0]=matrix[i][0];
            sum +=matrix[i][0];
        }
        for(int i=1;i<m;i++){
            dp[0][i] = matrix[0][i];
            sum += matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==1){
                    dp[i][j] = mini(dp[i-1][j],dp[i-1][j-1],dp[i][j-1])+1;
                    sum +=dp[i][j];
                }

            }
        }
        return sum;
    }
};