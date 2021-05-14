/*
 * @Descroption: LeetCode 6. Z 字形变换
 * @Author: EmoryHuang
 * @Date: 2021-03-17 17:30:36
 * @解题思路: 从左到右迭代 s，将每个字符添加到合适的行。之后从上到下遍历行即可。
 * 使用`cur`记录当前行，只有当我们向上移动到最上面的行或向下移动到最下面的行时，当前方向才会发生改变。
 * PS：一开始用的二维数组，看到题解，瞬间感觉自己好蠢
 */

class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int len = s.length();
        vector<string> row(min(numRows, len));
        int cur = 0;        //当前行
        bool flag = false;  //初始时从上向下
        for (int i = 0; i < len; i++) {
            row[cur] += s[i];
            //若为第一行或者最后一行，则转换方向
            if (cur == 0 || cur == numRows - 1) flag = !flag;
            cur += flag ? 1 : -1;  //从上到下或者从下到上
        }
        string ans;
        for (int i = 0; i < row.size(); i++) ans += row[i];
        return ans;
    }
};