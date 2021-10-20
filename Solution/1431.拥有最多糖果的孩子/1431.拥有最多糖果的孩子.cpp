/*
 * @Descroption: LeetCode 1431. ӵ������ǹ��ĺ���
 * @Author: EmoryHuang
 * @Date: 2021-10-20 19:35:50
 * @Method:
 * ���⣬�������������ֵ�Ƚ�
 */

class Solution {
   public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxc = *max_element(candies.begin(), candies.end());
        for (int num : candies) ans.push_back(num + extraCandies >= maxc);
        return ans;
    }
};