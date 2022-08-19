/*
 * @Descroption: LeetCode 303. 区域和检索 - 数组不可变
 * @Author: EmoryHuang
 * @Date: 2021-03-26 09:43:36
 * @解题思路:
 * 最朴素的想法是存储数组 `nums` 的值，每次调用 `sumRange` 时，
 * 通过循环的方法计算数组 `nums` 从下标 `i` 到下标 `j` 范围内的元素和
 *
 * 可以先创建一个前缀和数组，用来存放从原数组每项累加的和，这样可以利用减法，直接得出结果
 */

class NumArray {
   public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr.push_back(0);
        int sum = 0;
        for (int i = 1; i <= nums.size(); i++) {
            sum += nums[i - 1];
            arr.push_back(sum);
        }
    }

    int sumRange(int left, int right) { return arr[right + 1] - arr[left]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */