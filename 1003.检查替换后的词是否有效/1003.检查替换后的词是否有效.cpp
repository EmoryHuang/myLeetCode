class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (auto ch : s) {
            if (ch == 'a' || ch == 'b'){
                st.push(ch);
            } else if (ch == 'c') {
                if(st.empty()) return false;
                if(st.top() == 'b') st.pop();
                else return false;
                if(st.empty()) return false;
                if(st.top() == 'a') st.pop();
                else return false;

            }
        }
        return st.empty();
    }
};