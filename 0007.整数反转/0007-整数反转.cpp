class Solution {
   public:
    int reverse(int x) {
        long ans = 0;
        while (x) {
            ans = ans * 10 + x % 10;  //��β��
            x /= 10;
        }
        if (ans > INT_MAX || ans < INT_MIN)  //�ж�Խ��
            return 0;
        else
            return ans;
    }
};