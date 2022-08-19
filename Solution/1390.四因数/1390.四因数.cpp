/*
 * @Descroption: LeetCode 1390. 四因数
 * @Author: EmoryHuang
 * @Date: 2021-08-20 20:21:40
 * @Method:
 * 遍历数组中的每个数，
 * 若当前数的因数个数为4个，则计数因数之和
 */

class Solution {
   public:
    int count_divisor(int num) {
        set<int> d;
        for (int i = 1; i <= sqrt(num); i++) {
            if (num % i == 0) {
                d.insert(i);
                d.insert(num / i);
            }
        }
        int sum = 0;
        for (int x : d) sum += x;
        if (d.size() == 4) return sum;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) ans += count_divisor(num);
        return ans;
    }
};