/*
 * @Descroption: LeetCode 1881. ���������ֵ
 * @Author: EmoryHuang
 * @Date: 2021-09-10 20:21:30
 * @Method:
 * ��� n �Ǹ�����Ѱ�� n �е�һ���� x ���λ�ò���
 * ��� n ��������Ѱ�� n �е�һ���� x С��λ�ò���
 */

class Solution {
   public:
    string maxValue(string n, int x) {
        int len = n.size();
        if (n[0] == '-') {
            for (int i = 1; i < len; i++)
                if (n[i] - '0' > x) {
                    n.insert(i, 1, x + '0');
                    return n;
                }
            n.push_back(x + '0');
            return n;
        } else {
            for (int i = 0; i < len; i++)
                if (n[i] - '0' < x) {
                    n.insert(i, 1, x + '0');
                    return n;
                }
            n.push_back(x + '0');
            return n;
        }
    }
};