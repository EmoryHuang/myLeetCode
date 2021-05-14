class Solution {
public:
    int totalMoney(int n) {
        return n/7*28+(n/7)*(n/7-1)/2*7 + (n/7+1+n/7+n%7)*(n%7)/2;
    }
};