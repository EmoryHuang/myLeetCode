/*
 * @Descroption: LeetCode 1442. 形成两个异或相等数组的三元组数目
 * @Author: EmoryHuang
 * @Date: 2021-05-18 11:32:12
 * @解题思路:
 * 方法一：二重循环
 * 计算异或前缀和 s
 * 遍历i，k
 * 当s[i]==s[k+1]时，区间内的任意一个j，都和i，k组成满足题目的一个三元组
 *
 * 方法二
 * 如果a==b也就是a^b=0。
 * 那么arr[i]^arr[i+1]^……^arr[j]^……arr[k]的结果就是0
 * 只需要从数组arr中找到一些连续的元素，他们的异或结果等于0即可
 * 此时区间为[i,k]，区间内三元组的个数为 k - i
 * 因为区间内的任意一个j，都和i，k组成满足题目的一个三元组
 */

class Solution {
   public:
    //方法一
    // int countTriplets(vector<int>& arr) {
    //     int n = arr.size();
    //     int ans = 0;
    //     vector<int> s(n + 1);
    //     // 异或前缀和 s
    //     for (int i = 0; i < n; i++) s[i + 1] = s[i] ^ arr[i];
    //     for (int i = 0; i < n; i++) {
    //         for (int k = i + 1; k < n; k++) {
    //             if (s[i] == s[k + 1]) ans += k - i;
    //         }
    //     }
    //     return ans;
    // }

    // 方法二
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int sum = 0;
            for (int k = i; k < n; k++) {
                sum ^= arr[k];
                // 异或结果为0，满足条件
                if (sum == 0 && k > i) ans += (k - i);
            }
        }
        return ans;
    }
};