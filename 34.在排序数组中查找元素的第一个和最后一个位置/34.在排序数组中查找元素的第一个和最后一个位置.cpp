class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        // урвС╠ъ╫Г
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        if (nums[l] != target) return {-1, -1};
        int start = l;
        // урср╠ъ╫Г
        l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        int end = l;
        return {start, end};
    }
};