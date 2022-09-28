/*
 * @Descroption: LeetCode 942. 增减字符串匹配
 * @Author: EmoryHuang
 * @Date: 2021-06-04 14:07:00
 * @解题思路:
 * 维护当前未使用的最小和最大的数，从左向右扫描字符串，
 * 如果碰到 'I'，就取出当前最小的数，否则取出当前最大的数
 */

class Solution {
   public:
    vector<int> diStringMatch(string s) {
        int low = 0, high = s.size();
        vector<int> ans;
        for (auto c : s) {
            if (c == 'I')
                ans.push_back(low++);
            else if (c == 'D')
                ans.push_back(high--);
        }
        ans.push_back(low);
        return ans;
    }
};