/*
 * @Descroption: LeetCode 886. 可能的二分法
 * @Author: EmoryHuang
 * @Date: 2021-08-26 17:07:20
 * @Method:
 * 方法一：并查集
 * 对于每个人，遍历所有他们不喜欢的人，若不喜欢的两个人在同一组，则不满足
 * 同时，被同一个人不喜欢的必须在同一组，否则不会是二分图
 *
 * 方法二：染色法
 * 对于每个连通的部分，用两种颜色对它进行着色，就可以检查它是否是二分的。
 * 将任一结点涂成白色，然后将它的所有邻居都涂成黑色，
 * 然后将所有的邻居的邻居都涂成白色，以此类推。
 * 若产生冲突则说明不是二分图。
 */

class Solution {
   public:
    // 方法一：并查集
    // vector<int> parent;
    // int find(int x) {
    //     if (x != parent[x]) parent[x] = find(parent[x]);
    //     return parent[x];
    // }
    // void merge(int x, int y) { parent[find(x)] = find(y); }
    // bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    //     // 初始化并查集
    //     for (int i = 0; i <= n; i++) parent.push_back(i);
    //     // 建立邻接表
    //     unordered_map<int, vector<int>> mp;
    //     for (auto d : dislikes) {
    //         mp[d[0]].push_back(d[1]);
    //         mp[d[1]].push_back(d[0]);
    //     }
    //     for (int i = 1; i <= n; i++)
    //         for (auto j : mp[i]) {
    //             // 若不喜欢的两个人在同一组，则不满足
    //             if (find(i) == find(j)) return false;
    //             // 被同一个人不喜欢的必须在同一组，否则不会是二分图
    //             merge(mp[i][0], j);
    //         }
    //     return true;
    // }

    // 方法二：染色法
    vector<int> color;
    unordered_map<int, vector<int>> mp;
    bool dfs(int u, int c) {
        // u表示当前节点，c表示当前点的颜色
        color[u] = c;
        // 遍历 u 的邻接节点
        for (auto v : mp[u]) {
            // 如果当前节点未染色
            if (!color[v]) {
                // 将相邻的点染成相反的颜色
                if (!dfs(v, -c)) return false;
            } else if (color[v] == c)
                // 结点v已经着色，且和结点u颜色冲突
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // 0表示未染色，1表示黑色，-1表示白色
        color.resize(n + 1);
        for (auto d : dislikes) {
            mp[d[0]].push_back(d[1]);
            mp[d[1]].push_back(d[0]);
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            // 如果当前节点未染色
            if (!color[i]) {
                if (!dfs(i, 1)) {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
};