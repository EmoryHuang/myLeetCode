class Solution {
   public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        int sum = 0, maxn;
        for (int i = 0; i < k; i++) sum += nums[i];  //前 k 个数之和
        maxn = sum;
        for (int i = k; i < len; i++) {  //开始滑动
            sum += nums[i] - nums[i - k];
            maxn = max(maxn, sum);
        }
        return (double)maxn / k;
    }
};