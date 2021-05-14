class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int len = tokens.size();
        for (int i = 0; i < len; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                if (tokens[i] == "+")
                    nums.push(b + a);
                else if (tokens[i] == "-")
                    nums.push(b - a);
                else if (tokens[i] == "*")
                    nums.push(b * a);
                else
                    nums.push(b / a);
            } else {
                nums.push(stoi(tokens[i]));
            }
        }
        return nums.top();
    }
};