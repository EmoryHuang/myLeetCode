/*
 * @Descroption: ��ָ Offer 58 - I. ��ת����˳��
 * @Author: EmoryHuang
 * @Date: 2021-07-07 19:34:36
 * @����˼·:
 * ��ǰ������������η�ת
 */

class Solution {
   public:
    string reverseWords(string s) {
        int i = 0, n = s.size();
        string ans, tmp;
        while (i < n) {
            tmp = "";
            while (i < n && s[i] == ' ') i++;
            while (i < n && s[i] != ' ') tmp += s[i++];
            if (tmp != "") ans = tmp + " " + ans;
        }
        return ans.substr(0, ans.size() - 1);
    }
};