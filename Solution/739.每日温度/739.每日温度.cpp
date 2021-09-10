/*
 * @Descroption: LeetCode 739. ÿ���¶�
 * @Author: EmoryHuang
 * @Date: 2021-07-19 16:05:38
 * @����˼·:
 * DFS ����
 * ά��һ���ݼ�ջ���洢Ԫ��λ��
 * ����ǰԪ�ش���ջ��Ԫ�أ����ҵ��˸��ߵ��¶ȣ����³�ջԪ�ض�Ӧ�ĵȴ�����
 */

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};