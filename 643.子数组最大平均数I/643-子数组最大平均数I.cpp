class Solution {
   public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        int sum = 0, maxn;
        for (int i = 0; i < k; i++) sum += nums[i];  //ǰ k ����֮��
        maxn = sum;
        for (int i = k; i < len; i++) {  //��ʼ����
            sum += nums[i] - nums[i - k];
            maxn = max(maxn, sum);
        }
        return (double)maxn / k;
    }
};