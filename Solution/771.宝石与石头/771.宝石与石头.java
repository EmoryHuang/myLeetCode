/*
 * @Descroption: LeetCode 771. 宝石与石头
 * @Author: EmoryHuang
 * @Date: 2023-07-24 09:24:04
 * @Method:
 * 哈希表
 */

import java.util.*;

class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        Set<Character> hash = new HashSet<>();
        for (char ch : jewels.toCharArray()) {
            hash.add(ch);
        }
        int ans = 0;
        for (char ch : stones.toCharArray()) {
            if (hash.contains(ch)) {
                ans++;
            }
        }
        return ans;
    }
}