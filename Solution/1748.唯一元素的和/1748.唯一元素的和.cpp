/*
 * @Descroption: LeetCode 1748. ΨһԪ�صĺ�
 * @Author: EmoryHuang
 * @Date: 2022-02-06 10:57:49
 * @Method:
 * ���⣬�������������٣�����ֱ����hash��¼Ԫ�س��ֵĴ���
 */

class Solution {
   public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> cnt(101, 0);
        for (auto num : nums) cnt[num]++;
        int ans = 0;
        for (int i = 0; i < 101; i++)
            if (cnt[i] == 1) ans += i;
        return ans;
    }
};