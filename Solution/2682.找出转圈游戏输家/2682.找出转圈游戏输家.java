/*
 * @Description: LeetCode 2682. 找出转圈游戏输家
 * @Author: EmoryHuang
 * @Date: 2023-08-16 09:22:50
 * @解题思路:
 * 模拟
 */

import java.util.*;

class Solution {
    public int[] circularGameLosers(int n, int k) {
        boolean[] visit = new boolean[n];
        for (int i = k, j = 0; !visit[j]; i += k) {
            visit[j] = true;
            j = (j + i) % n;
        }
        List<Integer> list = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                list.add(i + 1);
            }
        }
        int[] ans = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            ans[i] = list.get(i);
        }
        return ans;
    }
}