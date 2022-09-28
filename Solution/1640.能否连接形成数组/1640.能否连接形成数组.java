/*
 * @Descroption: LeetCode 1640. 能否连接形成数组
 * @Author: EmoryHuang
 * @Date: 2022-09-22 09:33:43
 * @Method:
 * 使用哈希表记录每个数组的首元素
 * 之后遍历arr,寻找数组首元素并判断数组顺序是否一致
 */

class Solution {
    public boolean canFormArray(int[] arr, int[][] pieces) {
        Map<Integer, int[]> map = new HashMap<>();
        for (int[] p : pieces) {
            map.put(p[0], p);
        }
        int idx = 0;
        while (idx < arr.length) {
            if (!map.containsKey(arr[idx])) {
                return false;
            }
            int[] p = map.get(arr[idx]);
            for (int num : p) {
                if (arr[idx++] != num) {
                    return false;
                }
            }
        }
        return true;
    }
}