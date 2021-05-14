class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len=nums.size();
        set<long> st;
        for(int i=0;i<len;i++){
            auto iter = st.lower_bound((long)nums[i]-t);
            if(iter!=st.end() && *iter <= (long)nums[i]+t)
                return true;
            st.insert(nums[i]);
            if(i>=k)st.erase(nums[i-k]);
        }
        return false;
    }
};