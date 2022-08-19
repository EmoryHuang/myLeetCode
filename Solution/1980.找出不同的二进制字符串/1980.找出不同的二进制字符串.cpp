/*
 * @Descroption: LeetCode 1980. 找出不同的二进制字符串
 * @Author: EmoryHuang
 * @Date: 2021-11-06 16:17:44
 * @Method:
 * 回溯
 * dfs 遍历字符串，若找到了一个不同的二进制字符串，则跳出循环
 */

class Solution {
   public:
    string ans;
    bool flag = false;
    void dfs(unordered_set<string> s, string cur) {
        if (!flag) {
            if (cur.size() == s.size()) {
                if (s.count(cur) == 0) {
                    ans = cur;
                    flag = true;
                }
                return;
            }
            dfs(s, cur + '0');
            dfs(s, cur + '1');
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s(nums.begin(), nums.end());
        dfs(s, "");
        return ans;
    }
};