/*
 * @Descroption: LeetCode 153. Ѱ����ת���������е���Сֵ
 * @Author: EmoryHuang
 * @Date: 2021-04-08 18:45:36
 * @����˼·: ���ַ����ؼ�����һЩϸ��
 * �����йض��ֲ��ҵ�̽�����Կ���[���ֲ���ѧϰ�ʼ�](https://emoryhuang.github.io/blog/158595231.html)
 */

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= nums.back())
                right = mid;
            else
                left = mid + 1;
        }
        return nums[left];
    }
};