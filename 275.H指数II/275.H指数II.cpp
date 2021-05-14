class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len=citations.size();
        int left=0,right=len-1;
        while(left<=right){
            int mid = left + (right - left) /2;
            if(citations[mid]==len-mid)
                return len-mid;
            else if(citations[mid]>len-mid)
                right=mid-1;
            else
                left=left+1;
        }
        return len-left;
    }
};