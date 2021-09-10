/*
 * @Descroption: LeetCode 825. ���������
 * @Author: EmoryHuang
 * @Date: 2021-08-19 15:16:08
 * @Method:
 * ��ϣ�����
 * ����ÿ�����䣬��������������ͽ� cntA * cntB ���� ans
 * ��������ͬʱ����¼ cntA * (cntB - 1)
 */

class Solution {
   public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> hash(121);
        for (int age : ages) hash[age]++;
        int ans = 0;
        for (int i = 0; i < 121; i++) {
            for (int j = 0; j < 121; j++) {
                if (j <= 0.5 * i + 7) continue;
                if (j > i) continue;
                if (i < 100 && 100 < j) continue;
                ans += hash[i] * hash[j];
                if (i == j) ans -= hash[i];
            }
        }
        return ans;
    }
};