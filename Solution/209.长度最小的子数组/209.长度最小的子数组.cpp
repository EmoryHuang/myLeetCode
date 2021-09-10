/*
 * @Descroption: LeetCode 209. ������С��������
 * @Author: EmoryHuang
 * @Date: 2021-05-23 14:56:11
 * @����˼·:
 * �������ڣ�����i��j����ָ��ֱ�ָ��������Ŀ�ͷ��β
 * ����ʱ��ÿ�θ��� sum += nums[j]����sum >= target����i����ƶ�
 */
 
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0, len = INT_MAX;
        int i = 0, j = 0;
        while (j < n) {
            sum += nums[j];
            while (sum >= target) {
                len = min(len, j - i + 1);
                sum -= nums[i++];
            }
            j++;
        }
        return len == INT_MAX ? 0 : len;
    }
};