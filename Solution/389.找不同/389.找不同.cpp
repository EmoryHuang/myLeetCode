/*
 * @Descroption: LeetCode 389. �Ҳ�ͬ
 * @Author: EmoryHuang
 * @Date: 2021-05-20 20:10:37
 * @����˼·:
 * ����һ����ϣ��
 *
 * �����������
 * ÿ���ַ��� ASCII ���ֵ���
 *
 * �����������
 * ���ַ����г��������ε��ַ�
 */

class Solution {
   public:
    // �����������
    // char findTheDifference(string s, string t) {
    //     int ans = 0;
    //     for (char ch : s) ans -= ch;
    //     for (char ch : t) ans += ch;
    //     return ans;
    // }

    // �����������
    char findTheDifference(string s, string t) {
        int ans = 0;
        for (char ch : s) ans ^= ch;
        for (char ch : t) ans ^= ch;
        return ans;
    }
};
