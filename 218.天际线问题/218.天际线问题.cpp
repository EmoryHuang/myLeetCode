/*
 * @Descroption: LeetCode 218. ���������
 * @Author: EmoryHuang
 * @Date: 2021-07-13 20:09:14
 * @����˼·:
 * ά��һ������ѣ��������ж˵�
 * �������˵㣬����߶ȼ�������
 * ������Ҷ˵㣬����߶��Ƴ������
 * ÿ��ȡ��ǰ���ֵ����һ�����ֵ�Ƚ�
 */

class Solution {
   public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<vector<int>> points;
        // Ϊ�˷������򣬶�����˵㣬��߶�Ϊ���������Ҷ˵���߶�Ϊ��
        for (auto bulid : buildings) {
            int l = bulid[0], r = bulid[1], h = bulid[2];
            points.push_back({l, -h});
            points.push_back({r, h});
        }
        // ���պ������������
        // �����������ͬ��������˵�����
        // �����ͬ����/�Ҷ˵㣬���ո߶Ƚ�������
        sort(points.begin(), points.end());
        multiset<int> heap;
        int pre = 0;
        heap.insert(pre);
        // �������ж˵�
        for (auto point : points) {
            int p = point[0], h = point[1];
            if (h < 0)
                heap.insert(-h);  // �������˵㣬���������
            else
                heap.erase(heap.find(h));  // ������Ҷ˵㣬���Ƴ������
            ;
            int cur = *heap.rbegin();  // ȡ��ǰ���ֵ�Ƚ�
            if (cur != pre) {
                ans.push_back({p, cur});
                pre = cur;
            }
        }
        return ans;
    }
};