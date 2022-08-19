/*
 * @Descroption: LeetCode 849. ��������˵�������
 * @Author: EmoryHuang
 * @Date: 2021-06-13 15:25:00
 * @����˼·:
 * Ѱ���������0����ͷβ�������⴦��
 */

class Solution {
   public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int start = -1, ans = 0;
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (start == -1)  // ��һ����
                    ans = i;
                else
                    ans = max(ans, (i - start) / 2);
                start = i;
            }
        }
        ans = max(n - start - 1, ans);  // ���һ����
        return ans;
    }
};