/*
 * @Descroption: ������ 17.10. ��ҪԪ��
 * @Author: EmoryHuang
 * @Date: 2021-07-09 19:21:36
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
    //     return -1;
    // }

    // ��������Ħ��ͶƱ
    int majorityElement(vector<int>& nums) {
        int res = -1, cnt = 0;
        for (int num : nums) {
            if (cnt == 0) res = num;
            if (res == num)
                cnt++;
            else
                cnt--;
        }
        cnt = 0;
        for (int num : nums)
            if (num == res) cnt++;
        return cnt > nums.size() / 2 ? res : -1;
    }
};