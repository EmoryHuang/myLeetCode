class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p1 = 0;  // �ֱ�ָ��0��1
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                p1++;
            } else if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) swap(nums[i], nums[p1]);
                p0++;
                p1++;  // 0��1ǰ�����p1ҲҪ����
            }
        }
    }
};