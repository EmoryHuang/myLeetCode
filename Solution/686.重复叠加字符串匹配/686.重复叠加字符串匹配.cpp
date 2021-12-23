/*
 * @Descroption: LeetCode 686. �ظ������ַ���ƥ��
 * @Author: EmoryHuang
 * @Date: 2021-12-22 08:56:58
 * @Method:
 * ��� A �ĳ���С�� B �ĳ��ȣ���ʱ B �� A ���ظ��Ӵ���
 * �� A ���ظ����������� len(B) / len(A) + 2
 * */


class Solution {
   public:
    int repeatedStringMatch(string a, string b) {
        int n = b.size() / a.size();
        string rep = a;
        // ��� A �ĳ���С�� B �ĳ��ȣ���ʱ B �� A ���ظ��Ӵ���
        // �� A ���ظ����������� len(B) / len(A) + 2
        for (int i = 1; i <= n + 2; i++) {
            if (rep.find(b) != string::npos) return i;
            rep += a;
        }
        return -1;
    }
};