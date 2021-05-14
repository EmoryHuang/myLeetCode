/*
 * @Descroption: LeetCode 33. ������ת��������
 * @Author: EmoryHuang
 * @Date: 2021-03-23 12:16:36
 * @����˼·: �տ�ʼ���Ǻܶ���Ŀ����ʲô��ֱ�ӱ�����һ��
 * �������Ƕ�����������������ת�����飬��˻���Ҫ�ж� mid ��λ��
 * �����йض��ֲ��ҵ�̽�����Կ���[���ֲ���ѧϰ�ʼ�](https://emoryhuang.github.io/blog/158595231.html)
 */

class Solution {
   public:
    // ����һ���������߶�ʮһ
    // int search(vector<int>& nums, int target) {
    //     for (int i = 0; i < nums.size(); i++)
    //         if (nums[i] == target) return i;
    //     return -1;
    // }

    // ������������
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        // Ѱ����ת�������Сֵ
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= nums.back())
                right = mid;
            else
                left = mid + 1;
        }
        // �ж� target ��������
        if (target <= nums.back())
            right = nums.size() - 1;
        else {
            left = 0;
            right--;
        }
        // Ѱ�� target
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        if (nums[left] != target) return -1;
        return left;
    }
};