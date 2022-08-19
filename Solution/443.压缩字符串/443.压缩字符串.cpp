/*
 * @Descroption: LeetCode 443. 压缩字符串
 * @Author: EmoryHuang
 * @Date: 2021-08-21 17:47:22
 * @Method:
 * 双指针
 * 寻找相同的字符，移动右指针，记录字符和数量，并以此覆盖字符串
 * 使用 tail 来标识新串
 */

class Solution {
   public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int l = 0, r = 0, tail = 0;
        while (r < n) {
            while (r < n && chars[r] == chars[l]) r++;
            int cnt = r - l;
            chars[tail++] = chars[l];
            if (cnt > 1) {
                string cnt_str = to_string(cnt);
                for (auto c : cnt_str) chars[tail++] = c;
            }
            l = r;
        }
        return tail;
    }
};