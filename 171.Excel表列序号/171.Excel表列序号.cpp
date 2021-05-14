class Solution {
public:
    int titleToNumber(string columnTitle) {
        int len=columnTitle.size();
        int ans=0;
        for(int i=0;i<len;i++){
            ans = ans*26+(columnTitle[i]-'A'+1);
        }
        return ans;
    }
};