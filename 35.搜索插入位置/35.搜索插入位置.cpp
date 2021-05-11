class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0 || nums.back() < target) return nums.size();
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};