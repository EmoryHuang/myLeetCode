/*
 * @Descroption: LeetCode 1449. ��λ�ɱ���ΪĿ��ֵ���������
 * @Author: EmoryHuang
 * @Date: 2021-06-12 21:53:00
 * @����˼·:
 * ��ȫ��������
 * ����������λ����ͬ��λ�������������Ȼ����λ��С��������
 * ���������Ҫ�ȼ�������Եõ������������λ��
 * dp[j]��ʾ�ܳɱ�ǡ��Ϊ j ʱ���λ��
 * ״̬ת�Ʒ��̣�dp[j] = max(dp[j], dp[j - cost] + 1)
 * Ӧ�þ������ø�λ����ֵԽ��Խ�ã�
 * ������ǿ��Դ���ֵ 9 ��ʼ����ֵ 1 ���������״̬�ܹ��ɸ���ֵת�ƶ�������ѡ�����ֵ
 */

#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    string largestNumber(vector<int>& cost, int target) {
        // dp[j]��ʾ�ܳɱ�ǡ��Ϊ j ʱ���λ��
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        for (int c : cost)
            for (int j = c; j <= target; j++) dp[j] = max(dp[j], dp[j - c] + 1);
        if (dp[target] < 0) return "0";
        string ans;
        for (int i = 8, j = target; i >= 0; i--) {  // �Ӻ���ǰ������cost�Ϊ9
            while (j >= cost[i] && dp[j] == dp[j - cost[i]] + 1) {
                ans += to_string(i + 1);
                j -= cost[i];
            }
        }
        return ans;
    }
};