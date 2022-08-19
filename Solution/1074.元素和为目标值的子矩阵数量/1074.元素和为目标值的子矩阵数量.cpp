/*
 * @Descroption: LeetCode 1074. 元素和为目标值的子矩阵数量
 * @Author: EmoryHuang
 * @Date: 2021-05-29 13:21:56
 * @解题思路:
 * 首先需要计算二维前缀和
 * 搜索所有子矩阵需要枚举「矩形左上角」和「矩形右下角」（超时）
 *
 * 通过哈希表优化
 * 枚举上，下，右边
 * 把「子矩阵右边界」到「原矩阵左边界」的矩阵和 cur 存入哈希表
 * 我们希望找到矩阵和为 target 的子矩阵
 * 这等价于从「哈希表」中找到一个 x，使得 cur - x = target
 */

class Solution {
   public:
    // 朴素二维前缀和（超时）
    // int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     vector<vector<int>> arr(m + 1, vector<int>(n + 1));
    //     for (int i = 1; i <= m; i++)
    //         for (int j = 1; j <= n; j++)
    //             arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + matrix[i - 1][j - 1];
    //     int ans = 0;
    //     for (int i = 1; i <= m; i++) {
    //         for (int j = 1; j <= n; j++) {
    //             for (int p = 1; p <= i; p++) {
    //                 for (int q = 1; q <= j; q++) {
    //                     int sum = arr[i][j] - arr[i][q - 1] - arr[p - 1][j] + arr[p - 1][q - 1];
    //                     if (sum == target) ans++;
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // 优化
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> arr(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + matrix[i - 1][j - 1];
        int ans = 0;
        for (int top = 1; top <= m; top++) {        // 遍历上边界
            for (int bot = top; bot <= m; bot++) {  // 遍历下边界
                int cur = 0;                        // 面积
                map<int, int> mp;                   // map中为{面积：数量}
                for (int r = 1; r <= n; r++) {      // 遍历右边界
                    // 三个边界加上左边缘所围成矩形的面积
                    cur = arr[bot][r] - arr[top - 1][r];
                    if (cur == target) ans++;
                    // 若有面积为 cur - target 的矩形
                    if (mp.count(cur - target)) ans += mp[cur - target];
                    mp[cur]++;
                }
            }
        }
        return ans;
    }
};