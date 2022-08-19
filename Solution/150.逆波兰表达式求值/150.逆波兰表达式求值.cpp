/*
 * @Descroption: LeetCode 150. �沨�����ʽ��ֵ
 * @Author: EmoryHuang
 * @Date: 2021-03-20 14:53:36
 * @����˼·: ��׺���ʽ��ֵ�����⣬�������£�
 * 1. �������ʽ���������������ȷ���ջ��
 * 2. ��������������򵯳� `a` �� `b`��ִ�� `b + a`���������ѹ�뵽ջ��
 * 3. ���������֣�����ֱ�ӷ���ջ��
 */

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int len = tokens.size();
        for (int i = 0; i < len; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int a = nums.top();  // a�ȵ���
                nums.pop();
                int b = nums.top();  // b�󵯳�
                nums.pop();
                if (tokens[i] == "+")
                    nums.push(b + a);  //ע��a��b������˳�򣬽���������ջ
                else if (tokens[i] == "-")
                    nums.push(b - a);
                else if (tokens[i] == "*")
                    nums.push(b * a);
                else
                    nums.push(b / a);
            } else {
                nums.push(stoi(tokens[i]));  //תΪint����������ջ
            }
        }
        return nums.top();
    }
};