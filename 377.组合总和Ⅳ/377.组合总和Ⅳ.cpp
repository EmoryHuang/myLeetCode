class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long> dp(target + 1);
        dp[0]=1;
        for(int i=1;i<=target;i++)
            for(int num:nums)
                // 在 taraget 之前的数字组合数可能超过 INT_MAX 
                if(i >=num && dp[i-num] < INT_MAX)
                    dp[i] += dp[i-num];
        return dp[target];
    }
};