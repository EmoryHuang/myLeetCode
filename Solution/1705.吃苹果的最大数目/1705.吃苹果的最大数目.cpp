/*
 * @Descroption: LeetCode 1705. 吃苹果的最大数目
 * @Author: EmoryHuang
 * @Date: 2021-12-24 09:16:57
 * @Method:
 * 模拟 + 优先队列
 * 维护一个小根堆，分别存储每天采摘信息 (days[i] + pickday, apples[i])
 * 每天要吃苹果时，取堆顶元素，直到堆顶的苹果不是腐烂的
 * 吃完后，更新第 pickday 天的苹果数量
 * */

class Solution {
   public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans = 0, i = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        while (heap.size() > 0 || i < apples.size()) {
            bool eat = false;
            // 维护一个小根堆，分别存储每天采摘信息 (days[i] + pickday, apples[i])
            if (i < apples.size() && apples[i] != 0) heap.push({days[i] + i, apples[i]});
            while (heap.size() > 0 && !eat) {
                // 取堆顶元素，直到堆顶的苹果不是腐烂的
                auto [day, apple] = heap.top();
                heap.pop();
                if (i >= day) continue;
                ans++;
                eat = true;
                // 更新第 pick 天的苹果数量
                if (apple - 1 > 0) heap.push({day, apple - 1});
            }
            i++;
        }
        return ans;
    }
};