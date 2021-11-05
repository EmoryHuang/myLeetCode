/*
 * @Descroption: LeetCode 1773. ͳ��ƥ������������Ʒ����
 * @Author: EmoryHuang
 * @Date: 2021-11-05 19:49:44
 * @Method:
 * ���⣬�����������ƥ��
 */

class Solution {
   public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int idx, ans = 0;
        if (ruleKey == "type")
            idx = 0;
        else if (ruleKey == "color")
            idx = 1;
        else
            idx = 2;
        for (auto item : items)
            if (item[idx] == ruleValue) ans++;
        return ans;
    }
};