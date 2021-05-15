/*
 * @Descroption: LeetCode 1046. 最后一块石头的重量
 * @Author: EmoryHuang
 * @Date: 2021-03-25 10:03:36
 * @解题思路:
 * 将所有石头的重量放入最大堆中。每次依次从队列中取出最重的两块石头 a 和 b，差值放回堆
 */

class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (int s : stones) q.push(s);
        while (q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if (a > b) q.push(a - b);
        }
        return q.empty() ? 0 : q.top();
    }
};