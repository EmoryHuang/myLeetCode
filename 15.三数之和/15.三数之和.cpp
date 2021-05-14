/*
 * @Descroption: LeetCode 15. ����֮��
 * @Author: EmoryHuang
 * @Date: 2021-03-21 11:05:36
 * @����˼·: ���ȣ�ֱ�� for ѭ�������붼�����룬�϶���ʱ����ô�����������μ�֦���Լ�ȥ���ظ���
 *      ������������˫ָ���������������������飬�̶�һ����`nums[i]`����ʹ������ָ��`j`,`k`ָ��`nums[i]`���������
 *      ���ʹ��� `0`��˵�� `nums[k]` ̫��k ���ƣ�����С�� `0`��˵��`nums[j]`̫С��j ����
 *      �����ظ�Ԫ�أ���������������ظ���
 */

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ans;
        if (len < 3) return ans;  //Ԫ�ظ�������3��
        sort(nums.begin(), nums.end());
        if (nums[0] > 0) return ans;  //������Ԫ�ض�����0
        for (int i = 0; i < len; i++) {
            int j = i + 1, k = len - 1;  //˫ָ��
            while (j < k) {
                if (nums[j] + nums[k] > -nums[i])
                    k--;
                else if (nums[j] + nums[k] < -nums[i])
                    j++;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;  //�����ظ�����
                    while (j < k && nums[k] == nums[k - 1]) k--;  //�����ظ�����
                    j++;                                          //�ƶ�ָ��
                    k--;
                }
            }
            while (i + 1 < len && nums[i] == nums[i + 1]) i++;  //�����ظ�����
        }
        return ans;
    }
};