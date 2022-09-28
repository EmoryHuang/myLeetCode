/*
 * @Descroption: LeetCode 788. 旋转数字
 * @Author: EmoryHuang
 * @Date: 2022-09-25 11:13:49
 * @Method:
 * 根据题意，好数中不能有 3,4,7，且至少包含 2,5,6,9 中的一个
 * 遍历[1,n]，判断每个数字是否是好数即可
 */

class Solution {
    public int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            boolean flag = false;
            int num = i;
            while (num != 0) {
                int t = num % 10;
                num /= 10;
                if (t == 2 || t == 5 || t == 6 || t == 9)
                    flag = true;
                else if (t == 3 || t == 4 || t == 7) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans++;
            }
        }
        return ans;
    }
}