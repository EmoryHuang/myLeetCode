/*
 * @Descroption: LeetCode 726. 原子的数量
 * @Author: EmoryHuang
 * @Date: 2021-07-05 21:33:40
 * @解题思路:
 * 反向遍历字符串
 * 若读到数字则记录，若读到字母则记录
 * 若读到 ) 则将其左边的数字作为倍数，并更新总倍数
 * 若读到 ( 则将对应 ) 的倍数还原
 * 若读到大写字母，则反转字符串，并将 str 和 num 放入 map
 */


class Solution {
   public:
    string countOfAtoms(string formula) {
        map<string, int> mp;
        stack<int> hash;
        // str 记录字符，num 记录数字，muls记录总的倍数
        string str, num;
        int muls = 1;
        // 从后向前遍历字符串
        for (int i = formula.size() - 1; i >= 0; i--) {
            // 如果是数字，则记录
            if (isdigit(formula[i]))
                num = formula[i] + num;
            else if (formula[i] == ')') {
                // 若 num 为空，则说明括号右边没有数字，则倍数为 1
                // 否则倍数为 num
                int mul = num == "" ? 1 : stoi(num);
                num = "";     // 重新记录 num
                muls *= mul;  // 更新总的倍数
                hash.push(mul);
            } else if (formula[i] == '(') {
                muls /= hash.top();  // 更新总的倍数
                hash.pop();
            } else {
                str += formula[i];
                if (isupper(formula[i])) {
                    // 若读到大写字母，则反转字符串，并加入 map
                    reverse(str.begin(), str.end());
                    mp[str] += (num == "" ? 1 : stoi(num)) * muls;
                    str = "", num = "";  // 清空
                }
            }
        }
        string ans;
        for (auto i : mp) {
            ans += i.first;
            if (i.second > 1) ans += to_string(i.second);
        }
        return ans;
    }
};