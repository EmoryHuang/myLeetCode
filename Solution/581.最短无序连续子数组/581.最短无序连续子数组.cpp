/*
 * @Descroption: LeetCode 581. �����������������
 * @Author: EmoryHuang
 * @Date: 2021-08-03 11:09:55
 * @Method:
 * ����һ������
 * ��ԭ��������֮�󣬱Ƚ�ǰ�벿�ֺͺ�벿�����򲿷ֵĳ���
 * ��������˫ָ��
 * ���ǿ���ͨ��Ѱ�����������������е����ֵ����Сֵȷ�����ұ߽�
 */

class Solution {
   public:
    // ����һ������
    // int findUnsortedSubarray(vector<int>& nums) {
    //     if (is_sorted(nums.begin(), nums.end())) return 0;
    //     int n = nums.size();
    //     vector<int> copy = nums;
    //     sort(nums.begin(), nums.end());
    //     int l = 0, r = n - 1;
    //     while (copy[l] == nums[l]) l++;
    //     while (copy[r] == nums[r]) r--;
    //     return r - l + 1;
    // }

    // ��������˫ָ��
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = -1, r = -1;
        int minn = INT_MAX, maxn = INT_MIN;
        for (int i = 0; i < n; i++) {
            // Ѱ��������������ұ߽�
            if (nums[i] >= maxn)
                maxn = nums[i];  // ���򣬸���maxn
            else
                r = i;  // ���򣬸��±߽�
            // Ѱ���������������߽�
            if (nums[n - i - 1] <= minn)
                minn = nums[n - i - 1];
            else
                l = n - i - 1;
        }
        if (l == -1) return 0;
        return r - l + 1;
    }
};