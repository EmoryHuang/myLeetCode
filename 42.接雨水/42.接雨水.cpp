/*
 * @Descroption: LeetCode 42. ����ˮ
 * @Author: EmoryHuang
 * @Date: 2021-04-02 18:08:36
 * @����˼·:
 * ����һ��ʹ��˫ָ�룬ֻҪ�ұ��б���߸ߵ����ӣ������м���ʲô�������ǰ�ܴ����ˮ��ֻ����ߵ�������أ���������ָ����������ߺ��ұ���ߣ�ֱ���ཻ
 * ���������������ȥ�����������ˮ����������������ָ����±��ֵ�����ÿһ����ˮ�����ӵ����
 */

class Solution {
   public:
    // ����һ��˫ָ��
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while (left <= right) {
            if (leftMax < rightMax) {  //���ұ߱���߸ߣ���ǰ�ܴ����ˮ��ֻ����ߵ��������
                ans += max(0, leftMax - height[left]);
                leftMax = max(leftMax, height[left]);  //�����������
                left++;
            } else {
                ans += max(0, rightMax - height[right]);
                rightMax = max(rightMax, height[right]);
                right--;
            }
        }
        return ans;
    }

    // �����������м������
    // int trap(vector<int>& height) {
    //     int left = 0, right = height.size() - 1;
    //     int high = 1;
    //     int sum = 0, v = 0;
    //     for (int i = 0; i < height.size(); i++) sum += height[i];
    //     while (left <= right) {
    //         while (left <= right && height[left] < high) left++;
    //         while (left <= right && height[right] < high) right--;
    //         v += right - left + 1;  //����ÿ������
    //         high++;
    //     }
    //     return v - sum;  //��ȥԭʼ���
    // }
};