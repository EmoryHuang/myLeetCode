/*
 * @Descroption: ��ָ Offer 53 - I. �����������в������� I
 * @Author: EmoryHuang
 * @Date: 2021-07-16 18:35:17
 * @����˼·:
 * ���ַ�Ѱ����˵㣬Ȼ�����˵㿪ʼѰ�� target
 */

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        int ans = 0;
        while (l < nums.size() && nums[l++] == target) ans++;
        return ans;
    }
};