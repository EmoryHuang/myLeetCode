/*
 * @Descroption: LeetCode 167. ����֮�� II - ������������
 * @Author: EmoryHuang
 * @Date: 2021-04-20 16:10:36
 * @����˼·: ������������ָ�룬�жϴ�С�����ƶ���������Ŀ��ֵ�򷵻��±�
 */

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target)
                return {left + 1, right + 1};
            else if (numbers[left] + numbers[right] > target)
                right--;
            else
                left++;
        }
        return {};
    }
};