/*
 * @Descroption: LeetCode 90. 子集 II
 * @Author: EmoryHuang
 * @Date: 2021-03-31 11:10:36
 * @解题思路:
 * 与 [78. 子集]类似，采用回溯法，但需要剪枝
 * 判断是否需要剪枝，需要先对数组排序，使用排序函数 `sort()`
 * 当`i>start`时，做选择的之前，比较一下当前数`nums[i]`与上一个数`nums[i-1]`是不是相同，相同则`continue`
 */

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> temp;
    void trackBack(vector<int> nums, vector<int>& path, int start) {
        ans.push_back(path);  //把每一条路径加入结果集
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);       //做出选择
            trackBack(nums, temp, i + 1);  //递归进入下一层
            temp.pop_back();               //撤销选择
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        trackBack(nums, temp, 0);
        return ans;
    }
};