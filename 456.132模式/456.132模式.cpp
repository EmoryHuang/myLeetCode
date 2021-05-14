/*
 * @Descroption: LeetCode 456. 132 ģʽ
 * @Author: EmoryHuang
 * @Date: 2021-03-24 15:08:36
 * @����˼·:
 * ����Ҫ���� 1 �� 3 ��ߵ���С�����֣� 2 �� 3 �ұߵı� 3 С���ұ� 1 �������
 * ����������ͨ������ 3 ��λ�ã��ҵ� 3 �����С��Ԫ�� 1 ��ͬʱ�� 3 ���ұ��ҵ� 2 ����
 *
 * �������ձ������һ��ʹ�õ���ջ�ķ�����������ջ������ջ�е�Ԫ�ض������ε������ߵݼ��ģ�����ʹ�õ��ǵ����ݼ�ջ
 * ����������� 1 ��ʹ�õ���ջ�ҵ��ұ߲�������Ԫ�أ�3��
 * ����ǰԪ��`nums[i]`����ջ��Ԫ�أ��򵯳�����Ϊ 2
 * ֮���������Ѱ��С�� 2 ��Ԫ�أ�1��
 */

class Solution {
   public:
    // ����һ��������
    // bool find132pattern(vector<int>& nums) {
    //     int len = nums.size();
    //     int i = nums[0];
    //     for (int j = 1; j < len - 1; j++) {  //����j,k
    //         for (int k = j + 1; k < len; k++)
    //             if (i < nums[k] && nums[k] < nums[j]) return true;
    //         i = min(i, nums[j]);  //����iΪ��С��Ԫ��
    //     }
    //     return false;
    // }

    // ������������ջ
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return false;
        int numsj = INT_MIN;
        stack<int> st;
        for (int i = len - 1; i >= 0; i--) {  //�������󣬿��Ա�֤��ջ��Ԫ��2��Ȼ������ջԪ��3�Ҳ�
            if (nums[i] < numsj) return true;            //Ѱ�ұ�2С����
            while (!st.empty() && st.top() < nums[i]) {  //ջ��Ԫ��Ϊ i �Ҳ����ֵ��3
                numsj = st.top();  //��������ջ��Ԫ�ػ���������򵯳�����Ϊ 2
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};