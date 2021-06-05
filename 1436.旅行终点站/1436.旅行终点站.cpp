/*
 * @Descroption: LeetCode 1436. �����յ�վ
 * @Author: EmoryHuang
 * @Date: 2021-06-05 15:32:00
 * @����˼·:
 * ����㼯����Ѱ���յ㣬û�г�������㼯���еļ����յ�վ
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