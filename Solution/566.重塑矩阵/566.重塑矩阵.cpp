/*
 * @Descroption: LeetCode 566. ���ܾ���
 * @Author: EmoryHuang
 * @Date: 2021-04-16 18:56:36
 * @����˼·: ���±���һ�鲢��ֵע�����к��±��ת��
 */

class Solution {
   public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c) return nums;
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < m * n; i++) {
            ans[i / c][i % c] = nums[i / n][i % n];
        }
        return ans;
    }
};