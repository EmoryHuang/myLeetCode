/*
 * @Descroption: LeetCode 670. ��󽻻�
 * @Author: EmoryHuang
 * @Date: 2021-11-08 21:06:30
 * @Method:
 * ����һ������
 * Ѱ�ҵ�ǰ�ַ���������ֵ�������ֵ��Ϊ��ǰ�ַ�������н���
 *
 * ������������
 * �� num �е����ִӴ�С�Ľ�������
 * Ȼ����ԭ����һһ�Ƚϣ������ĵ�һ����ͬ��ֵ������Ҫ������ֵ
 */

class Solution {
   public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<char> a(s.begin(), s.end());
        vector<char> b = a;
        sort(b.begin(), b.end(), [](char x, char y) { return x > y; });
        int idx = -1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) return num;
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] == b[idx]) {
                swap(a[i], a[idx]);
            }
        }
        string ans(a.begin(), a.end());
        return stoi(ans);
    }
};