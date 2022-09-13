/*
 * @Descroption: LeetCode 1608. 特殊数组的特征值
 * @Author: EmoryHuang
 * @Date: 2022-09-12 11:16:51
 * @Method:
 * 排序 + 枚举 + 二分
 * 枚举x，通过排序加二分找到nums中比x大的元素个数
 */


class Solution {
    public int specialArray(int[] nums) {
        Arrays.sort(nums);
        for (int x = 0; x <= 1000; x++) {
            int l = 0, r = nums.length - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (nums[mid] >= x)
                    r = mid;
                else
                    l = mid + 1;
            }
            if (nums[l] >= x && x == nums.length - r)
                return x;
        }
        return -1;
    }
}