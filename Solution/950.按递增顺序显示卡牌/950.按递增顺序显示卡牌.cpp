/*
 * @Descroption: LeetCode 950. ������˳����ʾ����
 * @Author: EmoryHuang
 * @Date: 2021-06-04 14:40:00
 * @����˼·:
 * ����ģ��ķ�����������Ŀ�����ǵĹ��򣬿��Ե���˼��
 * �Ӵ�С�Կ��ƽ�������
 * ���Ƚ����Ľڵ���뿨�ѣ���ʱ����ֻ��һ���ƣ���Ȼ�󽫿��ѵײ����Ʒŵ�����
 * Ȼ�����ڿ��ѵĶ���������һ����
 * �������ڰ�����Ŀ������е�ʱ�����ǾͿ��Եõ�����˳��Ŀ���
 */

class Solution {
   public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> q;
        q.push_back(deck.back());  // ���Ľڵ�
        for (int i = n - 2; i >= 0; i--) {
            q.push_front(q.back());  // ��βԪ�طŵ���ͷ
            q.pop_back();
            q.push_front(deck[i]);  // ������һ��Ԫ��
        }
        vector<int> ans(q.begin(), q.end());
        return ans;
    }
};