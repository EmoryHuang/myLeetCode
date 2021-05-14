class Solution {
public:
    int clumsy(int N) {
        if(N<=2)return N;
        if(N==3)return 6;
        int sum = N*(N-1)/(N-2)+N-3;
        N-=4;
        while(N>=4){
            sum += -N*(N-1)/(N-2)+N-3;
            N-=4;
        }
        return sum - clumsy(N);
    }
};