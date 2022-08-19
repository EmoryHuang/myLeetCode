/*
 * @Descroption: LeetCode 904. 水果成篮
 * @Author: EmoryHuang
 * @Date: 2021-11-04 20:31:50
 * @Method:
 * 滑动窗口
 * 将题目的问题转化一下：求仅包含两个元素的最长子序列
 * 使用哈希表记录篮子中的元素
 */

class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, l = 0;
        unordered_map<int, int> cnt;
        for (int r = 0; r < fruits.size(); ++r) {
            cnt[fruits[r]]++;
            if (cnt.size() >= 3) {
                // 滑动窗口左移
                cnt[fruits[l]]--;
                // 如果左端点的值变为 0 则删除
                if (cnt[fruits[l]] == 0) cnt.erase(fruits[l]);
                l++;
            }
            // 更新最大长度
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};