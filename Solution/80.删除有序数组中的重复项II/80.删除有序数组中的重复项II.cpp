/*
 * @Descroption: LeetCode 80. ɾ�����������е��ظ��� II
 * @Author: EmoryHuang
 * @Date: 2021-04-06 17:49:36
 * @����˼·: ����˼·��[ɾ�����������е��ظ���]��ͬ�����ÿ���ָ��
 * ���ǲ�ͬ���ǣ�ÿ��Ԫ�� ���������Σ�����ͨ������ `flag` �����ж��ظ���
 */

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int len = 0, flag = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[len] != nums[i]) {
                nums[++len] = nums[i];
                flag = 0;                                    // ���� flag
            } else if (nums[len] == nums[i] && flag == 0) {  // ��һ���ظ���
                nums[++len] = nums[i];
                flag++;
            }
        }
        return ++len;
    }
};