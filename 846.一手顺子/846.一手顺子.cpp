/*
 * @Descroption: LeetCode 1296. ��������Ϊ�������ֵļ���
 * @Author: EmoryHuang
 * @Date: 2021-07-15 19:55:18
 * @����˼·:
 * �ù�ϣ���¼����Ԫ�ص�����
 * ��������Ԫ�ؽ��б���������ÿ��Ԫ�� num
 * �� num + i �ĸ���Ϊ0���򷵻� false
 */

class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        map<int, int> mp;
        for (auto num : hand) mp[num]++;
        for (auto num : hand) {
            if (mp[num] == 0) continue;
            for (int i = 0; i < groupSize; i++) {
                if (mp.count(num + i) == 0) return false;
                mp[num + i]--;
            }
        }
        return true;
    }
};