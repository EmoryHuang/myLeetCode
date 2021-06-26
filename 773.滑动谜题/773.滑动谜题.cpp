/*
 * @Descroption: LeetCode 773. ��������
 * @Author: EmoryHuang
 * @Date: 2021-06-26 14:00:00
 * @����˼·:
 * BFS
 * �� board �����ַ�����������Ҫ�õ��� target = "123450"
 * �ڵ�ǰ״̬ cur ���ҳ� 0 ���ڵ�λ�� x������ÿһ���� x ���ڵ�λ�� y��
 * ���ǽ� cur[x] �� cur[y] ���н������õ���һ���µ�״̬ next
 * ���������
 */

class Solution {
   public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        string target = "123450", start;  // Ŀ��״̬
        // �õ���ʼ�ַ���
        for (auto row : board)
            for (auto s : row) start += s + '0';
        if (start == target) return 0;
        queue<pair<string, int>> q;
        set<string> vis;
        q.push({start, 0});  // ��¼����ǰ״̬��Ҫ step ��
        vis.insert(start);   // ��¼��ǰ�ַ����Ƿ����
        while (!q.empty()) {
            auto [cur, step] = q.front();
            q.pop();
            if (cur == target) return step;  // �ﵽĿ��״̬
            int x = cur.find('0');           // �ҵ� 0 ��λ�� x
            for (auto y : neighbors[x]) {
                string next = cur;
                swap(next[x], next[y]);  //����
                if (!vis.count(next)) {
                    vis.insert(next);
                    q.push({next, step + 1});
                }
            }
        }
        return -1;
    }
};