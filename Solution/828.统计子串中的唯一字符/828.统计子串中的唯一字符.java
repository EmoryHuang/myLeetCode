/*
 * @Descroption: LeetCode 828. 统计子串中的唯一字符
 * @Author: EmoryHuang
 * @Date: 2022-09-06 09:45:30
 * @Method:
 * 使用哈希表记录每个字符出现的位置
 * 对于每个字符，计算它从上一次出现到下一次出现的位置
 * 共有(arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i])种可能
 */

class Solution {
    public int uniqueLetterString(String s) {
        Map<Character, List<Integer>> map = new HashMap<Character, List<Integer>>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (!map.containsKey(c)) {
                map.put(c, new ArrayList<Integer>());
                map.get(c).add(-1);
            }
            map.get(c).add(i);
        }
        int ans = 0;
        for (Map.Entry<Character, List<Integer>> e : map.entrySet()) {
            List<Integer> arr = e.getValue();
            arr.add(s.length());
            for (int i = 1; i < arr.size() - 1; i++) {
                ans += (arr.get(i) - arr.get(i - 1)) * (arr.get(i + 1) - arr.get(i));
            }
        }
        return ans;
    }
}