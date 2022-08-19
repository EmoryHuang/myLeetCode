/*
 * @Descroption: LeetCode 11. 盛最多水的容器
 * @Author: EmoryHuang
 * @Date: 2021-03-19 14:22:36
 * @解题思路: 刚开始直接暴力硬刚，然后就超时了，使用双指针方法，其实重要的是移动哪个的思路
 *      如果宽度变小，那么面积想比之前的更大，唯一的可能是最短的短板比之前要高。
 *      所以更高的木板没必要移动，只需要移动较短的那个板
 */

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int maxv = 0, v;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            v = min(height[i], height[j]) * (j - i);  //面积
            maxv = max(maxv, v);
            if (height[i] < height[j])  //移动较短的那个板
                i++;
            else
                j--;
        }
        return maxv;
    }
};