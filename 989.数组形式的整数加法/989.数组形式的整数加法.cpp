class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int len = num.size();
        vector<int> ans;
        for(int i=len-1;i>=0;i--){
            int tmp = num[i]+k;
            ans.insert(ans.begin(),tmp%10);
            k =tmp/ 10;
        }
        while(k>0){
            ans.insert(ans.begin(),k%10);
            k /= 10;
        }
        return ans;
    }
};