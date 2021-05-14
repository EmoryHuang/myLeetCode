/*
 * @Descroption: LeetCode 456. 132 模式
 * @Author: EmoryHuang
 * @Date: 2021-03-24 15:08:36
 * @解题思路:
 * 首先要明白 1 是 3 左边的最小的数字； 2 是 3 右边的比 3 小并且比 1 大的数字
 * 暴力法可以通过遍历 3 的位置，找到 3 左边最小的元素 1 ，同时在 3 的右边找到 2 即可
 *
 * 评论里普遍给出了一种使用单调栈的方法，「单调栈」就是栈中的元素都是依次递增或者递减的，这里使用的是单调递减栈
 * 从右向左遍历 1 ，使用单调栈找到右边部分最大的元素（3）
 * 若当前元素`nums[i]`大于栈顶元素，则弹出并作为 2
 * 之后再在左边寻找小于 2 的元素（1）
 */

class Solution {
   public:
    // 方法一：暴力法
    // bool find132pattern(vector<int>& nums) {
    //     int len = nums.size();
    //     int i = nums[0];
    //     for (int j = 1; j < len - 1; j++) {  //遍历j,k
    //         for (int k = j + 1; k < len; k++)
    //             if (i < nums[k] && nums[k] < nums[j]) return true;
    //         i = min(i, nums[j]);  //更新i为较小的元素
    //     }
    //     return false;
    // }

    // 方法二：单调栈
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return false;
        int numsj = INT_MIN;
        stack<int> st;
        for (int i = len - 1; i >= 0; i--) {  //从右向左，可以保证出栈的元素2必然是在入栈元素3右侧
            if (nums[i] < numsj) return true;            //寻找比2小的数
            while (!st.empty() && st.top() < nums[i]) {  //栈顶元素为 i 右侧最大值，3
                numsj = st.top();  //若遇到比栈顶元素还大的数，则弹出，作为 2
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};