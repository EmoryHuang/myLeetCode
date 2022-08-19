/*
 * @Descroption: LeetCode 1010. �ܳ���ʱ��ɱ� 60 �����ĸ���
 * @Author: EmoryHuang
 * @Date: 2021-05-21 13:20:59
 * @����˼·:
 * ʹ�ù�ϣ��洢ÿ�׸�ʱ���60ȡģ����
 * ����time�����ҹ�ϣ�����Ƿ������������Ϊ60
 */

class Solution {
   public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> hash(60);  // ��¼ % 60 ��������ĸ���
        int ans = 0;
        for (int t : time) {
            t = t % 60;
            ans += hash[(60 - t) % 60];
            hash[t]++;
        }
        return ans;
    }
};