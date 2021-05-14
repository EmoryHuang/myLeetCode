class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len=nums.size();
        unordered_set<int> st;
        for(int i=0;i<len;i++){
            if(st.find(nums[i])==st.end())
                st.insert(nums[i]);
            else{
                for(int j=0;j<i;j++){
                    if(nums[i]==nums[j] && i-j<=k)
                        return true;
                }
            }
        }
        return false;
    }
};