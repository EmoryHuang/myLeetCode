/*
 * @Descroption: LeetCode 1894. 找到需要补充粉笔的学生编号
 * @Author: EmoryHuang
 * @Date: 2021-09-10 14:54:25
 * @Method:
 * 数学
 * 求和，取余，找到n轮后剩下的数量，然后再遍历一次，找到需要补充的位置
 */

class Solution {
   public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for (int num : chalk) sum += num;
        int cnt = k % sum;
        for (int i = 0; i < chalk.size(); i++) {
            if (cnt < chalk[i]) return i;
            cnt -= chalk[i];
        }
        return -1;
    }
};
