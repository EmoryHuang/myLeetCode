/*
 * @Descroption: LeetCode 378. ��������е� K С��Ԫ��
 * @Author: EmoryHuang
 * @Date: 2021-04-23 15:52:36
 * @����˼·:
 * ���ô���ѵ����ʣ���Ԫ�ط������ѣ�������ѵ�Ԫ�ظ������� k���򵯳������ȡ�Ѷ�Ԫ��
 */

class Solution {
   public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;  // �����
        for (auto row : matrix) {
            for (auto num : row) {
                q.push(num);
                if (q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};