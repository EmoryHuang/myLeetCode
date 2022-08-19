/*
 * @Descroption: LeetCode 1296. ��������Ϊ�������ֵļ���
 * @Author: EmoryHuang
 * @Date: 2021-07-15 19:52:22
 * @����˼·:
 * �ù�ϣ���¼����Ԫ�ص�����
 * ��������Ԫ�ؽ��б���������ÿ��Ԫ�� num
 * �� num + i �ĸ���Ϊ0���򷵻� false
 */

class Solution {
   public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        for (auto num : nums) mp[num]++;
        for (auto num : nums) {
            if (mp[num] == 0) continue;
            for (int i = 0; i < k; i++) {
                if (mp.count(num + i) == 0) return false;
                mp[num + i]--;
            }
        }
        return true;
    }
};