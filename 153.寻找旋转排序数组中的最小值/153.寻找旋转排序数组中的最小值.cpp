class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid = left+(right-left)/2;
            if(nums[mid] <= nums.back())
                right=mid;
            else
                left=mid+1;
        }
        return nums[left];
    }
};