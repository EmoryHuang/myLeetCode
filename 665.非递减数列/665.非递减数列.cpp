/*
 * @Descroption: LeetCode 665. �ǵݼ�����
 * @Author: EmoryHuang
 * @Date: 2021-03-19 15:19:36
 * @����˼·:
 * ������� `nums[i] > nums[i+1]` ��������ı�һ��������������ѡ��
 * һ�ǰ� `nums[i]` ��󣬶��ǰ� `nums[i+1]` ��С
 * ��ͬʱ����Ҫ�Ƚ� `nums[i-1]` �� `nums[i+1]` ��ֵ
 * ���� `... 1 4 3 ...` ֻ��ѡ��� 4 ��С�� `... 3 4 1 ...` ֻ��ѡ��� 1 ���(����`nums[i]=4`)
 */

class Solution {
   public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size(), count = 0;
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] > nums[i + 1]) {                   //����������
                if (i == 0 || nums[i + 1] >= nums[i - 1])  //���ǿ�ͷ������Լ���i���ַ���ǰ���С
                    nums[i] = nums[i + 1];  // nums[i]���
                else
                    nums[i + 1] = nums[i];  // nums[i-1]��С
                count++;
            }
        }
        return count < 2;
    }
};