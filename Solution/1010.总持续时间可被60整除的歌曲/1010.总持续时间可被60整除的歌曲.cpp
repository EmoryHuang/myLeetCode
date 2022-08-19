/*
 * @Descroption: LeetCode 1010. 总持续时间可被 60 整除的歌曲
 * @Author: EmoryHuang
 * @Date: 2021-05-21 13:20:59
 * @解题思路:
 * 使用哈希表存储每首歌时间对60取模的数
 * 遍历time，查找哈希表中是否存在两个数和为60
 */

class Solution {
   public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> hash(60);  // 记录 % 60 各个结果的个数
        int ans = 0;
        for (int t : time) {
            t = t % 60;
            ans += hash[(60 - t) % 60];
            hash[t]++;
        }
        return ans;
    }
};