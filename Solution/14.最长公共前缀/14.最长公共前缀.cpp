/*
 * @Descroption: LeetCode 14. 最长公共前缀
 * @Author: EmoryHuang
 * @Date: 2021-03-20 14:16:36
 * @解题思路: 方法一：取第一个字符串，和后面的比较，与每个单词相同的最长前缀是多少，遍历所有字符串
 *          方法二：以第一个元素为基准，把所有元素左对齐，然后纵向比较
 */

class Solution {
   public:
    // 方法一：find()
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (len == 0) return "";
        string ans;
        ans = strs[0];  //取第一个字符串和后面的比较
        for (int i = 1; i < len; i++) {
            while (strs[i].find(ans) != 0) {
                ans = ans.substr(0, ans.size() - 1);  //取 ans 与每个单词相同的最长前缀
            }
        }
        return ans;
    }

    //方法二：纵向比较
    // string longestCommonPrefix(vector<string>& strs) {
    //     int len = strs.size();
    //     if (len == 0) return "";
    //     if (len == 1) return strs[0];
    //     string ans = strs[0];
    //     for (int i = 0; i < ans.size(); i++) {                    //遍历第一个字符串
    //         for (int j = 1; j < len; j++) {                       //遍历剩余字符串
    //             if (i == strs[j].size() || strs[j][i] != ans[i])  //若到达末尾或者不相等
    //                 return ans.substr(0, i);
    //         }
    //     }
    //     return ans;
    // }
};