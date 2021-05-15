/*
 * @Descroption: LeetCode 1441. 用栈操作构建数组
 * @Author: EmoryHuang
 * @Date: 2021-04-19 13:49:36
 * @解题思路:
 * 遍历数组，若在数组中，则`Push`，否则先`Push`再`Pop`
 */

class Solution {
   public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int count = 1;
        for (int i = 0; i < target.size(); count++) {
            if (target[i] == count) {
                i++;
                ans.push_back("Push");
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};