class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len=nums.size(),count=0;;
        for(int i =0;i<len-1;i++){
            if(nums[i]>nums[i+1]){
                if(i==0||nums[i+1]>=nums[i-1])
                    nums[i]=nums[i+1];
                else
                    nums[i+1]=nums[i];
                count++;
            }
        }
        return count <2;
    }
};