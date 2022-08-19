/*
 * @Descroption: LeetCode 2012. ��������ֵ���
 * @Author: EmoryHuang
 * @Date: 2021-10-15 20:20:15
 * @Method:
 * ģ��
 * ʹ�� l2r, r2l �ֱ��¼ [0, i) �е����ֵ��[i + 1, n) �е���Сֵ
 * ֮�������������ֵ
 */

class Solution {
   public:
    int sumOfBeauties(vector<int>& nums) {
        int ans = 0, n = nums.size();
        // l2r, r2l �ֱ��¼�� i ��λ��֮ǰ�����ֵ��֮�����Сֵ
        vector<int> l2r(n), r2l(n);
        l2r[0] = nums[0];
        r2l[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            l2r[i] = max(l2r[i - 1], nums[i]);
            r2l[n - i - 1] = min(r2l[n - i], nums[n - i - 1]);
        }
        // �������������ֵ
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > l2r[i - 1] && nums[i] < r2l[i + 1])
                ans += 2;
            else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
                ans++;
        }
        return ans;
    }
};