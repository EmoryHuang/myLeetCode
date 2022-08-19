/*
 * @Descroption: LeetCode 1945. �ַ���ת����ĸ�λ����֮��
 * @Author: EmoryHuang
 * @Date: 2021-11-08 10:58:50
 * @Method:
 * ���⣬���ַ���ת��Ϊ���֣�Ȼ���ظ� k �β����õ���λ����֮��
 */

class Solution {
   public:
    int getLucky(string s, int k) {
        string ans = "";
        for (char c : s) ans += to_string(c - 'a' + 1);
        while (k--) {
            int sum = 0;
            for (char c : ans) sum += c - '0';
            ans = to_string(sum);
        }
        return stoi(ans);
    }
};