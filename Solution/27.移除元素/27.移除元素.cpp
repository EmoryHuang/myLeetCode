/*
 * @Descroption: LeetCode 27. �Ƴ�Ԫ��
 * @Author: EmoryHuang
 * @Date: 2021-03-19 19:31:36
 * @����˼·: ��ǰһ��(ɾ�����������е��ظ���)��˼�������ͬ
 * ����ֻ��Ҫ���ǰ len �����ظ���Ԫ�أ����԰Ѳ��ظ���Ԫ��������ǰ��
 * ��������ָ�� `i`��`j`��`i` Ϊ��ָ�룬`j` Ϊ��ָ�룬�Ƚ� `nums[i]` �� `val`
 * �������ָ�� `i` ���ƣ�������һ�αȽ�
 * ���򣬽� `i` λ�õ�Ԫ�طŵ� `j` λ���ϣ�Ȼ��ָ�� `i`,`j` �ٺ���
 */

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[len++] = nums[i];
            }
        }
        return len;
    }
};