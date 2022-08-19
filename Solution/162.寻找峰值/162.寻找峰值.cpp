/*
 * @Descroption: LeetCode 162. Ѱ�ҷ�ֵ
 * @Author: EmoryHuang
 * @Date: 2021-05-10 18:17:36
 * @����˼·: ����˼��
 * �� mid ǡ��λ�ڽ������л���һ���ֲ��½��¶��У���˵����ֵ���ڱ�Ԫ�ص���ߡ�
 * �� mid ǡ��λ���������л���һ���ֲ������¶��У���˵����ֵ���ڱ�Ԫ�ص��ұߡ�
 * �����йض��ֲ��ҵ�̽�����Կ���[���ֲ���ѧϰ�ʼ�](https://emoryhuang.github.io/blog/158595231.html)
 */

class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};