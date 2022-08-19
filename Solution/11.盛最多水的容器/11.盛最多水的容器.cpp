/*
 * @Descroption: LeetCode 11. ʢ���ˮ������
 * @Author: EmoryHuang
 * @Date: 2021-03-19 14:22:36
 * @����˼·: �տ�ʼֱ�ӱ���Ӳ�գ�Ȼ��ͳ�ʱ�ˣ�ʹ��˫ָ�뷽������ʵ��Ҫ�����ƶ��ĸ���˼·
 *      �����ȱ�С����ô������֮ǰ�ĸ���Ψһ�Ŀ�������̵Ķ̰��֮ǰҪ�ߡ�
 *      ���Ը��ߵ�ľ��û��Ҫ�ƶ���ֻ��Ҫ�ƶ��϶̵��Ǹ���
 */

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int maxv = 0, v;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            v = min(height[i], height[j]) * (j - i);  //���
            maxv = max(maxv, v);
            if (height[i] < height[j])  //�ƶ��϶̵��Ǹ���
                i++;
            else
                j--;
        }
        return maxv;
    }
};