/*
 * @Descroption: LeetCode 594. ���г������
 * @Author: EmoryHuang
 * @Date: 2021-10-13 08:57:40
 * @Method:
 * ����һ������ + ˫ָ��
 * �����������в���ֻҪ��������ȣ���˿���ֱ������Ȼ��ͨ��˫ָ���ҵ����г�����еĳ���
 *
 * ����������ϣ��
 * ʹ�ù�ϣ���¼Ԫ�س��ֵĴ�����num ���Ժ� num + 1 ��ɺ�г������
 * Ҳ������������ֵΪ 1 ����������ܸ���
 */

class Solution {
   public:
    // ����һ������ + ˫ָ��
    // int findLHS(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     int l = 0, r = 0, ans = 0;
    //     for (; r < nums.size(); r++) {
    //         while (nums[r] - nums[l] > 1) l++;
    //         if (nums[r] - nums[l] == 1) ans = max(ans, r - l + 1);
    //     }
    //     return ans;
    // }

    // ����������ϣ��
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> hash;
        int ans = 0;
        for (int num : nums) {
            hash[num]++;
            if (hash[num - 1] > 0) ans = max(ans, hash[num] + hash[num - 1]);
            if (hash[num + 1] > 0) ans = max(ans, hash[num] + hash[num + 1]);
        }
        return ans;
    }
};