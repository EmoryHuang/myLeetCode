class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string s[3]={"qwertyuiop","asdfghjkl","zxcvbnm"};
        for(auto word : words){
            int count[3]={0};
            for(auto c : word){
                c = tolower(c);
                for(int i=0;i<3;i++)
                    if(s[i].find(c)!=string::npos) count[i]++;
            }
            int len = word.size();
            if(count[0]==len || count[1]==len || count[2]==len)
                ans.push_back(word);
        }
        return ans;
    }
};