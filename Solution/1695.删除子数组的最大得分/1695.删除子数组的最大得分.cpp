/*
 * @Descroption: LeetCode 1695. ɾ������������÷�
 * @Author: EmoryHuang
 * @Date: 2021-08-10 14:57:39
 * @Method:
 * ��������
 * �������飬����ǰԪ��δ���룬����봰�ڣ�
 * ���������������ظ�Ԫ�أ����ƶ��󴰿ڣ�ɾ���ظ�Ԫ��֮ǰ������Ԫ��
 */

class Solution {
   public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        int ans = 0, sum = 0;
        unordered_set<int> hash;
        while (r < n) {
            // ����ǰԪ��δ����
            if (hash.count(nums[r]) == 0) {
                hash.insert(nums[r]);
                sum += nums[r];
                ans = max(ans, sum);
            } else {
                // ɾ���ظ�Ԫ��֮ǰ������Ԫ��
                while (nums[l] != nums[r]) {
                    sum -= nums[l];
                    hash.erase(nums[l]);
                    l++;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};