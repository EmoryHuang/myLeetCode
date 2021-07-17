/*
 * @Descroption: LeetCode 1276. ���˷�ԭ�ϵĺ�����������
 * @Author: EmoryHuang
 * @Date: 2021-07-17 15:37:16
 * @����˼·:
 * ����˵���������Ԫһ�η���
 * 4x + 2y = tomatoSlices
 * x + y = cheeseSlices
 */

class Solution {
   public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (tomatoSlices % 2 != 0 || tomatoSlices < cheeseSlices * 2 || cheeseSlices * 4 < tomatoSlices) {
            return {};
        }
        return {tomatoSlices / 2 - cheeseSlices, cheeseSlices * 2 - tomatoSlices / 2};
    }
};