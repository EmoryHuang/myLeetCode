/*
 * @Descroption: LeetCode 13. ��������ת����
 * @Author: EmoryHuang
 * @Date: 2021-03-20 13:16:36
 * @����˼·: ̰��˼�룬������һ·��������ƥ���Ӧ���ַ����ɣ�������ת������������
 * ע�⽫��Щ�������`CM`,`CD`,`XC`,`XL`,`IX`,`IV`һ����Ϊ����ֵ
 * ע�����˳�򣬽���ǰ�õķ���ǰ��
 */

class Solution {
   public:
    int romanToInt(string s) {
        int nums[] = {900, 1000, 400, 500, 90, 100, 40, 50, 9, 10, 4, 5, 1};
        // ��Ҫ����ǰ�õķ���ǰ�棬����ᱻ�滻
        string strs[] = {"CM", "M", "CD", "D", "XC", "C", "XL", "L", "IX", "X", "IV", "V", "I"};
        int ans = 0;
        for (int i = 0; i < 13; i++) {
            while (s.find(strs[i]) != string::npos) {             //���������ַ�
                s.replace(s.find(strs[i]), strs[i].size(), " ");  //�����滻Ϊ" "
                ans += nums[i];
            }
        }
        return ans;
    }
};