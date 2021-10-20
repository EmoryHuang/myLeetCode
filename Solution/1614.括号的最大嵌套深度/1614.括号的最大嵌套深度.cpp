/*
 * @Descroption: LeetCode 1614. ���ŵ����Ƕ�����
 * @Author: EmoryHuang
 * @Date: 2021-10-20 08:44:40
 * @Method:
 * ���⣬ʹ��ջ��¼���ŵ����Ƕ�����
 */

class Solution {
   public:
    int maxDepth(string s) {
        stack<char> stack;
        int ans = 0;
        for (auto c : s) {
            if (c == '(') {
                stack.push(c);
                ans = max(ans, (int)stack.size());
            } else if (c == ')')
                stack.pop();
        }
        return ans;
    }
};