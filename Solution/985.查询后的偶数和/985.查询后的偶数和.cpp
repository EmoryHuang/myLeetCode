/*
 * @Descroption: LeetCode 985. ��ѯ���ż����
 * @Author: EmoryHuang
 * @Date: 2021-10-21 19:35:08
 * @Method:
 * ģ��
 * ����ԭ����ż���� sum��������ѯ
 * ���޸�ǰ��ż�������� sum �м�ȥ
 * ���޸ĺ�����ż��������������
 */

class Solution {
   public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> ans;
        // ����ԭ����ż����
        for (int num : nums)
            if (num % 2 == 0) sum += num;
        for (auto q : queries) {
            int val = q[0], idx = q[1];
            // ���޸�ǰ��ż�������� sum �м�ȥ
            if (nums[idx] % 2 == 0) sum -= nums[idx];
            nums[idx] += val;
            // ���޸ĺ�����ż��
            if (nums[idx] % 2 == 0) sum += nums[idx];
            ans.push_back(sum);
        }
        return ans;
    }
};