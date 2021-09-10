/*
 * @Descroption: LeetCode 1742. ������С����������
 * @Author: EmoryHuang
 * @Date: 2021-05-25 13:04:11
 * @����˼·:
 * ��ϣ���¼ÿ�������е�С��������ȡ���ֵ
 */

class Solution {
   public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> sum(50);
        int ans = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int x = i, box = 0;
            while (x) {
                box += x % 10;
                x /= 10;
            }
            sum[box]++;
            ans = max(ans, sum[box]);
        }
        return ans;
    }
};