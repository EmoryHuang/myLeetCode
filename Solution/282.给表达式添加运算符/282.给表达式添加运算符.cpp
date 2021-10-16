/*
 * @Descroption: LeetCode 282. 给表达式添加运算符
 * @Author: EmoryHuang
 * @Date: 2021-10-16 09:23:55
 * @Method:
 * 回溯
 * 使用回溯考虑所有可能的操作数，计算 '+', '-', '*'
 * 计算乘法时，由于优先级的问题，需要记录上一步的操作数，使用 pre 记录
 */

class Solution {
   public:
    vector<string> ans;
    int n;
    void dfs(string path, int idx, long long cur, long long pre, string num, int target) {
        if (idx == n) {
            if (cur == target) ans.push_back(path);
            return;
        }
        for (int i = idx; i < n; i++) {
            // 数字不能以 0 开头
            if (num[idx] == '0' && i > idx) break;
            // 遍历得到可能的数字
            string c = num.substr(idx, i - idx + 1);
            long long numc = stoll(c);
            if (idx == 0)
                dfs(path + c, i + 1, numc, numc, num, target);
            else {
                dfs(path + '+' + c, i + 1, cur + numc, numc, num, target);
                dfs(path + '-' + c, i + 1, cur - numc, -numc, num, target);
                // 计算乘法时，由于优先级的问题，需要记录上一步的操作数，使用 pre 记录
                dfs(path + '*' + c, i + 1, cur - pre + pre * numc, pre * numc, num, target);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        n = num.size();
        dfs("", 0, 0, 0, num, target);
        return ans;
    }
};