/*
 * @Descroption: LeetCode 1705. ��ƻ���������Ŀ
 * @Author: EmoryHuang
 * @Date: 2021-12-24 09:16:57
 * @Method:
 * ģ�� + ���ȶ���
 * ά��һ��С���ѣ��ֱ�洢ÿ���ժ��Ϣ (days[i] + pickday, apples[i])
 * ÿ��Ҫ��ƻ��ʱ��ȡ�Ѷ�Ԫ�أ�ֱ���Ѷ���ƻ�����Ǹ��õ�
 * ����󣬸��µ� pickday ���ƻ������
 * */

class Solution {
   public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans = 0, i = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        while (heap.size() > 0 || i < apples.size()) {
            bool eat = false;
            // ά��һ��С���ѣ��ֱ�洢ÿ���ժ��Ϣ (days[i] + pickday, apples[i])
            if (i < apples.size() && apples[i] != 0) heap.push({days[i] + i, apples[i]});
            while (heap.size() > 0 && !eat) {
                // ȡ�Ѷ�Ԫ�أ�ֱ���Ѷ���ƻ�����Ǹ��õ�
                auto [day, apple] = heap.top();
                heap.pop();
                if (i >= day) continue;
                ans++;
                eat = true;
                // ���µ� pick ���ƻ������
                if (apple - 1 > 0) heap.push({day, apple - 1});
            }
            i++;
        }
        return ans;
    }
};