/*
 * @Descroption: LeetCode 830. 较大分组的位置
 * @Author: EmoryHuang
 * @Date: 2021-06-19 15:41:00
 * @解题思路:
 * 一次遍历并进行计数
 * 如果当前字符与后一个字符不同并且分组长度达到 3，则加入
 */

class Solution {
   public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int cnt = 1;
        for (int i = 0; i < s.size(); i++) {
            if (i == s.size() - 1 || s[i] != s[i + 1]) {
                if (cnt >= 3) ans.push_back({i - cnt + 1, i});
                cnt = 1;
            } else
                cnt += 1;
        }
        return ans;
    }
};