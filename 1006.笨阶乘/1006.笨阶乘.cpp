/*
 * @Descroption: LeetCode 1006. ���׳�
 * @Author: EmoryHuang
 * @Date: 2021-04-01 18:17:36
 * @����˼·:
 * ģ��ķ�������ÿ 4 λ�ۼ�
 *
 * ��ѧ������֤�����Բο�
 * [�ٷ����](https://leetcode-cn.com/problems/clumsy-factorial/solution/ben-jie-cheng-by-leetcode-solution-deh2/)
 */

class Solution {
   public:
    // ����һ��ģ��
    // int clumsy(int N) {
    //     if (N <= 2) return N;
    //     if (N == 3) return 6;
    //     int sum = N * (N - 1) / (N - 2) + N - 3;
    //     N -= 4;
    //     while (N >= 4) {
    //         sum += -N * (N - 1) / (N - 2) + N - 3;  //ÿ4λ�ۼ�
    //         N -= 4;
    //     }
    //     return sum - clumsy(N);  //���ϲ���4λ�Ĳ���
    // }

    // ����������ѧ
    int clumsy(int N) {
        if (N == 1) {
            return 1;
        } else if (N == 2) {
            return 2;
        } else if (N == 3) {
            return 6;
        } else if (N == 4) {
            return 7;
        }
        if (N % 4 == 0) {
            return N + 1;
        } else if (N % 4 <= 2) {
            return N + 2;
        } else {
            return N - 1;
        }
    }
};