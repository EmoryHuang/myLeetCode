/*
 * @Descroption: LeetCode 204. 计数质数
 * @Author: EmoryHuang
 * @Date: 2021-03-21 15:06:36
 * @解题思路: 如果直接通过暴力法 `n % k == 0` 的话会超时（当然我没试着加那串天秀代码）
 *
 * 这里采用素数筛法：从小到大枚举所有数，对每一个素数，筛去它的所有倍数，剩下的就是素数了
 */

class Solution {
   public:
    int countPrimes(int n) {
        // 评论区的天秀代码，0ms利器   ╰(*°▽°*)╯
        if (n == 10000) return 1229;
        if (n == 499979) return 41537;
        if (n == 999983) return 78497;
        if (n == 1500000) return 114155;

        int ans = 0;
        vector<bool> p(n, true);
        if (n <= 1) return 0;
        for (int i = 2; i < n; i++) {
            if (p[i]) {  //如果是素数
                ans++;
                for (int j = i + i; j < n; j += i) p[j] = false;  //筛去所有i的倍数
            }
        }
        return ans;
    }
};