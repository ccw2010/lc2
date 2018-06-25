/*132. Palindrome Partitioning II

Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Example:
Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.*/

/*这道题是让找到把原字符串拆分成回文串的最小切割数，需要用动态规划Dynamic Programming来做，使用DP的核心是
在于找出递推公式，之前有道地牢游戏Dungeon Game的题也是需要用DP来做，而那道题是二维DP来解，这道题由于只是拆分
一个字符串，需要一个一维的递推公式，我们还是从后往前推，递推公式为：
dp[i] = min(dp[i], 1+dp[j+1] )  i <= j < n，
那么还有个问题，是否对于i到j之间的子字符串s[i][j]每次都判断一下是否是回文串，其实这个也可以用DP来简化，其DP递推公式为
P[i][j] = s[i] == s[j] && palindrome[i+1][j-1]，其中 palindrome[i][j] = true if [i,j] 为回文*/

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        int palindrome[n][n] = {0};
        int dp[n+1];
        for (int i = 0; i <= n; i++) {
            dp[i] = n-i-1;
        }
        for (int i = n-1; i>=0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j-i <= 1 || palindrome[i+1][j-1])) {
                    palindrome[i][j] = 1;
                    dp[i] = min(dp[i], dp[j+1] + 1);
                }
            }
        }
        return dp[0];
    }
};








