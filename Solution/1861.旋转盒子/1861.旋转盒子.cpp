/*
 * @Descroption: LeetCode 1861. ��ת����
 * @Author: EmoryHuang
 * @Date: 2021-10-22 15:25:27
 * @Method:
 * ģ��
 * ����ʯͷ��ˮƽλ�ò��ᷢ���ı䣬��˿��Ա���ÿ�е�������
 * ����ÿ�У��Ӻ���ǰ���б��������Ҹ��µײ�λ�ã���ʯͷ���µ��ײ�
 */

class Solution {
   public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        for (int i = 0; i < m; i++) {
            // bottom ��¼�ײ�λ��
            int bottom = n;
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '*')
                    bottom = j;  // ����ǹ̶��ϰ������µײ�λ��
                else if (box[i][j] == '#') {
                    bottom -= 1;
                    swap(box[i][j], box[i][bottom]);
                }
            }
        }
        // ˳ʱ����ת 90 ��
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][m - i - 1] = box[i][j];
            }
        }
        return ans;
    }
};