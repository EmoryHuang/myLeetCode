/*
 * @Descroption: LeetCode 517. 超级洗衣机
 * @Author: EmoryHuang
 * @Date: 2021-09-29 09:30:20
 * @Method:
 * 贪心
 * 首先判断是否能均分，得到目标 target
 * 若 num - target < 0 表示需要从两边获取衣服, 否则需要向两边拿出衣服
 * p < 0 说明需要从右边获取衣服, p > 0 说明需要向右边拿出衣服
 * 最大的操作次数就是 max(num - target, abs(p))
 */

class Solution {
   public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        for (auto num : machines) sum += num;
        if (sum % machines.size()) return -1;
        int target = sum / machines.size();
        int ans = 0, p = 0;
        for (auto num : machines) {
            // 若 num - target < 0 表示需要从两边获取衣服, 否则需要向两边拿出衣服
            // p < 0 说明需要从右边获取衣服, p > 0 说明需要向右边拿出衣服
            // 最大的操作次数就是 max(num - target, abs(p))
            p += num - target;
            ans = max({ans, num - target, abs(p)});
        }
        return ans;
    }
};