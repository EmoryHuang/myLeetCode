/*
 * @Descroption: LeetCode 1636. 按照频率将数组升序排序
 * @Author: EmoryHuang
 * @Date: 2022-09-19 09:29:55
 * @Method:
 * 使用哈希表记录元素数量，之后再排序
 */


class Solution {
    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> hash = new HashMap<Integer, Integer>();
        for (int num : nums)
            hash.put(num, hash.getOrDefault(num, 0) + 1);
        List<Integer> list = new ArrayList<Integer>();
        for (int num : nums)
            list.add(num);
        Collections.sort(list, (a, b) -> {
            int x = hash.get(a), y = hash.get(b);
            return x != y ? x - y : b - a;
        });
        for (int i = 0; i < list.size(); i++)
            nums[i] = list.get(i);
        return nums;
    }
}