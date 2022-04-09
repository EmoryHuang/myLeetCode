/*
 * @Descroption: LeetCode 780. �����յ�
 * @Author: EmoryHuang
 * @Date: 2022-04-09 08:58:23
 * @Method:
 * ���յ㷴����������
 * ת���Ǵӵ� (x, y) ת���� (x, x+y) ���� (x+y, y)
 * �������ʱ, ÿ��ʹ�� tx, ty �еĽϴ�ֵ��ȥ��Сֵ, ʹ�ò��ϱƽ����
 *
 * Ϊ�˿��ٱƽ�, ����ÿ�ν��ϴ�ֵһ���Լ�ȥ�౶�Ľ�Сֵ, �Ӷ����ٵ�������
 */

class Solution {
   public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > 0 && ty > 0) {
            if (sx == tx && sy == ty) return true;
            if (tx > ty) {
                tx -= ty * max((tx - sx) / ty, 1);
            } else {
                ty -= tx * max((ty - sy) / tx, 1);
            }
        }
        return false;
    }
};