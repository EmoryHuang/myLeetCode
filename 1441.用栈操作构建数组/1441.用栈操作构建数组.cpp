class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int count=1;
        for(int i=0;i<target.size();count++){
            if(target[i]==count){
                i++;
                ans.push_back("Push");
            } else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};