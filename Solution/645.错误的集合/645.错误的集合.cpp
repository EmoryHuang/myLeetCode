/*
 * @Descroption: LeetCode 645. ����ļ���
 * @Author: EmoryHuang
 * @Date: 2021-05-29 16:08:00
 * @����˼·:
 * ���⣬���Ա�������ϣ������
 */

class Solution {
   public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2);
        vector<int> hash(n + 1);
        for (int num : nums) hash[num]++;
        for (int i = 1; i <= n; i++) {
            if (hash[i] == 0)
                ans[1] = i;
            else if (hash[i] == 2)
                ans[0] = i;
        }
        return ans;
    }
};