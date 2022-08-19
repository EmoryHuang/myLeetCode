/*
 * @Descroption: LeetCode 1217. �����
 * @Author: EmoryHuang
 * @Date: 2021-09-11 20:27:09
 * @Method:
 * �����ƶ�������λ�������ģ�ż���ƶ���ż��λ��������
 * ��ôֻ��Ҫͳ������ż����������Ȼ����ѡ���������ٵ�һ��
 */

class Solution {
   public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for (int num : position) {
            if (num % 2 == 0)
                even++;
            else
                odd++;
        }
        return min(odd, even);
    }
};