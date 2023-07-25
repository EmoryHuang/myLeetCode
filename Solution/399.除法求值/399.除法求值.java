/*
 * @Descroption: LeetCode 1466. 重新规划路线
 * @Author: EmoryHuang
 * @Date: 2023-07-18 09:55:20
 * @Method:
 * 给定图中的一些点（变量），以及某些边的权值（两个变量的比值），
 * 试对任意两点（两个变量）求出其路径长（两个变量的比值）
 * Floyd 算法
 */

import java.util.*;

class Pair {
    int index;
    double value;

    public Pair(int index, double value) {
        this.index = index;
        this.value = value;
    }
}

class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        int nvars = 0;
        Map<String, Integer> variable = new HashMap<>();
        for (List<String> eq : equations) {
            if (!variable.containsKey(eq.get(0))) {
                variable.put(eq.get(0), nvars++);
            }
            if (!variable.containsKey(eq.get(1))) {
                variable.put(eq.get(1), nvars++);
            }
        }
        List<Pair>[] edges = new List[nvars];
        for (int i = 0; i < nvars; i++) {
            edges[i] = new ArrayList<>();
        }
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            int va = variable.get(equations.get(i).get(0));
            int vb = variable.get(equations.get(i).get(1));
            edges[va].add(new Pair(vb, values[i]));
            edges[vb].add(new Pair(va, 1.0 / values[i]));
        }

        int m = queries.size();
        double[] ans = new double[m];
        for (int i = 0; i < m; i++) {
            List<String> q = queries.get(i);
            double res = -1.0;
            if (variable.containsKey(q.get(0)) && variable.containsKey(q.get(1))) {
                int u = variable.get(q.get(0)), v = variable.get(q.get(1));
                if (u == v) {
                    res = 1.0;
                } else {
                    Queue<Integer> queue = new LinkedList<>();
                    queue.offer(u);
                    double[] ratios = new double[nvars];
                    Arrays.fill(ratios, -1.0);
                    ratios[u] = 1.0;

                    while (!queue.isEmpty() && ratios[v] < 0) {
                        int x = queue.poll();
                        for (Pair pair : edges[x]) {
                            int y = pair.index;
                            double val = pair.value;
                            if (ratios[y] < 0) {
                                ratios[y] = ratios[x] * val;
                                queue.offer(y);
                            }
                        }
                    }
                    res = ratios[v];
                }
            }
            ans[i] = res;
        }
        return ans;
    }

    // Floyd 算法 精度问题
    // public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
    //     int nvars = 0;
    //     Map<String, Integer> variable = new HashMap<>();
    //     for (List<String> eq : equations) {
    //         if (!variable.containsKey(eq.get(0))) {
    //             variable.put(eq.get(0), nvars++);
    //         }
    //         if (!variable.containsKey(eq.get(1))) {
    //             variable.put(eq.get(1), nvars++);
    //         }
    //     }
    //     double[][] graph = new double[nvars][nvars];
    //     for (int i = 0; i < nvars; i++) {
    //         Arrays.fill(graph[i], -1.0);
    //     }
    //     int n = equations.size();
    //     for (int i = 0; i < n; i++) {
    //         int va = variable.get(equations.get(i).get(0));
    //         int vb = variable.get(equations.get(i).get(1));
    //         graph[va][vb] = values[i];
    //         graph[vb][va] = 1.0 / values[i];
    //     }

    //     for (int k = 0; k < nvars; k++) {
    //         for (int i = 0; i < nvars; i++) {
    //             for (int j = 0; j < nvars; j++) {
    //                 if (graph[i][k] > 0 && graph[k][j] > 0) {
    //                     graph[i][j] = graph[i][k] * graph[k][j];
    //                 }
    //             }
    //         }
    //     }

    //     int m = queries.size();
    //     double[] ans = new double[m];
    //     for (int i = 0; i < m; i++) {
    //         List<String> q = queries.get(i);
    //         double res = -1.0;
    //         if (variable.containsKey(q.get(0)) && variable.containsKey(q.get(1))) {
    //             int u = variable.get(q.get(0)), v = variable.get(q.get(1));
    //             if (graph[u][v] > 0) {
    //                 res = graph[u][v];
    //             }
    //         }
    //         ans[i] = res;
    //     }
    //     return ans;
    // }
}