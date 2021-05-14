/*
 * @Descroption: LeetCode 73. ��������
 * @Author: EmoryHuang
 * @Date:  2021-03-21 19:30:36
 * @����˼·:
 * ����һ���ռ临�Ӷ� O(mn)
 * �ռ临�Ӷ� O(mn)�ķ����������뵽�������ٽ������������Ԫ�ؽ��б�ǣ�
 * ���ĳ��Ԫ��Ϊ `0`����ô�ͽ���Ԫ�����ڵ��к�������Ӧ��������λ����Ϊ `true`
 *
 * ���������ռ临�Ӷ� O(1)
 * �þ���ĵ�һ�к͵�һ�д��淽��һ�е�����������飬�������ᵼ��ԭ����ĵ�һ�к͵�һ�б��޸ģ�
 * ���ʹ��������Ǳ������ֱ��¼��һ�к͵�һ���Ƿ�ԭ������ `0`
 */

class Solution {
   public:
    // ����һ���ռ临�Ӷ�O(mn)
    // void setZeroes(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     vector<bool> row(m), col(n);
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (!matrix[i][j]) {
    //                 row[i] = col[j] = true;
    //             }
    //         }
    //     }
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (row[i] || col[j]) {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }

    // ���������ռ临�Ӷ�O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool flagRow = false, flagCol = false;
        //�жϵ�һ���Ƿ���0
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                flagCol = true;
                break;
            }
        }
        //�жϵ�һ���Ƿ���0
        for (int i = 0; i < n; i++) {
            if (!matrix[0][i]) {
                flagRow = true;
                break;
            }
        }
        // �������˵�һ�е�һ�е�Ԫ�أ���Ϊ0�����ö�Ӧ��һ�е�һ�е�Ԫ��Ϊ0
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        // ������һ�е�һ�е�Ԫ�أ���Ϊ0��������������Ϊ0
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[0][j] || !matrix[i][0]) {
                    matrix[i][j] = 0;
                }
            }
        }
        //����һ����0
        if (flagRow) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
        //����һ����0
        if (flagCol) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};