/*
 * @Descroption: LeetCode 804. 唯一摩尔斯密码词
 * @Author: EmoryHuang
 * @Date: 2021-07-26 14:45:48
 * @Method:
 * dfs回溯
 * 使用set记录不同摩尔斯密码词
 */

class Solution {
   public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> ls = {".-", "-...", "-.-.", "-..",  ".",   "..-.", "--.", "....", "..",   ".---", "-.-",  ".-..", "--",
                             "-.", "---",  ".--.", "--.-", ".-.", "...",  "-",   "..-",  "...-", ".--",  "-..-", "-.--", "--.."};
        set<string> st;
        for (auto word : words) {
            string morstr = "";
            for (auto c : word) morstr += ls[c - 'a'];
            st.insert(morstr);
        }
        return st.size();
    }
};