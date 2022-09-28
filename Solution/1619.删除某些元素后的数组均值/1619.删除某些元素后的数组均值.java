/*
 * @Descroption: LeetCode 1619. 删除某些元素后的数组均值
 * @Author: EmoryHuang
 * @Date: 2022-09-14 09:15:33
 * @Method:
 * 简单题，排序后直接截取
 */

class Solution {
    public double trimMean(int[] arr) {
        Arrays.sort(arr);
        double ans = 0;
        int n = arr.length;
        for (int i = n / 20; i < n * 19 / 20; i++) {
            ans += arr[i];
        }
        return ans / (n * 9 / 10);
    }
}