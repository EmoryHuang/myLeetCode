/*
 * @Descroption: LeetCode 643. ���������ƽ���� I
 * @Author: EmoryHuang
 * @Date: 2021-03-19 15:56:36
 * @����˼·:
 * һ��ʼֱ�ӱ���Ȼ����ʱ��Ȼ���ֲ��û������ڵ�˼�룬��Ŀ���Ǽ򵥵�
 * �ȼ���ǰ k ����֮�ͣ�Ȼ��ʼ������������һ��������ȥ��ǰ�����
 */

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