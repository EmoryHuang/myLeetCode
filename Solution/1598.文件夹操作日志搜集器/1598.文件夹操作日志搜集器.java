/*
 * @Descroption: LeetCode 1598. 文件夹操作日志搜集器
 * @Author: EmoryHuang
 * @Date: 2022-09-09 09:40:03
 * @Method:
 * 若 log == './' 不进行操作
 * 若 log == '../ 则 cnt - 1
 * 否则 cnt + 1
 */


class Solution {
    public int minOperations(String[] logs) {
        int ans = 0;
        for (String log : logs) {
            if (log.equals("./"))
                ;
            else if (log.equals("../"))
                ans = Math.max(0, ans - 1);
            else
                ans++;
        }
        return ans;
    }
}