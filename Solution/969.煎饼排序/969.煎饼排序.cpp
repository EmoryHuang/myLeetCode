/*
 * @Descroption: LeetCode 969. �������
 * @Author: EmoryHuang
 * @Date: 2022-02-19 09:13:18
 * @Method:
 * ���� arr �� 1 �� n �����У���˿���ÿ������ȷ��һ�����ֵ
 * �Ӻ���ǰö��ÿ��λ����Ҫ��Ԫ��
 * �ҵ���ǰ��Ҫ��Ԫ���� arr �е�λ�� idx
 * ����Ҫ��Ԫ�ز��ڵ�һ��λ�ã����ȷ�ת [0, idx]���������Ա�֤��һ��λ������Ҫ��Ԫ��
 * ����Ҫ��Ԫ���ڵ�һ��λ�ã���ֱ�ӷ�ת [0, i - 1]
 */

class Solution {
   public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        // �Ӻ���ǰö��ÿ��λ����Ҫ��Ԫ��
        for (int i = n; i > 0; i--) {
            // �ҵ���ǰ��Ҫ��Ԫ���� arr �е�λ�� idx
            int idx = find(arr.begin(), arr.begin() + i, i) - arr.begin();
            // ��λ�ò���Ҫ�ı�
            if (idx == i - 1) continue;
            if (idx != 0) {
                // ����Ҫ��Ԫ�ز��ڵ�һ��λ�ã����ȷ�ת [0, idx]���������Ա�֤��һ��λ������Ҫ��Ԫ��
                ans.push_back(idx + 1);
                reverse(arr.begin(), arr.begin() + idx + 1);
            }
            // ����Ҫ��Ԫ���ڵ�һ��λ�ã���ֱ�ӷ�ת [0, i - 1]
            ans.push_back(i);
            reverse(arr.begin(), arr.begin() + i);
        }
        return ans;
    }
};