class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;
        for(int num :nums){
            sum += num;
            ans.push_back(sum);
        }
        return ans;
    }
};