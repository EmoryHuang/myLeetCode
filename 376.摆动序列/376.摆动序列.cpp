class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        int flag = 0;// 摆动方向
        int ans = 1;
        for(int i = 1;i<len;i++){
            // 前一个差和后一个差正负交替
            if((flag >=0 && nums[i]-nums[i-1] <0) || (flag<=0 && nums[i]-nums[i-1] >0)){
                flag = nums[i]-nums[i-1];
                ans++;
            }
        }
        return ans;
    }
};