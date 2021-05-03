class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        for(int i=0;i<s.size();i++)
            if(s[i]!='-') ans += toupper(s[i]);
        for(int i= ans.size()-k;i>0;i-=k)
            ans.insert(i,"-");
        return ans;
    }
};