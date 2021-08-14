/*
 * @Descroption: LeetCode 1583. ͳ�Ʋ����ĵ�����
 * @Author: EmoryHuang
 * @Date: 2021-08-14 13:55:38
 * @Method:
 * ģ��
 * ��� y �� x ���׽��̶ȵ��±겢��¼������
 * ����ÿ���� x, ��� x ����� y �Լ� y �� x �����̶ܳȴ��� index
 * ����ÿ�����ܵ� u��0 ~ index - 1���ҵ������� u ��Ե����� v
 * ��� u �� x ���׽��̶�ʤ�� u �� v���� x ������
 */

class Solution {
   public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> order(n, vector<int>(n));
        vector<int> pair(n);
        // ��� y �� x ���׽��̶ȵ��±�
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - 1; j++) order[i][preferences[i][j]] = j;
        // ��¼������
        for (auto p : pairs) {
            pair[p[0]] = p[1];
            pair[p[1]] = p[0];
        }
        int ans = 0;
        for (int x = 0; x < n; x++) {
            // ��� x ����� y �Լ� y �� x �����̶ܳȴ���
            int y = pair[x];
            int index = order[x][y];
            for (int i = 0; i < index; i++) {
                // ����ÿ�����ܵ� u���ҵ������� u ��Ե����� v
                int u = preferences[x][i];
                int v = pair[u];
                // ��� u �� x ���׽��̶�ʤ�� u �� v
                if (order[u][x] < order[u][v]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};