/*
 * @Descroption: LeetCode 869. 重新排序得到 2 的幂
 * @Author: EmoryHuang
 * @Date: 2021-10-28 09:05:18
 * @Method:
 * 打表枚举出 1e9 内所有 2 的幂
 * 统计 n 中各个数字的个数
 * 然后查找所有 2 的幂中是否存在一个数，它各个数字的个数与 n 相同
 */

class Solution {
   public:
    bool reorderedPowerOf2(int n) {
        vector<int> power, cnt(10);
        for (int i = 1; i < 1e9; i *= 2) power.push_back(i);
        while (n) {
            cnt[n % 10]++;
            n /= 10;
        }
        for (int num : power) {
            bool flag = true;
            vector<int> cur(10);
            while (num) {
                cur[num % 10]++;
                num /= 10;
            }
            for (int i = 0; i < 10; i++)
                if (cur[i] != cnt[i]) {
                    flag = false;
                    break;
                }
            if (flag) return true;
        }
        return false;
    }
};