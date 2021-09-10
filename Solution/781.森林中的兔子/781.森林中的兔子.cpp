/*
 * @Descroption: LeetCode 781. 森林中的兔子
 * @Author: EmoryHuang
 * @Date: 2021-04-04 19:36:36
 * @解题思路:
 * 某种颜色的兔子 `m` 只，它们回答的答案数值为 `k` ，则有 `m = k + 1`
 * 通过模拟，先对 `answers` 进行排序，然后遍历，对当前元素 `k` 后面的 `k` 个 `k` 值进行忽略
 */

class Solution {
   public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(), answers.end());
        int len = answers.size();
        int ans = 0;
        for (int i = 0; i < len; i++) {
            ans += answers[i] + 1;
            int k = answers[i];
            // 忽略当前元素 k 后面的 k 个 k 值
            while (k-- && i + 1 < len && answers[i] == answers[i + 1]) i++;
        }
        return ans;
    }
};