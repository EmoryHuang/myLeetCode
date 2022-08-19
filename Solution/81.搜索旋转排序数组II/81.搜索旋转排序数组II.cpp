/*
 * @Descroption: LeetCode 81. ������ת�������� II
 * @Author: EmoryHuang
 * @Date: 2021-04-07 18:20:36
 * @����˼·: ����˼·��[������ת��������]��ͬ�����������п������ظ�Ԫ��
 * ��Ȼ˵ֱ�ӱ���Ҳ����ͨ���������ǳ����˶��ַ�����������ת�����飬��˻���Ҫ�ж� mid ��λ��
 */

class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            while (left < right && nums[left] == nums[left + 1]) left++;     // �����ظ�Ԫ��
            while (left < right && nums[right] == nums[right - 1]) right--;  // �����ظ�Ԫ��
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])  // target��������
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[right])  // target�����Ұ��
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};