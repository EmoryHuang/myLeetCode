class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> st;
        for(int i=0;i<sentence.size();i++)
            st.insert(sentence[i]);
        return st.size()==26 ? true: false;
    }
};