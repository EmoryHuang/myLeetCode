/*
 * @Descroption: LeetCode 90. �Ӽ� II
 * @Author: EmoryHuang
 * @Date: 2021-03-31 11:10:36
 * @����˼·:
 * �� [78. �Ӽ�]���ƣ����û��ݷ�������Ҫ��֦
 * �ж��Ƿ���Ҫ��֦����Ҫ�ȶ���������ʹ�������� `sort()`
 * ��`i>start`ʱ����ѡ���֮ǰ���Ƚ�һ�µ�ǰ��`nums[i]`����һ����`nums[i-1]`�ǲ�����ͬ����ͬ��`continue`
 */

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> temp;
    void trackBack(vector<int> nums, vector<int>& path, int start) {
        ans.push_back(path);  //��ÿһ��·����������
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);       //����ѡ��
            trackBack(nums, temp, i + 1);  //�ݹ������һ��
            temp.pop_back();               //����ѡ��
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        trackBack(nums, temp, 0);
        return ans;
    }
};