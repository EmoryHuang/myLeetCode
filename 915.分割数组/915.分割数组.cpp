class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        if(A.size()==0)return 0;
        int maxA = A[0],maxLeft=A[0];
        int pos=0;
        for(int i=0;i<A.size();i++){
            maxA = max(maxA,A[i]);
            if(maxLeft > A[i]){ // 找到第一个比左侧数字都大的值
                maxLeft = maxA;
                pos = i;
            }
        }
        return pos + 1;
    }
};