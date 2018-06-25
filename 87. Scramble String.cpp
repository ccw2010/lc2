/*87. Scramble String

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty 
substrings recursively.
Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Example 1:
Input: s1 = "great", s2 = "rgeat"
Output: true

Example 2:
Input: s1 = "abcde", s2 = "caebd"
Output: false
*/


/*这道题定义了一种爬行字符串，就是说假如把一个字符串当做一个二叉树的根，然后它的非空子字符串是它的子节点，
然后交换某个子字符串的两个子节点，重新爬行回去形成一个新的字符串，这个新字符串和原来的字符串互为爬行字符串。
这道题可以用递归Recursion或是动态规划Dynamic Programming来做，我们先来看递归的解法，简单的说，就是s1和
s2是scramble的话，那么必然存在一个在s1上的长度l1，将s1分成s11和s12两段，同样有s21和s22.那么要么s11和s21
是scramble的并且s12和s22是scramble的；要么s11和s22是scramble的并且s12和s21是scramble的。就拿题目中的例子
rgeat 和 great 来说，rgeat 可分成 rg 和 eat 两段， great 可分成 gr 和 eat 两段，rg 和 gr 是scrambled的，
eat 和 eat 当然是scrambled。*/


// Recursion
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n != s2.size()) return false;
        if (s1 == s2) return true;
        string str1 = s1, str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if (str1 != str2) return false;
        for (int i = 1; i < n; i++) {
            string p1 = s1.substr(0, i);
            string p2 = s1.substr(i);
            string q1 = s2.substr(0, i);
            string q2 = s2.substr(i);
            if (isScramble(p1, q1) && isScramble(p2, q2)) return true;
            q1 = s2.substr(n-i);
            q2 = s2.substr(0, n-i);
            if (isScramble(p1, q1) && isScramble(p2, q2)) return true;
        }
        return false;
    }
};







