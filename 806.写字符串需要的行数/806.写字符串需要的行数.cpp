class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int row=1;
        int sum = 0;
        for(int i=0;i<s.size();i++){
            if(sum + widths[s[i]-'a'] > 100){
                row++;
                sum = 0;
            }
            sum += widths[s[i]-'a'];
        }
        return {row,sum==100?sum:sum%100};
    }
};