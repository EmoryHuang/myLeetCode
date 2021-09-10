/*
 * @Descroption: LeetCode 886. ���ܵĶ��ַ�
 * @Author: EmoryHuang
 * @Date: 2021-08-26 17:07:20
 * @Method:
 * ����һ�����鼯
 * ����ÿ���ˣ������������ǲ�ϲ�����ˣ�����ϲ������������ͬһ�飬������
 * ͬʱ����ͬһ���˲�ϲ���ı�����ͬһ�飬���򲻻��Ƕ���ͼ
 *
 * ��������Ⱦɫ��
 * ����ÿ����ͨ�Ĳ��֣���������ɫ����������ɫ���Ϳ��Լ�����Ƿ��Ƕ��ֵġ�
 * ����һ���Ϳ�ɰ�ɫ��Ȼ�����������ھӶ�Ϳ�ɺ�ɫ��
 * Ȼ�����е��ھӵ��ھӶ�Ϳ�ɰ�ɫ���Դ����ơ�
 * ��������ͻ��˵�����Ƕ���ͼ��
 */

class Solution {
   public:
    // ����һ�����鼯
    // vector<int> parent;
    // int find(int x) {
    //     if (x != parent[x]) parent[x] = find(parent[x]);
    //     return parent[x];
    // }
    // void merge(int x, int y) { parent[find(x)] = find(y); }
    // bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    //     // ��ʼ�����鼯
    //     for (int i = 0; i <= n; i++) parent.push_back(i);
    //     // �����ڽӱ�
    //     unordered_map<int, vector<int>> mp;
    //     for (auto d : dislikes) {
    //         mp[d[0]].push_back(d[1]);
    //         mp[d[1]].push_back(d[0]);
    //     }
    //     for (int i = 1; i <= n; i++)
    //         for (auto j : mp[i]) {
    //             // ����ϲ������������ͬһ�飬������
    //             if (find(i) == find(j)) return false;
    //             // ��ͬһ���˲�ϲ���ı�����ͬһ�飬���򲻻��Ƕ���ͼ
    //             merge(mp[i][0], j);
    //         }
    //     return true;
    // }

    // ��������Ⱦɫ��
    vector<int> color;
    unordered_map<int, vector<int>> mp;
    bool dfs(int u, int c) {
        // u��ʾ��ǰ�ڵ㣬c��ʾ��ǰ�����ɫ
        color[u] = c;
        // ���� u ���ڽӽڵ�
        for (auto v : mp[u]) {
            // �����ǰ�ڵ�δȾɫ
            if (!color[v]) {
                // �����ڵĵ�Ⱦ���෴����ɫ
                if (!dfs(v, -c)) return false;
            } else if (color[v] == c)
                // ���v�Ѿ���ɫ���Һͽ��u��ɫ��ͻ
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // 0��ʾδȾɫ��1��ʾ��ɫ��-1��ʾ��ɫ
        color.resize(n + 1);
        for (auto d : dislikes) {
            mp[d[0]].push_back(d[1]);
            mp[d[1]].push_back(d[0]);
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            // �����ǰ�ڵ�δȾɫ
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