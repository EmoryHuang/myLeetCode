/*
 * @Descroption: ��ָ Offer II 038. ÿ���¶�
 * @Author: EmoryHuang
 * @Date: 2021-08-04 19:47:35
 * @Method:
 * ά��һ������ջ
 * �������飬��������ջ��Ԫ�ظ����Ԫ�أ�����³�ջԪ�ض�Ӧ�ĵȴ�����
 * ������������Ԫ����ջ
 */

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < temperatures.size(); i++) {
            // ά���ݼ�ջ
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                // ���µȴ�����
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};