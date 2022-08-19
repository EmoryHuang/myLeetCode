/*
 * @Descroption: 面试题 16.10. 生存人数
 * @Author: EmoryHuang
 * @Date: 2021-07-18 15:21:43
 * @解题思路:
 * 差分思想
 * 统计每年变化的人数
 */

class Solution {
   public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        vector<int> cnt(101);
        for (int i = 0; i < birth.size(); i++) {
            int x = birth[i] - 1900, y = death[i] - 1900;
            cnt[x]++;
            if (y + 1 <= 100) cnt[y + 1]--;
        }
        int ans = 0, sum = 0, max = -1;
        for (int i = 0; i < 101; i++) {
            sum += cnt[i];
            if (sum > max) {
                max = sum;
                ans = i + 1900;
            }
        }
        return ans;
    }
};