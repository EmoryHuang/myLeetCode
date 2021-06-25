/*
 * @Descroption: LeetCode 752. 打开转盘锁
 * @Author: EmoryHuang
 * @Date: 2021-06-25 14:51:00
 * @解题思路:
 * 创建「两个队列」分别用于两个方向的搜索
 * 创建「两个哈希表」用于「解决相同节点重复搜索」和「记录转换次数」
 * 每次从队列中取值进行扩展时，先判断哪个队列容量较少
 * 如果在搜索过程中「搜索到对方搜索过的节点」，说明找到了最短路径
 */

class Solution {
   public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;  // 不需要转动
        unordered_set<string> dead;
        for (auto deadend : deadends) {
            if (deadend == "0000") return -1;  // deadends 中出现了 0000
            dead.insert(deadend);              // 将 deadends 中的元素压入 set
        }
        // 正向：从起点 s 开始搜索，反向：从结尾 t 开始搜索
        // q1 和 q2 分别代表从正向和反向搜索
        queue<string> q1, q2;
        q1.push("0000");
        q2.push(target);
        // m1 和 m2 分别记录正向和反向出现的状态是经过多少次转换而来
        unordered_map<string, int> m1, m2;
        m1["0000"] = 0;  // 代表转换成 "0000" 需要旋转 0 次
        m2[target] = 0;  // 代表转换成 target 需要旋转 0 次

        // 只有两个队列都不空，才有必要继续往下搜索
        // 如果其中一个队列空了，说明从某个方向搜到底都搜不到该方向的目标节点
        while (!q1.empty() && !q2.empty()) {
            int ans = -1;
            if (q1.size() <= q2.size())  // 优先搜索长度短的
                ans = update(q1, m1, m2, dead);
            else
                ans = update(q2, m2, m1, dead);
            if (ans != -1) return ans;
        }
        return -1;
    }

    int update(queue<string>& q, unordered_map<string, int>& same,
               unordered_map<string, int>& other, unordered_set<string>& dead) {
        string cur = q.front();  // 当前方向队首字符串
        int step = same[cur];    // 转到 cur 需要的次数
        q.pop();
        for (int i = 0; i < 4; i++) {
            // 模拟正向和反向旋转 +1，-1
            for (int j = -1; j <= 1; j++) {
                if (j == 0) continue;
                string t = cur;
                if (t[i] == '9' && j == 1)
                    t[i] -= 10;
                else if (t[i] == '0' && j == -1)
                    t[i] += 10;
                t[i] += j;
                if (same.count(t) || dead.count(t)) continue;  // 如果出现过或者是dead则继续
                if (other.count(t))  // 如果在「另一方向」找到过，说明找到了最短路，否则加入队列
                    return 1 + step + other[t];
                else {
                    q.push(t);
                    same[t] = step + 1;
                }
            }
        }
        return -1;
    }
};