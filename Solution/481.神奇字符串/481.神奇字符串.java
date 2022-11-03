/*
 * @Descroption: LeetCode 481. 神奇字符串
 * @Author: EmoryHuang
 * @Date: 2022-10-31 09:33:25
 * @Method:
 * 双指针
 * 指针 i 指向现在需要构造的对应的组的大小，指针 j 指向现在需要构造的对应组的位置
 * 模拟神奇字符串并记录 1 的个数
 */

class Solution {
    public int magicalString(int n) {
        if (n < 4)
            return 1;
        char[] s = new char[n];
        s[0] = '1';
        s[1] = '2';
        s[2] = '2';
        int ans = 1, i = 2, j = 3;
        while (j < n) {
            int size = s[i++] - '0';
            int num = 3 - (s[j - 1] - '0');
            while (size > 0 && j < n) {
                s[j++] = (char) (num + '0');
                ans += num == 1 ? 1 : 0;
                size--;
            }
        }
        return ans;
    }
}