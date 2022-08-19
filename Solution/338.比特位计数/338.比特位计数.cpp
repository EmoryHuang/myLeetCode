/*
 * @Descroption: LeetCode 338. ����λ����
 * @Author: EmoryHuang
 * @Date: 2021-03-26 10:29:36
 * @����˼·:
 * �����������Ʊ�ʾ�У�����һ����ǰ���Ǹ�ż����һ�� 1����Ϊ��ľ������λ�� 1
 * ������
 *     0 = 0       1 = 1
 *     2 = 10      3 = 11
 * ż���������Ʊ�ʾ�У�ż���� 1 �ĸ���һ���ͳ��� 2 ֮����Ǹ���һ����
 * ������
 *     2 = 10       4 = 100       8 = 1000
 *     3 = 11       6 = 110       12 = 1100
 */

class Solution {
   public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        ans[0] = 0;
        for (int i = 1; i <= num; i++) {
            if (i % 2 == 0)
                ans[i] = ans[i / 2];
            else
                ans[i] = ans[i / 2] + 1;
        }
        return ans;
    }
};