/*
 * @Descroption: LeetCode 405. ����ת��Ϊʮ��������
 * @Author: EmoryHuang
 * @Date: 2021-10-02 16:44:42
 * @Method:
 * λ����
 * ���� num��ÿ4λ��Ӧһ��ʮ������λ
 * ʹ��0xf(00...01111b)��ȡnum�ĵ�4λ
 */

class Solution {
   public:
    string toHex(int num) {
        if (num == 0) return "0";
        string hash = "0123456789abcdef", ans;
        while (num && ans.size() < 8) {
            ans = hash[0xf & num] + ans;
            num >>= 4;
        }
        return ans;
    }
};