/*3446. Sort Matrix by Diagonals


problem link:https://leetcode.com/problems/sort-matrix-by-diagonals/description/?envType=daily-question&envId=2025-08-28
You are given an n x n square matrix of integers grid. Return the matrix such that:

The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
The diagonals in the top-right triangle are sorted in non-decreasing order.
 

Example 1:

Input: grid = [[1,7,3],[9,8,2],[4,5,6]]

Output: [[8,2,3],[9,6,7],[4,5,1]]

Explanation:



The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:

[1, 8, 6] becomes [8, 6, 1].
[9, 5] and [4] remain unchanged.
The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:

[7, 2] becomes [2, 7].
[3] remains unchanged.


solution::

*/
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Diagonals starting from first column
        for(int i = 0; i < n; i++){
            vector<int> diag;
            int row = i, col = 0;
            while(row < n && col < n) diag.push_back(grid[row++][col++]);
            
            sort(diag.begin(), diag.end(), greater<int>()); // descending
            
            row = i; col = 0; int idx = 0;
            while(row < n && col < n) grid[row++][col++] = diag[idx++];
        }

        // Diagonals starting from first row (excluding first element)
        for(int j = 1; j < n; j++){
            vector<int> diag;
            int row = 0, col = j;
            while(row < n && col < n) diag.push_back(grid[row++][col++]);
            
            sort(diag.begin(), diag.end()); // ascending
            
            row = 0; col = j; int idx = 0;
            while(row < n && col < n) grid[row++][col++] = diag[idx++];
        }

        return grid;
    }
};
