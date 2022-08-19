/*
 * @Descroption: LeetCode 1944. �����п��Կ���������
 * @Author: EmoryHuang
 * @Date: 2021-09-10 19:54:25
 * @Method:
 * ����ջ + �������
 * �ʼ���������������žһ�¾ͳ�ʱ��
 * ���������ά��һ���ݼ�ջ������ i ������ջ��Ԫ�� j �Ƚϣ�
 * �� heights[i] > heights[j]��˵�� i �ܹ����� j��i �����˿����� j�����ջ���Ƚ���һ��ջ��Ԫ��
 * ���� i �ܹ����� j��i ������ j �Ҳ���ˣ��˳��Ƚ�
 */

class Solution {
   public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        // �������
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty()) {
                ans[i]++;
                if (heights[i] > heights[st.top()])
                    // i �ܹ����� j��i �����˿����� j����ջ���Ƚ���һ��ջ��Ԫ��
                    st.pop();
                else
                    // i �ܹ����� j��i ������ j �Ҳ���ˣ��˳��Ƚ�
                    break;
            }
            st.push(i);
        }
        return ans;
    }
};