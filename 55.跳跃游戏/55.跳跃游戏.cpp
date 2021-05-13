class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > reach) return false;
            reach = max(reach, i + nums[i]);  // 每走一步更新能够到达的最大值
        }
        return true;
    }
};