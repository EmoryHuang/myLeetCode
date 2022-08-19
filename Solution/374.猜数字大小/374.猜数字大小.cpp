/*
 * @Descroption: LeetCode 374. 猜数字大小
 * @Author: EmoryHuang
 * @Date: 2021-05-28 15:47:10
 * @解题思路:
 * 二分法猜数字
 */

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
   public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (guess(mid) <= 0)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};