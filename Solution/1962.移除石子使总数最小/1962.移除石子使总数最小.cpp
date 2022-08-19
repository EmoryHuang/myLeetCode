/*
 * @Descroption: LeetCode 1962. �Ƴ�ʯ��ʹ������С
 * @Author: EmoryHuang
 * @Date: 2021-10-21 09:20:05
 * @Method:
 * �����
 * ά��һ������ѣ�ȡ�Ѷ�Ԫ�� / 2 ����ѣ��������Ԫ��֮��
 */

class Solution {
   public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap(piles.begin(), piles.end());
        while (k--) {
            int cur = heap.top();
            heap.pop();
            heap.push((cur + 1) >> 1);
        }
        int ans = 0;
        while (!heap.empty()) {
            ans += heap.top();
            heap.pop();
        }
        return ans;
    }
};