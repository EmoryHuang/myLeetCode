/*
 * @Descroption: LeetCode 18. ����֮��
 * @Author: EmoryHuang
 * @Date: 2021-03-22 14:25:36
 * @����˼·: �� ����֮��
 * ���Ƶķ�����ֻ�����ֶ���һ��ѭ����������Ȼ��̶�����ָ�룬�ڲ���ʹ��˫ָ��
 */

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int len = nums.size();
        if (len < 4) return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 3; i++) {          // �̶���һ��ָ��
            for (int j = i + 1; j < len - 2; j++) {  // �̶��ڶ���ָ��
                int left = j + 1, right = len - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target)
                        right--;
                    else if (sum < target)
                        left++;
                    else {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;  //�����ظ�����
                        while (left < right && nums[right] == nums[right - 1]) right--;  //�����ظ�����
                        left++;
                        right--;
                    }
                }
                while (j < len - 1 && nums[j] == nums[j + 1]) j++;  //�����ظ�����
            }
            while (i < len - 2 && nums[i] == nums[i + 1]) i++;  //�����ظ�����
        }
        return ans;
    }
};