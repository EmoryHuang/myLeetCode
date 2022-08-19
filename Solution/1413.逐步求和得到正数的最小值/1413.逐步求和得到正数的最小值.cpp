/*
 * @Descroption: LeetCode 1413. ����͵õ���������Сֵ
 * @Author: EmoryHuang
 * @Date: 2021-06-05 15:13:00
 * @����˼·:
 * �ҵ������������ۻ�����С��sum������Ҫ�����С����Ϊ 1 - sum
 */

class Solution {
   public:
    int minStartValue(vector<int>& nums) {
        int ans = 0, sum = 0;
        for (int num : nums) {
            sum += num;
            ans = min(ans, sum);
        }
        return 1 - ans;
    }
};