/*126. Word Ladder II

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation 
sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]

Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.*/

/*这道题比127.Word Ladder 词语阶梯要复杂很多，下面这种解法的核心思想是BFS，大概思路如下：我们的目的是找出所有的路径，
我们建立一个路径集paths，用以保存所有路径，然后是起始路径p，在p中先把起始单词放进去。然后定义两个整型变量level，和minLevel，
其中level是记录循环中当前路径的长度，minLevel是记录最短路径的长度，这样的好处是，如果某条路径的长度超过了已有的最短路径的长度，
那么舍弃，这样会提高运行速度，相当于一种剪枝。还要定义一个set变量words，用来记录已经循环过的路径中的词，然后就是BFS的核心了，
循环路径集paths里的内容，取出队首路径，如果该路径长度大于level，说明字典中的有些词已经存入路径了，如果在路径中重复出现，则肯定
不是最短路径，所以我们需要在字典中将这些词删去，然后将words清空，对循环对剪枝处理。然后我们取出当前路径的最后一个词，对每个字母
进行替换并在字典中查找是否存在替换后的新词，这个过程在之前那道Word Ladder 词语阶梯里面也有。如果替换后的新词在字典中存在，将其
加入words中，并在原有路径的基础上加上这个新词生成一条新路径，如果这个新词就是结束词，则此新路径为一条完整的路径，加入结果中，并
更新minLevel，若不是结束词，解将新路径加入路径集中继续循环*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<string> p{beginWord};
        queue<vector<string>> paths;
        paths.push(p);
        int level = 1, minLevel = INT_MAX;
        unordered_set<string> words;
        while (!paths.empty()) {
            auto t = paths.front(); paths.pop();
            if (t.size() > level) {
                for (string w : words) dict.erase(w);
                words.clear();
                level = t.size();
                if (level > minLevel) break;
            }
            string last = t.back();
            for (int i = 0; i < last.size(); ++i) {
                string newLast = last;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newLast[i] = ch;
                    if (!dict.count(newLast)) continue;
                    words.insert(newLast);
                    vector<string> nextPath = t;
                    nextPath.push_back(newLast);
                    if (newLast == endWord) {
                        res.push_back(nextPath);
                        minLevel = level;
                    } else paths.push(nextPath);
                }
            }
        }
        return res;
    }
};