/*
 * @Descroption: LeetCode 1401. Բ�;����Ƿ����ص�
 * @Author: EmoryHuang
 * @Date: 2021-06-05 14:40:00
 * @����˼·:
 * ��������, �ж�Բ�ĵ�λ�����ĸ�����
 */

class Solution {
   public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        // Բ���ھ�����
        if (x1 <= x_center && x_center <= x2 && y1 <= y_center && y_center <= y2) return true;
        // Բ���ھ��ε����������ĸ�����
        else if (y_center > y2 && x1 <= x_center && x_center <= x2)  //����
            return radius >= y_center - y2;
        else if (y_center < y1 && x1 <= x_center && x_center <= x2)
            return radius >= y1 - y_center;
        else if (x_center < x1 && y1 <= y_center && y_center <= y2)  //����
            return radius >= x1 - x_center;
        else if (x_center > x2 && y1 <= y_center && y_center <= y2)
            return radius >= x_center - x2;
        // ���ε��ĸ������Ƿ���Բ���ڲ�
        else {
            int a = pow((x1 - x_center), 2) + pow((y1 - y_center), 2);
            int b = pow((x1 - x_center), 2) + pow((y2 - y_center), 2);
            int c = pow((x2 - x_center), 2) + pow((y1 - y_center), 2);
            int d = pow((x2 - x_center), 2) + pow((y2 - y_center), 2);
            int r = pow(radius, 2);
            return (a <= r || b <= r || c <= r || d <= r);
        }
    }
};