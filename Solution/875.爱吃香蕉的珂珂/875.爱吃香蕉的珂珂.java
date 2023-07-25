/*
 * @Descroption: LeetCode 875. 爱吃香蕉的珂珂
 * @Author: EmoryHuang
 * @Date: 2023-07-20 10:59:50
 * @Method:
 * 二分查找，搜索所有可能的速度
 */

import java.util.*;

class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1, right = Arrays.stream(piles).max().getAsInt();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    boolean check(int[] piles, int speed, int h) {
        int cnt = 0;
        for (int pile : piles) {
            cnt += (pile + speed - 1) / speed;
        }
        return cnt <= h;
    }
}