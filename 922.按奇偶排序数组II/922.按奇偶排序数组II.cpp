class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ans(nums.size());
        int odd = 1, even = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] % 2==0){
                ans[even]=nums[i];
                even += 2;
            } else{
                ans[odd]=nums[i];
                odd += 2;
            }
        }
        return ans;
    }
};