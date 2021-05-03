class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int cur = 0,ans=0;
        for(int i=0;i<K;i++){
            A[cur]=-A[cur];
            if(A[cur]>A[cur+1])cur++;
        }
        for(int num:A) ans += num;
        return ans;
    }
};