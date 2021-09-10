/*
 * @Descroption: LeetCode 1723. ������й��������ʱ��
 * @Author: EmoryHuang
 * @Date: 2021-05-08 20:28:36
 * @����˼·:
 * ���� + ��֦
 * ���û��ݵķ�����`work[i]` Ϊ�� `i` �����˵ĵ�ǰ����ʱ�䣬
 * ����һ���ݹ麯�� `backtrack(i)` �ݹ��ö�ٵ� `i` ������ķ��䷽����������ʵʱ�ظ��� `work` ����
 * ��֦��
 * - ����� `i` �������Ѿ������Ĺ���ʱ�� `work[i]` + ��ǰ������Ҫ��ʱ�� `jobs[num]`
 * ������֮ǰ�ҵ�����С�����ʱ�䣬��ô��������� `i` ������
 * - �����ǰ����δ�����乤������ô��һ������Ҳ��Ȼδ�����乤��
 * - �����ǰ����ǡʹ�ù��˵Ĺ������ﵽ�����ޣ���ô������
 */

class Solution {
   public:
    int ans = INT_MAX;
    // work[i]Ϊ��i�����˵ĵ�ǰ����ʱ��
    // numΪ��ǰ�������
    // maxTimeΪ���ǰnum�������������ʱ��
    void backtrack(vector<int>& jobs, int num, vector<int>& work, int maxTime) {
        if (num == jobs.size()) {     // ����ȫ�����
            ans = min(ans, maxTime);  //��������С�����ʱ��
            return;
        }
        for (int i = 0; i < work.size(); i++) {
            if (work[i] + jobs[num] > ans) continue;  // �������ʱ��
            work[i] += jobs[num];
            backtrack(jobs, num + 1, work, max(maxTime, work[i]));  //����
            work[i] -= jobs[num];                                   //����ѡ��
            // �����ǰ����δ�����乤������ô��һ������Ҳ��Ȼδ�����乤��
            // ���ߵ�ǰ����ǡ��ʹ�ù��˵Ĺ������ﵽ������
            if (work[i] == 0 || work[i] + jobs[num] == maxTime) break;
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> work(k);
        backtrack(jobs, 0, work, 0);
        return ans;
    }
};