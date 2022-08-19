/*
 * @Descroption: LeetCode 1838. ���ƵԪ�ص�Ƶ��
 * @Author: EmoryHuang
 * @Date: 2021-07-19 14:45:33
 * @����˼·:
 * ����һ������ + ��������
 * �жϵ�ǰ���������Ƿ���������
 * ������������ + �������� + ����
 * ���ȣ�ͨ�����ַ��жϵ�ǰѡ��Ƶ���Ƿ����
 * ������˵��ͨ���������ڽ����жϣ�����Ƶ���̶���������ǿ����жϣ���ǰ�����ڵ�Ԫ���Ƿ���������
 * Ŀ�����ּ�Ϊ��ǰ�����Ҷ˵��Ӧ�����֣�ͨ���ж�Ŀ������ͼ����жϵ�ǰ�����Ƿ���������
 */

class Solution {
   public:
    // ����һ������ + ��������
    // int maxFrequency(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());
    //     int l = 0, ans = 1;
    //     long diff = 0;
    //     for (int r = 1; r < n; r++) {
    //         diff += (long)(r - l) * (nums[r] - nums[r - 1]);
    //         if (diff > k) {
    //             diff -= nums[r] - nums[l];
    //             l++;
    //         }
    //         ans = max(ans, r - l + 1);
    //     }
    //     return ans;
    // }

    // ������������ + �������� + ����
    int n;
    bool check(vector<int> nums, vector<long> pre, int fre, int k) {
        for (int i = 0; i < n + 1 - fre; i++) {
            int j = i + fre - 1;
            long diff = (long)fre * nums[j] - (pre[j + 1] - pre[i]);
            if (diff <= k) return true;
        }
        return false;
    }
    int maxFrequency(vector<int>& nums, int k) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long> pre(n + 1);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + nums[i - 1];
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(nums, pre, mid, k))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};