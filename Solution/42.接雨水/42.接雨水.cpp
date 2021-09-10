/*
 * @Descroption: LeetCode 42. 接雨水
 * @Author: EmoryHuang
 * @Date: 2021-04-02 18:08:36
 * @解题思路:
 * 方法一，使用双指针，只要右边有比左边高的柱子，无论中间是什么情况。当前能存的雨水量只和左边的柱子相关，左右两个指针更新左边最高和右边最高，直到相交
 * 方法二，总体积减去柱子体积就是水的容量，利用左右指针的下标差值计算出每一层雨水和柱子的体积
 */

class Solution {
   public:
    // 方法一：双指针
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while (left <= right) {
            if (leftMax < rightMax) {  //若右边比左边高，当前能存的雨水量只和左边的柱子相关
                ans += max(0, leftMax - height[left]);
                leftMax = max(leftMax, height[left]);  //更新最高柱子
                left++;
            } else {
                ans += max(0, rightMax - height[right]);
                rightMax = max(rightMax, height[right]);
                right--;
            }
        }
        return ans;
    }

    // 方法二：按行计算体积
    // int trap(vector<int>& height) {
    //     int left = 0, right = height.size() - 1;
    //     int high = 1;
    //     int sum = 0, v = 0;
    //     for (int i = 0; i < height.size(); i++) sum += height[i];
    //     while (left <= right) {
    //         while (left <= right && height[left] < high) left++;
    //         while (left <= right && height[right] < high) right--;
    //         v += right - left + 1;  //计算每层的体积
    //         high++;
    //     }
    //     return v - sum;  //减去原始体积
    // }
};