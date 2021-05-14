/*
 * @Descroption: LeetCode 35. ��������λ��
 * @Author: EmoryHuang
 * @Date: 2021-03-22 17:02:36
 * @����˼·: ���⣬˼·ûʲô��˵�ģ�ֱ�ӱ�������Ҳ���ԣ����ֲ���Ҳ����
 * �����йض��ֲ��ҵ�̽�����Կ���[���ֲ���ѧϰ�ʼ�](https://emoryhuang.github.io/blog/158595231.html)
 */

class Solution {
   public:
    // ����һ����������
    // int searchInsert(vector<int>& nums, int target) {
    //     for (int i = 0; i < nums.length; i++) {
    //         if (nums[i] >= target) {
    //             return i;
    //         }
    //     }
    //     return nums.length;
    // }

    // ������������
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0 || nums.back() < target) return nums.size();
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};