/*
 * @Descroption: LeetCode 1296. 划分数组为连续数字的集合
 * @Author: EmoryHuang
 * @Date: 2021-07-15 19:55:18
 * @解题思路:
 * 用哈希表记录各个元素的数量
 * 对排序后的元素进行遍历，对于每个元素 num
 * 若 num + i 的个数为0，则返回 false
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