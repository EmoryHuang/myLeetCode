/*
 * @Descroption: LeetCode 825. 适龄的朋友
 * @Author: EmoryHuang
 * @Date: 2021-08-19 15:16:08
 * @Method:
 * 哈希表计数
 * 对于每个年龄，如果满足条件，就将 cntA * cntB 加入 ans
 * 当年龄相同时，记录 cntA * (cntB - 1)
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