/*
 * @Descroption: LeetCode 997. �ҵ�С��ķ���
 * @Author: EmoryHuang
 * @Date: 2021-05-13 19:56:36
 * @����˼·:
 * ͳ��ÿ���ڵ����Ⱥͳ��ȣ�����Ϊ `0` ���Ϊ `n-1` �ľ��Ƿ���
 */

class Solution {
   public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> degree(n + 1, vector<int>(2));  // ÿ�����Ķ�
        for (auto t : trust) {
            degree[t[0]][0]++;  // ����
            degree[t[1]][1]++;  // ���
        }
        for (int i = 1; i <= n; i++) {  // ����Ϊ 0 ���Ϊ n-1 �ľ��Ƿ���
            if (degree[i][0] == 0 && degree[i][1] == n - 1) return i;
        }
        return -1;
    }
};