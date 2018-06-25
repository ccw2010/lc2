/* 159. Longest Substring with At Most Two Distinct Characters

Given a string s, find the length of the longest substring t that contains at most 2 distinct characters.

Example 1:
Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.

Example 2:
Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
*/


/*这道题给我们一个字符串，让我们求最多有两个不同字符的最长子串。那么我们首先想到的是用哈希表来做，哈希表记录每个字符的出现次数，
然后如果哈希表中的映射数量超过两个的时候，我们需要删掉一个映射，比如此时哈希表中e有2个，c有1个，此时把b也存入了哈希表，那么就有
三对映射了，这时我们的left是0，先从e开始，映射值减1，此时e还有1个，不删除，left自增1。这是哈希表里还有三对映射，此时left是1，
那么到c了，映射值减1，此时e映射为0，将e从哈希表中删除，left自增1，然后我们更新结果为i - left + 1，以此类推直至遍历完整个字符串*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            m[s[i]]++;
            while (m.size() > 2) {
            	m[s[left]]--;
                if (m[s[left]] == 0) m.erase(s[left]);
                left++;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};


/* 除了用哈希表来映射字符出现的个数，我们还可以映射每个字符最新的坐标，比如题目中的例子"eceba"，遇到第一个e，映射其坐标0，
遇到c，映射其坐标1，遇到第二个e时，映射其坐标2，当遇到b时，映射其坐标3，每次我们都判断当前哈希表中的映射数，如果大于2的时候，
那么我们需要删掉一个映射，我们还是从left=0时开始向右找，我们看每个字符在哈希表中的映射值是否等于当前坐标left，比如第一个e，
哈希表此时映射值为2，不等于left的0，那么left自增1，遇到c的时候，哈希表中c的映射值是1，和此时的left相同，那么我们把c删掉，
left自增1，再更新结果，以此类推直至遍历完整个字符串，参见代码如下 */

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            m[s[i]] = i;
            while (m.size() > 2) {
                if (m[s[left]] == left) m.erase(s[left]);
                left++;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};







