/*
 * @Descroption: LeetCode 1441. ��ջ������������
 * @Author: EmoryHuang
 * @Date: 2021-04-19 13:49:36
 * @����˼·:
 * �������飬���������У���`Push`��������`Push`��`Pop`
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