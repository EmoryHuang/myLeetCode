/*
 * @Descroption: LeetCode 502. IPO
 * @Author: EmoryHuang
 * @Date: 2021-09-08 15:17:42
 * @Method:
 * ��
 * ����ʱ�ʱ�����ǲ���Ҫ��ȥ�����ʽ�ֻ��Ҫ���Ǵ�����
 * ����˼���������ģ����ȣ����ǰ������ʽ��С�����������
 * ����ѡ��k����Ŀ����ѡ����Ŀʱ�������е������ʽ𲻳��� w ����Ŀ�������ȶ���
 * ѡ�����������Ǹ���Ŀ����
 */

class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> p;
        // �������ʽ��С�����������
        for (int i = 0; i < n; i++) p.push_back({capital[i], profits[i]});
        sort(p.begin(), p.end());
        priority_queue<int> heap;
        int i = 0;
        while (k--) {
            // �����е������ʽ𲻳��� w ������������ȶ���
            while (i < n && p[i].first <= w) {
                heap.push(p[i++].second);
            }
            if (heap.empty()) break;  // ����Ϊ��
            // �Ӷ�����ѡ������������Ŀ
            w += heap.top();
            heap.pop();
        }
        return w;
    }
};