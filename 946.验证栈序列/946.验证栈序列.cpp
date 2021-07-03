/*
 * @Descroption: LeetCode 946. ��֤ջ����
 * @Author: EmoryHuang
 * @Date: 2021-07-03 14:25:59
 * @����˼·:
 * ģ�⣬ʹ��stackģ����ջ��
 * ��ջ�ǿգ�����ջ��Ԫ�ص��ڳ�ջԪ�أ����ջ
 */

class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int cnt = 0;
        for (int num : pushed) {
            st.push(num);
            // ��ջ�ǿգ�����ջ��Ԫ�ص��ڳ�ջԪ��
            while (!st.empty() && cnt < popped.size() && st.top() == popped[cnt]) {
                cnt++;
                st.pop();
            }
        }
        return cnt == popped.size();
    }
};