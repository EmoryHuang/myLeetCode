/*
 * @Descroption: LeetCode 74. ������ά����
 * @Author: EmoryHuang
 * @Date: 2021-03-24 15:30:36
 * @����˼·:
 * ����һ�����»����Ͽ�ʼ
 * �ڵ����Ķ�ά������Ѱ��Ԫ�أ�Ӧ�ú����׿����뵽������ڴ����ϻ������¿�ʼѰ�ң����»����Ͽ�ʼ��Ч�����Ը��ã�һ�ο����ų�һ��
 *
 * ������������
 * �����йض��ֲ��ҵ�̽�����Կ���[���ֲ���ѧϰ�ʼ�](https://emoryhuang.github.io/blog/158595231.html)
 */

class Solution {
   public:
    // ����һ�����»����Ͽ�ʼ
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     int i = m - 1, j = 0;
    //     while (i >= 0 && j < n) {
    //         if (matrix[i][j] == target)
    //             return true;
    //         else if (matrix[i][j] > target)
    //             i--;
    //         else
    //             j++;
    //     }
    //     return false;
    // }

    // ������������
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (target == matrix[mid / n][mid % n])
                return true;
            else if (target > matrix[mid / n][mid % n])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};