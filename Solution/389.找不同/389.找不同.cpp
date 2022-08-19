/*
 * @Descroption: LeetCode 389. 找不同
 * @Author: EmoryHuang
 * @Date: 2021-05-20 20:10:37
 * @解题思路:
 * 方法一：哈希表
 *
 * 方法二：求和
 * 每个字符的 ASCII 码的值求和
 *
 * 方法三：异或
 * 求字符串中出现奇数次的字符
 */

class Solution {
   public:
    // 方法二：求和
    // char findTheDifference(string s, string t) {
    //     int ans = 0;
    //     for (char ch : s) ans -= ch;
    //     for (char ch : t) ans += ch;
    //     return ans;
    // }

    // 方法三：异或
    char findTheDifference(string s, string t) {
        int ans = 0;
        for (char ch : s) ans ^= ch;
        for (char ch : t) ans ^= ch;
        return ans;
    }
};
