class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len=nums.size();
        if(len<3)return false;
        int numsj = INT_MIN;
        stack<int> st;
        for(int k = len-1;k>=0;k--){
            if(nums[k]<numsj)
                return true;
            while(!st.empty() && st.top() < nums[k]){//找到最大的2
                numsj = st.top();
                st.pop();
            }
            st.push(nums[k]);
        }
        return false;
    }
};