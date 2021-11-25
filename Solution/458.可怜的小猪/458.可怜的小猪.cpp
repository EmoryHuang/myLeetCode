/*
 * @Descroption: LeetCode 458. ������С��
 * @Author: EmoryHuang
 * @Date: 2021-11-25 08:39:30
 * @Method:
 * t = minutesToTest / minutesToDie �����һֻ����Բ��Ե�������
 * ��ôһֻ����Լ���� t + 1 ��Ͱ��ˮ
 * ͬ���ģ����� n ֻ��ֻ��Ҫ n ���� (t + 1)**n >= buckets
 * �� n = log(buckets, (t + 1))
 */


class Solution {
   public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t = minutesToTest / minutesToDie;
        return ceil(log(buckets) / log(t + 1));
    }
};