/*
 * @Descroption: LeetCode 1711. 大餐计数
 * @Author: EmoryHuang
 * @Date: 2021-07-07 19:15:40
 * @解题思路:
 * 用哈希表记录加数以及它出现的次数
 * 遍历所有可能的2的幂，利用遍历的2的幂减去当前数，得出对应补数
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