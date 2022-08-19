/*
 * @Descroption: LeetCode 947. �Ƴ�����ͬ�л�ͬ��ʯͷ
 * @Author: EmoryHuang
 * @Date: 2021-06-27 14:58:00
 * @����˼·:
 * ���鼯
 * ���������㣬��ͬһ�л���ͬһ����ϲ�
 * ��������ͨͼ��������ô�����Ƴ���ʯ�ӵ��������Ϊ n - ��ͨͼ����
 */

class Solution {
   public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) parent[x] = find(parent, parent[x]);
        return parent[x];
    }
    void myunion(vector<int>& parent, int x, int y) { parent[find(parent, x)] = find(parent, y); }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;  // ��ʼ�����鼯
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    // ��ͬһ�л���ͬһ����ϲ�
                    myunion(parent, i, j);
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i) ans++;  // ��ͨͼ����
        return n - ans;
    }
};