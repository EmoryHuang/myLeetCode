/*
 * @Descroption: LeetCode 239. 滑动窗口最大值
 * @Author: EmoryHuang
 * @Date: 2021-07-13 20:40:44
 * @解题思路:
 * 方法一：优先队列
 * 维护一个大根堆，遍历所有数
 * 如果当前最大值不在滑动窗口内，则弹出
 * 然后将堆顶元素加入 ans
 *
 * 方法二：单调队列
 * 使用一个队列存储所有还没有被移除的下标
 * 将新的元素与队尾的元素相比较, 保证队内为递减序列
 * 如果当前最大值不在滑动窗口内，则弹出
 * 然后将队首元素加入 ans
 */

class Solution {
   public:
    // 方法一：优先队列
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     priority_queue<pair<int, int>> q;
    //     vector<int> ans;
    //     for (int i = 0; i < k; i++) {
    //         q.emplace(nums[i], i);
    //     }
    //     ans.push_back(q.top().first);
    //     for (int i = k; i < nums.size(); i++) {
    //         q.emplace(nums[i], i);
    //         // 如果当前最大值不在滑动窗口内，则弹出
    //         while (q.top().second <= i - k) q.pop();
    //         ans.push_back(q.top().first);
    //     }
    //     return ans;
    // }

    // 方法二：单调队列
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            // 保证队内为递减序列
            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        for (int i = k; i < nums.size(); i++) {
            // 保证队内为递减序列
            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            // 如果当前最大值不在滑动窗口内，则弹出
            while (q.front() <= i - k) q.pop_front();
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};