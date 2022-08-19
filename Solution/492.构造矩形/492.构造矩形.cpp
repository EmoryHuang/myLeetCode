/*
 * @Descroption: LeetCode 492. �������
 * @Author: EmoryHuang
 * @Date: 2021-04-24 14:17:36
 * @����˼·:
 * ������ sqrt ������֮��Ѱ����ӽ�������� area �����ӣ����ɵõ������
 */

class Solution {
   public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        while (area % w != 0) w--;
        return {area / w, w};
    }
};