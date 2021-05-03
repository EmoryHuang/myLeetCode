class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=0;
        for(int num:nums)
            mp[num]++;
        for(auto [num,c]:mp)
            if(c==1){
                ans=num;
                break;
            }
        return ans;
    }
};