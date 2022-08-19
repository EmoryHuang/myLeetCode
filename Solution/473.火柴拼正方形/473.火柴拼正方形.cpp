/*
 * @Descroption: LeetCode 473. ���ƴ������
 * @Author: EmoryHuang
 * @Date: 2021-05-08 21:18:36
 * @����˼·: ���� + ��֦
 * ���û��ݵķ�����`side[i]` Ϊ�� `i` �ߵĳ��ȣ�
 * ����һ���ݹ麯�� `backtrack(i)` �ݹ��ö�ٵ� `i` �����ķ��䷽����
 * ������ʵʱ�ظ��� `side` ����
 * ��֦��
 * - �����`i`�����г���`side[i]`+��ǰ��񳤶� `matchsticks[num]`������`target`����ô���������`i`��
 * - �����ǰ��û�л����ô��һ����Ҳ��Ȼû�л��
 * - �����ǰ��ǡ�ܴﵽ target����ô������
 */

class Solution {
   public:
    bool backtrack(vector<int>& matchsticks, int num, vector<int>& side, int target) {
        if (num == matchsticks.size())  // �������
            return side[0] == side[1] && side[0] == side[2] && side[0] == side[3];
        for (int i = 0; i < side.size(); i++) {
            if (side[i] + matchsticks[num] > target) continue;  // ���ȴ��� target
            // �ŵ�ǰ���
            side[i] += matchsticks[num];
            // Ȼ���ڷ���һ�����
            if (backtrack(matchsticks, num + 1, side, target)) return true;  //����
            // �Ƴ����ŵ���������
            side[i] -= matchsticks[num];
            // �����ǰ��û�л����ô��һ����Ҳ��Ȼû�л��
            // ���ߵ�ǰ��ǡ�ܴﵽ target
            if (side[i] == 0 || side[i] + matchsticks[num] == target) break;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int num : matchsticks) sum += num;
        if (sum == 0 || sum % 4 != 0) return false;
        vector<int> side(4);
        return backtrack(matchsticks, 0, side, sum / 4);
    }
};