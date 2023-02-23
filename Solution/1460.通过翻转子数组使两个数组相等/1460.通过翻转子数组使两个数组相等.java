/*
* @Descroption: LeetCode 1460. 通过翻转子数组使两个数组相等
* @Author: EmoryHuang
* @Date: 2022-08-24 09:41:38
* @Method:
* 直接排序判断两个数组是否相等
*/


class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        Arrays.sort(arr);
        Arrays.sort(target);
        return Arrays.equals(target, arr);
    }
}