class Solution {
public:
    int countSegments(string s) {
        int ans=0;
        s += " ";
        for(int i =0;i<s.size()-1;i++)
            if(s[i]!=' ' &&s[i+1]==' ')
                ans++;
        return ans;
    }
};