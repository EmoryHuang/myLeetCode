/*
 * @Descroption: LeetCode 841. Կ�׺ͷ���
 * @Author: EmoryHuang
 * @Date: 2021-07-28 17:01:59
 * @Method:
 * dfs��bfs
 * ʹ��һ���б��¼�Ѿ����ʵķ��䣬ʹ�ö��м�¼��ǰ���Դ򿪵ķ����
 * ����ǰ����δ���ʣ�����Ϊ���ʣ��������е�Ҫ�Ǽ������
 */

class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        for (auto key : rooms[0]) q.push(key);
        set<int> ans;
        ans.insert(0);
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            if (ans.count(num) == 0) {
                ans.insert(num);
                for (int key : rooms[num]) q.push(key);
            }
        }
        return ans.size() == n;
    }
};