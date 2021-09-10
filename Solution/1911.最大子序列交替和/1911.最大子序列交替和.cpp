/*
 * @Descroption: LeetCode 1911. ��������н����
 * @Author: EmoryHuang
 * @Date: 2021-07-22 15:10:33
 * @����˼·:
 * ��̬�滮
 * odd[i],even[i]�ֱ����ǰi��������������У����һ��Ԫ�ص��±�Ϊ����/ż��
 * ѡ��/��ѡ��ǰԪ��
 * ��odd��˵��ǰһ��ѡ���Ԫ���±���ż����
 * ����even��˵��ǰһ��ѡ���Ԫ���±���������
 * odd[i] = max(even[i - 1] - nums[i], odd[i - 1])
 * even[i] = max(odd[i - 1] + nums[i], even[i - 1])
 */

class Solution {
   public:
    // long long maxAlternatingSum(vector<int>& nums) {
    //     int n = nums.size();
    //     // odd[i],even[i]�ֱ����ǰi��������������У����һ��Ԫ�ص��±�Ϊ����/ż��
    //     vector<long long> odd(n), even(n);
    //     odd[0] = 0;
    //     even[0] = nums[0];
    //     for (int i = 1; i < n; i++) {
    //         // ѡ��/��ѡ��ǰԪ��
    //         // ��odd��˵��ǰһ��ѡ���Ԫ���±���ż����
    //         // ����even��˵��ǰһ��ѡ���Ԫ���±���������
    //         odd[i] = max(even[i - 1] - nums[i], odd[i - 1]);
    //         even[i] = max(odd[i - 1] + nums[i], even[i - 1]);
    //     }
    //     return max(odd[n - 1], even[n - 1]);
    // }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long odd = 0, even = nums[0];
        for (int i = 1; i < n; i++) {
            odd = max(even - nums[i], odd);
            even = max(odd + nums[i], even);
        }
        return even;
    }
};