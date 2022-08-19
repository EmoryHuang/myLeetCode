/*
 * @Descroption: LeetCode 554. 砖墙
 * @Author: EmoryHuang
 * @Date: 2021-05-02 17:08:36
 * @解题思路:
 * 遍历砖墙的每一行，对于当前行，从左到右地扫描每一块砖，使用一个哈希表记录当前砖的右侧边缘到砖墙的位置
 * 最后遍历哈希表，找到出现次数最多的砖块边缘，这就是垂线经过的砖块边缘，用砖墙的高度减去该最大值即为答案
 */

class Solution {
   public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> mp;  // map存储每块砖右边缘位置的数量
        int ans = 0;
        for (auto sub : wall) {
            int sum = 0;
            for (int i = 0; i < sub.size() - 1; i++) {
                sum += sub[i];
                mp[sum]++;
            }
        }
        for (auto a : mp) ans = max(ans, a.second);  //穿过最多右边缘
        return wall.size() - ans;
    }
};