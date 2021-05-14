/*
 * @Descroption:LC 12. 整数转罗马数字
 * @Author: EmoryHuang
 * @Date: 2021-05-08 15:48:05
 * @解题思路:贪心思想，从最大的一路减下来，匹配对应的字符即可
 *          注意将那些特殊情况`CM`,`CD`,`XC`,`XL`,`IX`,`IV`一起考虑为特殊值
 */

class Solution {
   public:
    string intToRoman(int num) {
        int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string strs[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans;
        for (int i = 0; i < 13; i++) {
            while (num >= nums[i]) {
                num -= nums[i];
                ans += strs[i];
            }
        }
        return ans;
    }
};