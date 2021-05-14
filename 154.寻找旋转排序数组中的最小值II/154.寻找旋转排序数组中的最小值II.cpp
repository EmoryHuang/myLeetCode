/*
 * @Descroption: LeetCode 154. Ѱ����ת���������е���Сֵ II
 * @Author: EmoryHuang
 * @Date: 2021-04-08 19:01:36
 * @����˼·: ��[153. Ѱ����ת���������е���Сֵ]��ͬ�����ַ����ؼ����ڴ����ظ�ֵ
 * �����йض��ֲ��ҵ�̽�����Կ���[���ֲ���ѧϰ�ʼ�](https://emoryhuang.github.io/blog/158595231.html)
 */

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
                right = mid;
            else if (nums[mid] > nums[right])
                left = mid + 1;
            else  // nums[mid]����nums[right]ʱ
                right--;
        }
        return nums[left];
    }
};