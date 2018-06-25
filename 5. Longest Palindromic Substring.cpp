/*5. Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length 
of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        int left = 0, right = 0, len = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < i; j++) {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                if (dp[j][i] && len < i - j + 1) {
                    len = i - j + 1;
                    left = j;
                    right = i;
                }
            }
            dp[i][i] = true;
        }
        return s.substr(left, right - left + 1);
    }
};