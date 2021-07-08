/*
 * @Descroption: LCP 18. ������
 * @Author: EmoryHuang
 * @Date: 2021-07-08 19:22:12
 * @����˼·:
 * ���⣬ֱ�ӱ��������ᳬʱ������������ + ˫ָ��
 */

class Solution {
   public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        int ans = 0, j = drinks.size() - 1;
        for (int i = 0; i < staple.size(); i++) {
            if (staple[i] > x) break;
            while (j >= 0 && staple[i] + drinks[j] > x) j--;
            if (j == -1) break;
            ans += j + 1;
            ans %= 1000000007;
        }
        return ans;
    }
};