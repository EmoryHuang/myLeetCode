/*
 * @Descroption: LeetCode 169. ����Ԫ��
 * @Author: EmoryHuang
 * @Date: 2021-07-11 14:37:43
 * @����˼·:
 * ����һ����ϣ��
 * ʹ��һ����ϣ���¼Ԫ�ص�����
 * ��������Ħ��ͶƱ
 * Ħ��ͶƱ��ÿ�ν�������ͬ��Ԫ�ؽ��С�����������������Ԫ��ʣ�࣬�򡸿��ܡ�ΪԪ�ظ�����������һ����Ǹ�
 * ֮���ٽ���һ�α����������������ܡ�����ҪԪ�� x �ĳ��ִ����Ƿ񳬹�����һ��
 */

class Solution {
   public:
    // ����һ����ϣ��
    // int majorityElement(vector<int>& nums) {
    //     map<int, int> hash;
    //     for (int num : nums) {
    //         hash[num]++;
    //         if (hash[num] > nums.size() / 2) return num;
    //     }
    //     return 0;
    // }

    // ��������Ħ��ͶƱ
    int majorityElement(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) ans = nums[i];
            if (ans == nums[i])
                cnt++;
            else
                cnt--;
        }
        cnt = 0;
        for (int num : nums)
            if (num == ans) cnt++;
        return cnt > nums.size() / 2 ? ans : 0;
    }
};