/*
 * @Descroption: LeetCode 1823. 找出游戏的获胜者
 * @Author: EmoryHuang
 * @Date: 2022-05-04 11:17:24
 * @Method:
 * 方法一: 队列模拟
 * 在队列中放置 1 到 n 的玩家
 * 每一轮游戏中，将队首元素取出并将该元素在队尾处重新加入队列，重复该操作 k - 1 次
 * 第 k 次即为失败者，直达队列中只剩下一个玩家，即获胜者
 *
 * 方法二: 数学 + 模拟
 * 每次往同一方向，以固定步长 k 进行消数
 * 由于下一次操作的发起点为消除位置的下一个点
 * 同时问题规模会从 n 变为 n - 1
 * 因此有 f(n, k) = (f(n - 1, k) + k) % n
 */

class Solution {
   public:
    // 方法一: 队列模拟
    // int findTheWinner(int n, int k) {
    //     deque<int> q;
    //     for (int i = 1; i <= n; i++) q.push_back(i);
    //     while (q.size() > 1) {
    //         for (int i = 0; i < k - 1; i++) {
    //             q.push_back(q.front());
    //             q.pop_front();
    //         }
    //         q.pop_front();
    //     }
    //     return q.front();
    // }

    // 方法二: 数学 + 模拟
    int findTheWinner(int n, int k) {
        int ans = 0;
        for (int i = 2; i <= n; i++) ans = (ans + k) % i;
        return ans + 1;
    }
};