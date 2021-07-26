/*
 * @Descroption: LeetCode 804. ΨһĦ��˹�����
 * @Author: EmoryHuang
 * @Date: 2021-07-26 14:45:48
 * @Method:
 * dfs����
 * ʹ��set��¼��ͬĦ��˹�����
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