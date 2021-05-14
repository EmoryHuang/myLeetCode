/*
 * @Descroption:LC 12. ����ת��������
 * @Author: EmoryHuang
 * @Date: 2021-05-08 15:48:05
 * @����˼·:̰��˼�룬������һ·��������ƥ���Ӧ���ַ�����
 *          ע�⽫��Щ�������`CM`,`CD`,`XC`,`XL`,`IX`,`IV`һ����Ϊ����ֵ
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