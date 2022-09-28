/*
 * @Descroption: LeetCode 1624. 两个相同字符之间的最长子字符串
 * @Author: EmoryHuang
 * @Date: 2022-09-17 09:27:10
 * @Method:
 * 使用哈希表记录元素第一次出现的位置
 * 若再次出现则计算中间字符长度
 */

class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int ans = -1;
        Map<Character, Integer> hash = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (hash.containsKey(c))
                ans = Math.max(ans, i - hash.get(c) - 1);
            else
                hash.put(c, i);
        }
        return ans;
    }
}