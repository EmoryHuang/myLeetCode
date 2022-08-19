/*
 * @Descroption: LeetCode 670. 最大交换
 * @Author: EmoryHuang
 * @Date: 2021-11-08 21:06:30
 * @Method:
 * 方法一：暴力
 * 寻找当前字符后面的最大值，若最大值不为当前字符，则进行交换
 *
 * 方法二：排序
 * 对 num 中的数字从大到小的进行排序
 * 然后与原数字一一比较，遇到的第一个不同的值即是需要交换的值
 */

class Solution {
   public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<char> a(s.begin(), s.end());
        vector<char> b = a;
        sort(b.begin(), b.end(), [](char x, char y) { return x > y; });
        int idx = -1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) return num;
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] == b[idx]) {
                swap(a[i], a[idx]);
            }
        }
        string ans(a.begin(), a.end());
        return stoi(ans);
    }
};