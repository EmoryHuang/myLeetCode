/*
 * @Descroption: ��ָ Offer 33. �����������ĺ����������
 * @Author: EmoryHuang
 * @Date: 2021-11-11 19:56:55
 * @Method:
 * ����ջ
 * ά��һ������ѣ�ֻҪջ��Ԫ�ػ��ȵ�ǰ�ڵ�󣬾ͱ�ʾ������������Ҫ�Ƴ�
 * ֱ��ջ��Ԫ��С�ڽڵ㣬����ջΪ��
 * ��������ÿ���ڵ㣬��Ҫ�������ĸ�ҪС
 */

class Solution {
   public:
    bool verifyPostorder(vector<int>& postorder) {
        priority_queue<int> heap;
        int pre = INT_MAX;
        // �������
        for (int i = postorder.size() - 1; i >= 0; i--) {
            // ������Ԫ�ؽ�С
            if (postorder[i] > pre) return false;
            // ά��һ�������
            // ֻҪջ��Ԫ�ػ��ȵ�ǰ�ڵ�󣬾ͱ�ʾ������������Ҫ�Ƴ�
            // ջ������һ��Ԫ�ؾ��������ڵ�ĸ�
            while (!heap.empty() && postorder[i] < heap.top()) {
                pre = heap.top();
                heap.pop();
            }
            heap.push(postorder[i]);
        }
        return true;
    }
};