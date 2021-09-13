/*
 * @Descroption: LeetCode 447. 回旋镖的数量
 * @Author: EmoryHuang
 * @Date: 2021-09-13 11:07:15
 * @Method:
 * 暴力 + 哈希表
 * 遍历当前点到其他点的距离，并用哈希表记录距离出现次数
 * 从每个距离出现次数 n 中选出两个数，作为另外两个点
 * 即 A(n, 2) = n * (n - 1)
 */

class Solution {
   public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for (auto a : points) {
            unordered_map<int, int> hash;
            // 遍历当前点到其他点的距离
            for (auto b : points) {
                int dis = (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
                hash[dis]++;
            }
            unordered_map<int, int>::iterator it;
            // 从每个距离出现次数 n 中选出两个数
            // 即 A(n, 2) = n * (n - 1)
            for (it = hash.begin(); it != hash.end(); it++) {
                ans += it->second * (it->second - 1);
            }
        }
        return ans;
    }
};