/*
 * @Descroption: LeetCode 59. �������� II
 * @Author: EmoryHuang
 * @Date: 2021-03-23 16:06:36
 * @����˼·:
 * ��[��������]�ķ���������ͬ��ģ�����������·������ʼλ���Ǿ�������Ͻǣ���ʼ���������ң���·���������ޣ�˳ʱ����ת��������һ������
 */

class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int top = 0, bottom = n - 1, right = n - 1, left = 0;
        int num = 1;
        while (num <= n * n) {
            for (int i = left; i <= right; i++) ans[top][i] = num++;     //������
            top++;                                                       //��������
            for (int i = top; i <= bottom; i++) ans[i][right] = num++;   //���ϵ���
            right--;                                                     //�Ҳ�����
            for (int i = right; i >= left; i--) ans[bottom][i] = num++;  //���ҵ���
            bottom--;                                                    //�ײ�����
            for (int i = bottom; i >= top; i--) ans[i][left] = num++;    //���µ���
            left++;                                                      //������
        }
        return ans;
    }
};