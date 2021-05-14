/*
 * @Descroption: LeetCode 179. �����
 * @Author: EmoryHuang
 * @Date: 2021-04-12 19:30:36
 * @����˼·: ��д`sort()`����λ���ִ������ǰ�棬֮���������Ӽ���
 * ��������� `sa + sb > sb + sa`
 */

class Solution {
   public:
    static bool cmp(int a, int b) {
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        if (nums[0] == 0) return "0";
        for (int i = 0; i < nums.size(); i++) {
            ans += to_string(nums[i]);
        }
        return ans;
    }
};