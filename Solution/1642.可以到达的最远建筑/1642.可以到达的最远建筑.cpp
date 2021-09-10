/*
 * @Descroption: LeetCode 1642. ���Ե������Զ����
 * @Author: EmoryHuang
 * @Date: 2021-07-24 14:41:33
 * @����˼·:
 * ά��һ����С��
 * ��gap������С�ѣ����Ƚ��������ڼ�����ĵط���С�������ש��
 * ���ש��ĸ���С��0ʱ����
 */

class Solution {
   public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> heap;
        int n = heights.size();
        for (int i = 1; i < n; i++) {
            int gap = heights[i] - heights[i - 1];
            // ֻ�����ϲ���Ҫ�õ�����
            if (gap > 0) {
                // ��gap������С��
                heap.push(gap);
                // ���Ƚ��������ڼ�����ĵط�
                if (heap.size() > ladders) {
                    // С�������ש��
                    bricks -= heap.top();
                    heap.pop();
                    // ש��ĸ���С��0ʱ����
                    if (bricks < 0) return i - 1;
                }
            }
        }
        return n - 1;
    }
};