17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the 
number could represent. A mapping of digit to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].


class Solution {
public:
    vector<string> letterCombinations(const string &nums) {
        vector<string> res;
        if (nums.empty()) return res;
        string m[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for (int i = 0; i < nums.size(); i++){
            vector<string> solution;
            string chars = m[nums[i] - '0'];  
            for (auto existing : res){
                for (auto c : chars){
                    solution.push_back(existing + c);
                }
            }
            res = solution;
        }
        return res;
    }
};