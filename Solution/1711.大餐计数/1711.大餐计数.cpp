/*
 * @Descroption: LeetCode 1711. ��ͼ���
 * @Author: EmoryHuang
 * @Date: 2021-07-07 19:15:40
 * @����˼·:
 * �ù�ϣ���¼�����Լ������ֵĴ���
 * �������п��ܵ�2���ݣ����ñ�����2���ݼ�ȥ��ǰ�����ó���Ӧ����
 */

class Solution {
   public:
    int countPairs(vector<int>& deliciousness) {
        int ans = 0;
        map<int, int> hash;
        for (int num : deliciousness) {
            for (int i = 0; i < 22; i++) {
                if (hash.find((1 << i) - num) != hash.end()) {
                    int cnt = hash.find((1 << i) - num)->second;
                    ans += cnt;
                    ans %= 1000000007;
                }
            }
            hash[num]++;
        }
        return ans;
    }
};