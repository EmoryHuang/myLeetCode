/*
 * @Descroption: LeetCode 9. 回文数
 * @Author: EmoryHuang
 * @Date: 2021-03-19 13:08:36
 * @解题思路: 和整数反转一样，通过求余反转整数，再判断是否为回文数
 * 第一种方法是反转整个数字，第二种方法参考题解反转一半数字，第三种是字符串方法
 */

class Solution {
   public:
    //方法一：反转整个数字
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long res = 0, temp = x;
        while (temp) {  //反转整个数字
            res = res * 10 + temp % 10;
            temp /= 10;
        }
        return x == (int)res;
    }

    //方法二：反转一半数字
    // bool isPalindrome(int x) {
    //     if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    //     int res = 0;
    //     while (x > res) {  //反转一半数字
    //         res = res * 10 + x % 10;
    //         x /= 10;
    //     }
    //     return x == res || x == res / 10;  //偶数个字符则直接相等，奇数个去除中位的数字
    // }

    //方法三：字符串
    // bool isPalindrome(int x) {
    //     string s = to_string(x);
    //     int i = 0, j = s.length() - 1;  //设置两个指针
    //     while (i < j) {
    //         if (s[i] != s[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
};