class Solution {
   public:
    int mySqrt(int x) {
        long long left = 0, right = x;
        while (left < right) {
            long long mid = left + (right - left + 1) / 2;
            if (mid <= x / mid)  //³ý·¨·ÀÖ¹Òç³ö
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};