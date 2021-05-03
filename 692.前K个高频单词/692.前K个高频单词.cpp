class Solution {
public:
    static bool cmp(pair<string,int> a,pair<string,int> b){
        if(a.second != b.second) return a.second > b.second;
        else return a.first < b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto w:words) mp[w]++;
        vector<pair<string,int>> p(mp.begin(),mp.end());
        vector<string> ans;
        sort(p.begin(),p.end(),cmp);
        for(int i=0;i<k;i++)
            ans.push_back(p[i].first);
        return ans;
    }
};