/*
 * @Descroption: LeetCode 4. 寻找两个正序数组的中位数
 * @Author: EmoryHuang
 * @Date: 2021-03-16 19:30:36
 * @解题思路: 首先最简单的思路就是合并 2 个数组，然后排序，再输出中位数
 *          第二个方法应用二分的思想，寻找第 k (k>1) 小的元素，可以取 `nums1[k/2-1]` 和
 * `nums2[k/2-1]` 进行比较。 假设两个有序数组的长度分别为 `m` 和 `n`，
 *          对于奇数长度的数组，中位数是两个有序数组中的第 `(m+n)/2` 个元素，
 *          对于偶数长度的数组，中位数是两个有序数组中的第 `(m+n)/2` 个元素和第 `(m+n)/2+1`
 * 个元素的平均值
 */

class Solution {
   public:
    // 方法一：合并排序
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int len2 = nums2.size();
    //     for (int i = 0; i < len2; i++) nums1.push_back(nums2[i]);  //将两个数组合并
    //     sort(nums1.begin(), nums1.end());                          //排序
    //     int len1 = nums1.size();
    //     double ans;
    //     if (len1 % 2 == 0)  //若长度为偶数
    //         ans = (nums1[len1 / 2] + nums1[len1 / 2 - 1]) / 2.0;
    //     else
    //         ans = nums1[len1 / 2];
    //     return ans;
    // }

    //方法二：二分选择
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int ind1 = 0, ind2 = 0;

        while (true) {
            // 边界情况
            if (ind1 == m) return nums2[ind2 + k - 1];         // nums1中的数全部排除
            if (ind2 == n) return nums1[ind1 + k - 1];         // nums2中的数全部排除
            if (k == 1) return min(nums1[ind1], nums2[ind2]);  // k=1即最小值

            // 正常情况
            int newind1 = min(ind1 + k / 2 - 1, m - 1);
            int newind2 = min(ind2 + k / 2 - 1, n - 1);
            int p1 = nums1[newind1];
            int p2 = nums2[newind2];
            if (p1 <= p2) {               //比较第 k/2-1 个元素的大小
                k -= newind1 - ind1 + 1;  //删除排除的元素
                ind1 = newind1 + 1;       //更新下标
            } else {
                k -= newind2 - ind2 + 1;
                ind2 = newind2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();  //总长度
        if (len % 2 == 1) {
            return getKthElement(nums1, nums2, (len + 1) / 2);
        } else {
            return (getKthElement(nums1, nums2, len / 2) +
                    getKthElement(nums1, nums2, len / 2 + 1)) /
                   2.0;
        }
    }
};