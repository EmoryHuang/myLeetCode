/*
 * @Descroption: LeetCode 1684. ͳ��һ���ַ�������Ŀ
 * @Author: EmoryHuang
 * @Date: 2021-09-22 16:44:05
 * @Method:
 * ���⣬�����ж�ÿ�������������ַ��Ƿ��� allowed ��
 */

class Solution {
   public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        for (auto word : words) {
            bool flag = 1;
            for (auto c : word) {
                if (allowed.find(c) == string::npos) {
                    flag = 0;
                    break;
                }
            }
            if (flag) ans += 1;
        }
        return ans;
    }
};