/*
 * @Descroption: LeetCode 2006. ��ľ���ֵΪ K ��������Ŀ
 * @Author: EmoryHuang
 * @Date: 2021-10-08 19:22:02
 * @Method:
 * ��ϣ���¼֮ǰ�����ݸ���
 */

class Solution {
   public:
    int countKDifference(vector<int>& nums, int k) {
        vector<int> hash(101);
        int ans = 0;
        for (int num : nums) {
            if (num - k >= 0) ans += hash[num - k];
            if (num + k <= 100) ans += hash[num + k];
            hash[num]++;
        }
        return ans;
    }
};