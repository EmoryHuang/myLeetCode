/*
 * @Descroption: LeetCode 78. 子集
 * @Author: EmoryHuang
 * @Date: 2021-03-31 10:58:36
 * @解题思路: 回溯法
 * 使用一个参数 start，来标识当前的选择列表的起始位置，将这个路径加入 ans 结果列表
 * 这道题将所有路径都加入，不需要剪枝
 */

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> temp;
    void trackBack(vector<int> nums, vector<int>& path, int start) {
        ans.push_back(path);  //把每一条路径加入结果集
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);       //做出选择
            trackBack(nums, temp, i + 1);  //递归进入下一层
            temp.pop_back();               //撤销选择
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        trackBack(nums, temp, 0);
        return ans;
    }
};