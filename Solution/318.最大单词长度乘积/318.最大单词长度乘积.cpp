/*
 * @Descroption: LeetCode 318. 最大单词长度乘积
 * @Author: EmoryHuang
 * @Date: 2021-11-17 09:17:40
 * @Method:
 * 位运算
 * 使用 bits 记录每个字母是否出现
 * 然后遍历 mask 使用 & 运算，若为 0 则说明没有重复字母
 */

class Solution {
   public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask;
        for (auto word : words) {
            // 使用 bits 记录每个字母是否出现
            int bits = 0;
            for (auto c : word) bits |= 1 << (c - 'a');
            mask.push_back(bits);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                // & 运算，若为 0 则说明没有重复字母
                if ((mask[i] & mask[j]) == 0) ans = max(ans, (int)words[i].size() * (int)words[j].size());
        return ans;
    }
};