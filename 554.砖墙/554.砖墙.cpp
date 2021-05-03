class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int> mp;
        int ans = 0;
        for(auto sub:wall){
            int sum = 0;
            for(int i=0;i<sub.size()-1;i++){
                sum += sub[i];
                mp[sum]++;
            }
        }
        for(auto a:mp)
            ans = max(ans,a.second);
        return wall.size()-ans;
    }
};