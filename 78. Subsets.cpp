/*78. Subsets
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.

Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/*这道求子集合的问题，由于其要列出所有结果，按照以往经验肯定要是要用递归来做。而这道题它的非递归解法相对来说
更简单一点。由于题目要求子集合中数字的顺序是非降序排列的，所有我们需要预处理，先给输入数组排序，然后再进一步处理，
最开始我在想的时候，是想按照子集的长度由少到多全部写出来，比如子集长度为0的就是空集，空集是任何集合的子集，满足条件，
直接加入。下面长度为1的子集，直接一个循环加入所有数字，子集长度为2的话可以用两个循环，但是这种想法到后面就行不通了，
因为循环的个数不能无限的增长，所以我们必须换一种思路。我们可以一位一位的网上叠加，比如对于题目中给的例子[1,2,3]来说，
最开始是空集，那么我们现在要处理1，就在空集上加1，为[1]，现在我们有两个自己[]和[1]，下面我们来处理2，我们在之前的子集
基础上，每个都加个2，可以分别得到[2]，[1, 2]，那么现在所有的子集合为[], [1], [2], [1, 2]，同理处理3的情况可得
[3], [1, 3], [2, 3], [1, 2, 3], 再加上之前的子集就是所有的子集合了

整个添加的顺序为：
[]
[1]
[2]
[1 2]
[3]
[1 3]
[2 3]
[1 2 3]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int size = res.size();
            for (int j = 0; j < size; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};

