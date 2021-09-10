class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right =height.size()-1;
        int leftMax = 0,rightMax = 0;
        int ans = 0;
        while(left<=right){
            if(leftMax<rightMax){
                ans+=max(0,leftMax-height[left]);
                leftMax=max(leftMax,height[left]);
                left++;
            }else{
                ans+=max(0,rightMax-height[right]);
                rightMax=max(rightMax,height[right]);
                right--;
            }
        }
        return ans;
    }
};