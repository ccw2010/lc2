/*74. Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

Example 2:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/

/*Use binary search.
n * m matrix convert to an array => matrix[x][y] => a[x * m + y]
an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &m, int k) {
        if(m.empty() || m[0].empty()) return false;
        int row = m.size();
        int col = m[0].size();
        int i = 0, j = row * col - 1;
        while (i < j){
            int mid = (i + j) / 2;
            if (m[mid/col][mid%col] < k)
                i = mid + 1;
            else 
                j = mid;
        }
        return m[i/col][i%col] == k;
    }
};

