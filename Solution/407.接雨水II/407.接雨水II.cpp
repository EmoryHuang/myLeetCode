/*
 * @Descroption: LeetCode 407. ����ˮ II
 * @Author: EmoryHuang
 * @Date: 2021-11-03 16:16:50
 * @Method:
 * ���ȶ���
 * ά��һ��С����
 * ȷ����ǰ���ӵ�Ԫ�ض��ڸ����Ŀ���˵������Χ�ĸ��߶��е���Сֵ����ô����ȷ������ˮ�Ĵ�С
 * ���Ƚ���Ե�������ȶ��У����󲻶����ڲ���С��Χ
 * �����Χ�ĸ߶ȴ��ڵ�ǰ�߶ȣ���ô���Թ�ˮ
 */


class Solution {
   public:
    typedef pair<int, pair<int, int>> piii;
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() == 0) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        // ά��һ��С����
        //  ȷ����ǰ���ӵ�Ԫ�ض��ڸ����Ŀ���˵������Χ�ĸ��߶��е���Сֵ
        //  ��ô����ȷ������ˮ�Ĵ�С
        priority_queue<piii, vector<piii>, greater<piii>> heap;
        // vis ����Ƿ����
        vector<vector<int>> vis(m, vector<int>(n));
        int ans = 0;
        // ����Ե�������ȶ���
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    heap.push({heightMap[i][j], {i, j}});
                    vis[i][j] = 1;
                }
            }
        }
        while (!heap.empty()) {
            auto [h, p] = heap.top();
            heap.pop();
            int i = p.first, j = p.second;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                    // �����Χ�ĸ߶ȴ��ڵ�ǰ�߶ȣ���ô���Թ�ˮ
                    if (h > heightMap[x][y]) ans += h - heightMap[x][y];
                    heap.push({max(h, heightMap[x][y]), {x, y}});
                    vis[x][y] = 1;
                }
            }
        }
        return ans;
    }
};