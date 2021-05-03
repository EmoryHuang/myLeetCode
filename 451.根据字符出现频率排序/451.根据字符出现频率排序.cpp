class Solution {
public:
    static bool cmp(pair<char,int> a, pair<char,int> b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto c:s) mp[c]++;
        vector<pair<char,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),cmp);
        string ans;
        for(auto c:v)
            ans += string(c.second,c.first);//×Ö·û´®Æ´½Ó
        return ans;
    }
};