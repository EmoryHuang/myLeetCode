/*
 * @Descroption: LeetCode 1414. ��Ϊ K ������쳲�����������Ŀ
 * @Author: EmoryHuang
 * @Date: 2021-06-05 15:32:00
 * @����˼·:
 * ̰��˼�룬�Ӵ�Сѡ��쳲���������
 */

class Solution {
   public:
    int findMinFibonacciNumbers(int k) {
        vector<int> f(2, 1);
        int a = 1, b = 1;
        while (a + b <= k) {
            f.push_back(a + b);
            int tmp = a + b;
            a = b;
            b = tmp;
        }
        int count = 0;
        for (int i = f.size() - 1; i >= 0; i--)
            if (k >= f[i]) {
                k -= f[i];
                count++;
            }
        return count;
    }
};