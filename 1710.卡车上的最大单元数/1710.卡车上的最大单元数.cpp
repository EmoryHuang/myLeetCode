/*
 * @Descroption: LeetCode 1710. �����ϵ����Ԫ��
 * @Author: EmoryHuang
 * @Date: 2021-05-19 19:50:31
 * @����˼·:
 * ̰��˼�룬�ӿ���װ�����Ԫ�����ӿ�ʼ����
 */

class Solution {
   public:
    static bool cmp(vector<int> a, vector<int> b) { return a[1] > b[1]; }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);  // ����Ԫ������
        int ans = 0;
        for (auto box : boxTypes) {
            if (box[0] <= truckSize) {
                truckSize -= box[0];
                ans += box[0] * box[1];
            } else {  // ����truckSize����
                ans += truckSize * box[1];
                break;
            }
        }
        return ans;
    }
};