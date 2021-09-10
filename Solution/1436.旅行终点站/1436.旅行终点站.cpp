/*
 * @Descroption: LeetCode 1436. 旅行终点站
 * @Author: EmoryHuang
 * @Date: 2021-06-05 15:32:00
 * @解题思路:
 * 在起点集合中寻找终点，没有出现在起点集合中的即是终点站
 */

class Solution {
   public:
    string destCity(vector<vector<string>>& paths) {
        set<string> s;
        for (auto path : paths) s.insert(path[0]);
        for (auto path : paths)
            if (s.count(path[1]) == 0) return path[1];
        return "";
    }
};