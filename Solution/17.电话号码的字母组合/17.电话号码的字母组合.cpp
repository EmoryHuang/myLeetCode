/*
 * @Descroption: LeetCode 17. 电话号码的字母组合
 * @Author: EmoryHuang
 * @Date: 2021-03-22 14:53:36
 * @解题思路: DFS + 哈希表
 * 每次取电话号码的一位数字，从哈希表中获得该数字对应的所有可能的字母，
 * 并将其中的一个字母插入到已有的字母排列后面，然后继续处理电话号码的后一位数字，
 * 直到处理完电话号码中的所有数字，即得到一个完整的字母排列
 */

class Solution {
   public:
    string temp;
    vector<string> ans;
    vector<string> strs = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void DFS(int pos, string digits) {
        if (pos == digits.size()) {
            ans.push_back(temp);
            return;
        }
        int num = digits[pos] - '0';
        for (int i = 0; i < strs[num].size(); i++) {
            temp.push_back(strs[num][i]);
            DFS(pos + 1, digits);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return ans;
        DFS(0, digits);
        return ans;
    }
};