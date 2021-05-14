class Solution {
   public:
    int ans = INT_MAX;
    void backtrace(vector<int>& jobs, int num, vector<int>& work, int maxTime) {
        if (num == jobs.size()) {  // ����ȫ�����
            ans = min(ans, maxTime);
            return;
        }
        for (int i = 0; i < work.size(); i++) {
            if (work[i] + jobs[num] > ans) continue;  // �������ʱ��
            work[i] += jobs[num];
            backtrace(jobs, num + 1, work, max(maxTime, work[i]));
            work[i] -= jobs[num];  //����ѡ��
            // �����ǰ����δ�����乤������ô��һ������Ҳ��Ȼδ�����乤��
            // ���ߵ�ǰ����ǡ��ʹ�ù��˵Ĺ������ﵽ������
            if (work[i] == 0 || work[i] + jobs[num] == maxTime) break;
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> work(k);
        backtrace(jobs, 0, work, 0);
        return ans;
    }
};