/*
 * @Descroption: LeetCode 1601. ���ɴ�ɵĻ�¥������Ŀ
 * @Author: EmoryHuang
 * @Date: 2022-02-28 09:22:08
 * @Method:
 * ������ö��
 * ʹ�ö�����λ��¼ѡ��¥������������л�¥����
 * ͳ�ƶ��������� 1 �ĸ��������жϵ�ǰ state �Ƿ�������㻻¥����
 */

class Solution {
   public:
    vector<vector<int>> req;
    int count1(int state) {
        int res = 0;
        while (state) {
            res += state & 1;
            state >>= 1;
        }
        return res;
    }
    bool check(int state) {
        vector<int> cnt(20);
        for (int i = 0; i < req.size(); i++) {
            if ((state >> i) & 1) {
                cnt[req[i][0]]++;
                cnt[req[i][1]]--;
            }
        }
        bool flag = true;
        for (auto c : cnt)
            if (c != 0) {
                flag = false;
                break;
            }
        return flag;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0, m = requests.size();
        req = requests;
        // �������л�¥����
        for (int state = 0; state < (1 << m); state++) {
            // ͳ�ƶ��������� 1 �ĸ���
            int cnt = count1(state);
            if (cnt <= ans) continue;
            // �жϵ�ǰ���Ƿ�������㻻¥����
            if (check(state)) ans = max(ans, cnt);
        }
        return ans;
    }
};