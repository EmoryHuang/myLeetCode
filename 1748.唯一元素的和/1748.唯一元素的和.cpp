class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int> mp;
        int ans = 0;
        for(int num:nums){
            if(mp[num]==0) ans+=num;
            else if(mp[num]==1) ans-=num;
            mp[num]++;
        }
        return ans;
    }
};