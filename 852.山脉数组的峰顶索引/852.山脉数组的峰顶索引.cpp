class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i;
        for(i=0;i<arr.size()-1;i++)
            if(arr[i]-arr[i+1]>0)
                break;
        return i;
    }
};