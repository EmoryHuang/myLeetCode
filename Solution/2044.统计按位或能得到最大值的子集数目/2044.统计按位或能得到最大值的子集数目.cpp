/*
 * @Descroption: LeetCode 2044. ͳ�ư�λ���ܵõ����ֵ���Ӽ���Ŀ
 * @Author: EmoryHuang
 * @Date: 2022-03-15 10:22:32
 * @Method:
 * ����һ��������ö��
 * ������ö�٣�ʹ�� n λ�����Ƽ�¼ nums �е�ÿ�������Ƿ�ѡ��
 * ͬʱά����λ���ܵõ������ֵ
 *
 * ��������dfs
 * ����ö��ÿ�� num �Ƿ�ѡ�񣬲���¼�ܵõ������ֵ
 */

class Solution {
   public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, max_num = 0;
        for (int s = 0; s < 1 << n; s++) {
            int cur_num = 0;
            for (int i = 0; i < n; i++) {
                if ((s >> i) & 1) cur_num |= nums[i];
            }
            if (cur_num > max_num) {
                max_num = cur_num;
                ans = 1;
            } else if (cur_num == max_num)
                ans++;
        }
        return ans;
    }

    // ��������dfs
    // int n, max_num = 0, ans = 0;
    // void dfs(int idx, int num, vector<int>& nums) {
    //     if (idx == n) {
    //         if (num > max_num) {
    //             max_num = num;
    //             ans = 1;
    //         } else if (num == max_num)
    //             ans++;
    //         return;
    //     }
    //     dfs(idx + 1, num, nums);
    //     dfs(idx + 1, num | nums[idx], nums);
    // }
    // int countMaxOrSubsets(vector<int>& nums) {
    //     n = nums.size();
    //     dfs(0, 0, nums);
    //     return ans;
    // }
};