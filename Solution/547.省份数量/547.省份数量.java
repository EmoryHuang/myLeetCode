/*
 * @Descroption: LeetCode 547. 省份数量
 * @Author: EmoryHuang
 * @Date: 2023-07-17 10:18:33
 * @Method:
 * 并查集
 */

import java.util.*;

class Solution {
    int[] parent;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        parent[find(x)] = find(y);
    }

    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    merge(i, j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += i == parent[i] ? 1 : 0;
        }
        return ans;
    }
}