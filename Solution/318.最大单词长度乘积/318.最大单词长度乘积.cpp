/*
 * @Descroption: LeetCode 318. ��󵥴ʳ��ȳ˻�
 * @Author: EmoryHuang
 * @Date: 2021-11-17 09:17:40
 * @Method:
 * λ����
 * ʹ�� bits ��¼ÿ����ĸ�Ƿ����
 * Ȼ����� mask ʹ�� & ���㣬��Ϊ 0 ��˵��û���ظ���ĸ
 */

class Solution {
   public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask;
        for (auto word : words) {
            // ʹ�� bits ��¼ÿ����ĸ�Ƿ����
            int bits = 0;
            for (auto c : word) bits |= 1 << (c - 'a');
            mask.push_back(bits);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                // & ���㣬��Ϊ 0 ��˵��û���ظ���ĸ
                if ((mask[i] & mask[j]) == 0) ans = max(ans, (int)words[i].size() * (int)words[j].size());
        return ans;
    }
};