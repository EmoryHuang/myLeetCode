/*
 * @Descroption: LeetCode 13. 罗马数字转整数
 * @Author: EmoryHuang
 * @Date: 2021-03-20 13:16:36
 * @解题思路: 贪心思想，从最大的一路减下来，匹配对应的字符即可，与整数转罗马数字类似
 * 注意将那些特殊情况`CM`,`CD`,`XC`,`XL`,`IX`,`IV`一起考虑为特殊值
 * 注意检索顺序，将有前置的放在前面
 */

class Solution {
   public:
    int romanToInt(string s) {
        int nums[] = {900, 1000, 400, 500, 90, 100, 40, 50, 9, 10, 4, 5, 1};
        // 需要将有前置的放在前面，否则会被替换
        string strs[] = {"CM", "M", "CD", "D", "XC", "C", "XL", "L", "IX", "X", "IV", "V", "I"};
        int ans = 0;
        for (int i = 0; i < 13; i++) {
            while (s.find(strs[i]) != string::npos) {             //如果有这个字符
                s.replace(s.find(strs[i]), strs[i].size(), " ");  //将其替换为" "
                ans += nums[i];
            }
        }
        return ans;
    }
};