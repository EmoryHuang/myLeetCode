class Solution {
public:
    int findComplement(int N) {
        if(N==0)return 1;
        long num = 1;
        while(num <= N)
            num <<= 1;
        return num - 1 - N;
    }
};