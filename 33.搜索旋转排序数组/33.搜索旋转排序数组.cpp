class Solution {
   public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        // Ѱ����ת�������Сֵ
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= nums.back())
                right = mid;
            else
                left = mid + 1;
        }
        // �ж� target ��������
        if (target <= nums.back())
            right = nums.size() - 1;
        else {
            left = 0;
            right--;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        if (nums[left] != target) return -1;
        return left;
    }
};