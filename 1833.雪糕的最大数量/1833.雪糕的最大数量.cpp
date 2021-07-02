/*
 * @Descroption: LeetCode 1833. ѩ����������
 * @Author: EmoryHuang
 * @Date: 2021-07-02 13:06:00
 * @����˼·:
 * ̰��˼�룬������ǰ����ѡ��
 */

class Solution {
   public:
    // sort()
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for (int cost : costs) {
            coins -= cost;
            if (coins < 0) return ans;
            ans++;
        }
        return coins >= 0 ? ans : 0;
    }

    // ����
    // void quicksort(vector<int>& nums, int l, int r) {
    //     if (l >= r) return;
    //     int i = l - 1, j = r + 1, x = nums[l + r >> 1];
    //     while (i < j) {
    //         while (nums[++i] < x)
    //             ;
    //         while (nums[--j] > x)
    //             ;
    //         if (i < j) swap(nums[i], nums[j]);
    //     }
    //     quicksort(nums, l, j);
    //     quicksort(nums, j + 1, r);
    // }
    // int maxIceCream(vector<int>& costs, int coins) {
    //     quicksort(costs, 0, costs.size() - 1);
    //     int ans = 0;
    //     for (int cost : costs) {
    //         coins -= cost;
    //         if (coins < 0) return ans;
    //         ans++;
    //     }
    //     return coins >= 0 ? ans : 0;
    // }
};