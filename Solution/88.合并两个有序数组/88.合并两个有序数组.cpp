/*
 * @Descroption: LeetCode 88. 合并两个有序数组
 * @Author: EmoryHuang
 * @Date: 2021-03-24 16:14:36
 * @解题思路:
 * 最省事的方法，合并然后 sort()
 *
 * 相比于正向双指针（即正向遍历两个数组，选择较小的一个放入新的数组）而言，
 * 逆向双指针的优点在于不需要额外空间
 */

class Solution {
   public:
    // 方法一：合并sort()
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     for (int i = 0; i < n; i++) nums1[m + i] = nums2[i];
    //     sort(nums1.begin(), nums1.end());
    // }

    // 方法二：逆向双指针
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int tail = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j])
                nums1[tail--] = nums1[i--];
            else
                nums1[tail--] = nums2[j--];
        }
        while (j >= 0) nums1[tail--] = nums2[j--];  // 若还有剩余
    }
};