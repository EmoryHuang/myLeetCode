/*
 * @Descroption: LeetCode 915. 分割数组
 * @Author: EmoryHuang
 * @Date: 2022-10-24 09:41:35
 * @Method:
 * 因为题目保证有划分，那么可以设置两个值，左侧最大值和全局最大值，找到第一个比左侧数字都大的值
 */

class Solution {
    public int partitionDisjoint(int[] nums) {
        int max = nums[0], maxLeft = nums[0];
        int pos = 0;
        for (int i = 0; i < nums.length; i++){
            max = Math.max(max, nums[i]);
            // 找到第一个比左侧数字都大的值
            if (maxLeft > nums[i]){
                maxLeft = max;
                pos = i;
            }
        }
        return pos + 1;
    }
}