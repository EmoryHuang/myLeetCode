/*
 * @Descroption: LeetCode 378. 有序矩阵中第 K 小的元素
 * @Author: EmoryHuang
 * @Date: 2021-04-23 15:52:36
 * @解题思路:
 * 利用大根堆的性质，将元素放入大根堆，若大根堆的元素个数大于 k，则弹出，最后取堆顶元素
 */

class Solution {
   public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;  // 大根堆
        for (auto row : matrix) {
            for (auto num : row) {
                q.push(num);
                if (q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};