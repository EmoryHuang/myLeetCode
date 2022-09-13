/*
 * @Descroption: LeetCode 658. 找到 K 个最接近的元素
 * @Author: EmoryHuang
 * @Date: 2022-08-25 19:45:15
 * @Method:
 * 按最接近x的元素进行排序
 */


class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> list = new ArrayList<Integer>();
        for (int num : arr)
            list.add(num);
        Collections.sort(list, (a, b) -> {
            if (Math.abs(a - x) != Math.abs(b - x)) {
                return Math.abs(a - x) - Math.abs(b - x);
            } else {
                return a - b;
            }
        });
        List<Integer> ans = list.subList(0, k);
        Collections.sort(ans);
        return ans;
    }
}