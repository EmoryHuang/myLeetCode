class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long> dp(target + 1);
        dp[0]=1;
        for(int i=1;i<=target;i++)
            for(int num:nums)
                // �� taraget ֮ǰ��������������ܳ��� INT_MAX 
                if(i >=num && dp[i-num] < INT_MAX)
                    dp[i] += dp[i-num];
        return dp[target];
    }
};