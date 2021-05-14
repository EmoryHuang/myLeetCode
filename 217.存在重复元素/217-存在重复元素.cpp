class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        unordered_set<int> st;
        for (int i = 0; i < len; i++) {
            if (st.find(nums[i]) == st.end())
                st.insert(nums[i]);
            else
                return true;
        }
        return false;
    }
};