/*
 * @Descroption: LeetCode 1431. 拥有最多糖果的孩子
 * @Author: EmoryHuang
 * @Date: 2021-10-20 19:35:50
 * @Method:
 * 简单题，遍历数组与最大值比较
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