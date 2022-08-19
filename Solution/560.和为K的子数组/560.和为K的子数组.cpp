/*
 * @Descroption: LeetCode 560. ��ΪK��������
 * @Author: EmoryHuang
 * @Date: 2021-05-29 14:08:56
 * @����˼·:
 * ���ȼ���һάǰ׺��
 * ����������������Ҫö�١���߽硹�͡��ұ߽硹����ʱ��
 *
 * ͨ����ϣ���Ż�
 * ö���ұ߽�
 * �ѡ��ұ߽硹������˵㡹������� cur �����ϣ��
 * ����ϣ���ҵ���Ϊ k ��������
 * ��ȼ��ڴӡ���ϣ�����ҵ�һ�� x��ʹ�� cur - x = k
 */

class Solution {
   public:
    // ����һάǰ׺�ͣ���ʱ��
    // int subarraySum(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> pre(n + 1);
    //     for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + nums[i - 1];
    //     int ans = 0;
    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 1; j <= i; j++) {
    //             int sum = pre[i] - pre[j - 1];
    //             if (sum == k) ans++;
    //         }
    //     }
    //     return ans;
    // }

    // ��ϣ���Ż�
    // int subarraySum(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> pre(n + 1);
    //     for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + nums[i - 1];
    //     int ans = 0;
    //     map<int, int> mp;
    //     for (int i = 1; i <= n; i++) {
    //         int cur = pre[i];
    //         if (cur == k) ans++;
    //         if (mp.count(cur - k)) ans += mp[cur - k];
    //         mp[cur]++;
    //     }
    //     return ans;
    // }

    // ��ϣ��
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, cur = 0;
        map<int, int> mp;
        mp[0] = 1;
        for (int num : nums) {
            cur += num;
            ans += mp[cur - k];
            mp[cur]++;
        }
        return ans;
    }
};