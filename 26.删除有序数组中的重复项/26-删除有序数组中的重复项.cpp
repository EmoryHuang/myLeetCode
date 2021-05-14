/*
 * @Descroption: LeetCode 26. ɾ�����������е��ظ���
 * @Author: EmoryHuang
 * @Date: 2021-03-19 19:31:36
 * @����˼·: ����ֻ��Ҫ���ǰ len �����ظ���Ԫ�أ����԰Ѳ��ظ���Ԫ��������ǰ��
 * ��������ָ�� `i`��`j`��`i` Ϊ��ָ�룬`j` Ϊ��ָ�룬�Ƚ� `nums[i]` �� `nums[j]`
 * �������ָ�� `i` ���ƣ�������һ�αȽ�
 * ����ָ�� `j` ���ƣ��� `i` λ�õ�Ԫ�طŵ� `j` λ���ϣ�Ȼ��ָ�� `i` �ٺ���
 */

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int len = 0;  //��ǰ����
        for (int i = 1; i < nums.size(); i++) {
            if (nums[len] != nums[i]) {
                nums[++len] = nums[i];  //������ȵ��ַ��ŵ�ǰ��
            }
        }
        return ++len;
    }
};