class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int num : nums)
            sum += num;
        if(target > sum || (target + sum)%2==1)return 0;
        int posTarget = (target + sum)/2;
        vector<int> dp(posTarget + 1);
        dp[0]=1;
        for(int num : nums)
            for(int i = posTarget;i>=num;i--){
                dp[i] += dp[i-num];
            }
        return dp[posTarget];
    }   
};