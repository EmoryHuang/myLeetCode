/*
 * @Descroption: LeetCode 962. �������
 * @Author: EmoryHuang
 * @Date: 2021-07-10 14:58:57
 * @����˼·:
 * ��������������飬ջ�д�ŵݼ�Ԫ��
 * �Ӻ���ǰ����, ����ÿ������Ԫ�ش���ջ���ľͿ��Լ����ȣ�Ȼ��ջ������
 */

class Solution {
   public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        for (int i = 0; i < nums.size(); i++)
            // st �д�ŵݼ�Ԫ��
            if (st.empty() || nums[st.top()] > nums[i]) st.push(i);
        int ans = 0;
        // �Ӻ���ǰ����
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                ans = max(ans, i - st.top());
                st.pop();
            }
        }
        return ans;
    }
};