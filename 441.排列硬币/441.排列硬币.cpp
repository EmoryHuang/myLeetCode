/*
 * @Descroption: LeetCode 441. ����Ӳ��
 * @Author: EmoryHuang
 * @Date: 2021-07-22 20:00:05
 * @����˼·:
 * ����һ������
 * ���ַ�Ѱ���Ҷ˵�
 * ���������ⷽ��
 * x(x+1)/2=n
 */

class Solution {
   public:
    // ����һ������
    // int arrangeCoins(int n) {
    //     int l = 1, r = n / 2 + 1;
    //     while (l < r) {
    //         int mid = l + (r - l + 1) / 2;
    //         if (mid * (mid + 1) <= 2 * n)
    //             l = mid;
    //         else
    //             r = mid - 1;
    //     }
    //     return l;
    // }

    // ���������ⷽ��
    int arrangeCoins(int n) { 
        return (int)(-1 + sqrt(1 + 8 * (long)n)) / 2; 
    }
};