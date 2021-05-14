class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int len=citations.size();
        for(int i=0;i<len;i++){
            int h=len-i;
            if(h<=citations[i])
                return h;
        }
        return 0;
    }
};