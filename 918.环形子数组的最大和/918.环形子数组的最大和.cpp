class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int len = A.size();
        vector<int> dp(len);
        dp[0]=A[0];
        int sum = A[0];//整个数组的和
        int maxSum = INT_MIN;//最大子序和
        for(int i=1;i<len;i++){
            sum += A[i];
            dp[i] = max(dp[i-1]+A[i],A[i]);
            maxSum = max(maxSum,dp[i]);
        }
        int minSum = 0;// A[1]-A[n-1]的最小子序和
        for(int i =1;i<len-1;i++){
            dp[i] = min(dp[i-1]+A[i],A[i]);
            minSum = min(minSum,dp[i]);
        }
        return max(sum - minSum, maxSum);
    }
};