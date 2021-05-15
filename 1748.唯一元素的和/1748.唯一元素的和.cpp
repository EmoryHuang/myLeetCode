/*
 * @Descroption: LeetCode 1748. ΨһԪ�صĺ�
 * @Author: EmoryHuang
 * @Date: 2021-05-06 18:48:36
 * @����˼·:
 * ʹ�� map ͳ��Ԫ�س��ֵĴ������������飬ͳ��ΨһԪ�صĺ�
 */

class Solution {
   public:
    int sumOfUnique(vector<int>& nums) {
        map<int, int> mp;
        int ans = 0;
        for (int num : nums) {
            if (mp[num] == 0)
                ans += num;
            else if (mp[num] == 1)
                ans -= num;
            mp[num]++;
        }
        return ans;
    }
};