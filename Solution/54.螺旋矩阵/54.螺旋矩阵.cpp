/*
 * @Descroption: LeetCode 54. ��������
 * @Author: EmoryHuang
 * @Date: 2021-03-23 13:16:36
 * @����˼·:
 * ģ�����������·������ʼλ���Ǿ�������Ͻǣ���ʼ���������ң���·���������ޣ�˳ʱ����ת��������һ������
 */

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        if (m == 0 || n == 0) return ans;
        int top = 0, bottom = m - 1, right = n - 1, left = 0;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) ans.push_back(matrix[top][i]);    //������
            top++;                                                                //��������
            for (int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);  //���ϵ���
            right--;                                                              //�Ҳ�����
            for (int i = right; i >= left && top <= bottom; i--)
                ans.push_back(matrix[bottom][i]);  //���ҵ���
            bottom--;                              //�ײ�����
            for (int i = bottom; i >= top && left <= right; i--)
                ans.push_back(matrix[i][left]);  //���µ���
            left++;                              //������
        }
        return ans;
    }
};