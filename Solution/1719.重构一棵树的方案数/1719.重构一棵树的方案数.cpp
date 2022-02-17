/*
 * @Descroption: LeetCode 1719. �ع�һ�����ķ�����
 * @Author: EmoryHuang
 * @Date: 2022-02-16 10:02:47
 * @Method:
 * adj[x] �洢�ڵ� x ���������Ⱥͺ��
 * ����Ѱ�Ҹ��ڵ㣬���ڵ���������Ⱥͺ������ĿΪ n - 1
 * ����ÿ���ڵ� node���ҵ���ǰ�ڵ�ĸ��ڵ� parent
 * �� parent Ϊ���ڵ㣬����и��ڵ�������ϵ��Ŀ �� ����ڵ�������ϵ��Ŀ
 * parent �����Ⱥͺ���бض������� node �����Ⱥͺ������ parent ����
 * ��������ȫ������˵��������
 * �� parent �� node �����Ⱥͺ����Ŀ��ͬ�����޷�ȷ�����ӹ�ϵ�����ܴ��ڶ��ֹ���
 */

class Solution {
   public:
    int checkWays(vector<vector<int>>& pairs) {
        // adj[x] �洢�ڵ� x ���������Ⱥͺ��
        unordered_map<int, unordered_set<int>> adj;
        for (auto p : pairs) {
            adj[p[0]].insert(p[1]);
            adj[p[1]].insert(p[0]);
        }
        int root = -1;
        for (auto [node, neighb] : adj) {
            // Ѱ�Ҹ��ڵ㣬���ڵ���������Ⱥͺ������ĿΪ n - 1
            if (neighb.size() == adj.size() - 1) {
                root = node;
                break;
            }
        }
        // ���ڵ㲻���ڣ��򷵻� 0
        if (root == -1) return 0;
        int ans = 1;
        for (auto [node, neighb] : adj) {
            if (node == root) continue;
            // �ڵ�ǰ�ڵ� node �����Ⱥͺ����Ѱ�ҵ�ǰ�ڵ�ĸ��ڵ�
            // �� parent Ϊ���ڵ㣬����и��ڵ�������ϵ��Ŀ �� ����ڵ�������ϵ��Ŀ
            int cur_degree = neighb.size();
            int parent = -1;
            int parent_degree = INT_MAX;
            for (auto n : neighb) {
                if (cur_degree <= adj[n].size() && adj[n].size() < parent_degree) {
                    parent = n;
                    parent_degree = adj[n].size();
                }
            }
            if (parent == -1) return 0;
            // ȷ�� node ���������Ⱥͺ����ϵ�Ƿ����
            // parent �����Ⱥͺ���бض������� node �����Ⱥͺ������ parent ����
            for (auto n : neighb) {
                if (n == parent) continue;
                // ��������ȫ������˵��������
                if (!adj[parent].count(n)) return 0;
            }
            // �޷�ȷ�����ӹ�ϵ�����ܴ��ڶ��ֹ���
            if (cur_degree == parent_degree) ans = 2;
        }
        return ans;
    }
};