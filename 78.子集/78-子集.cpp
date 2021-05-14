/*
 * @Descroption: LeetCode 78. �Ӽ�
 * @Author: EmoryHuang
 * @Date: 2021-03-31 10:58:36
 * @����˼·: ���ݷ�
 * ʹ��һ������ start������ʶ��ǰ��ѡ���б����ʼλ�ã������·������ ans ����б�
 * ����⽫����·�������룬����Ҫ��֦
 */

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> temp;
    void trackBack(vector<int> nums, vector<int>& path, int start) {
        ans.push_back(path);  //��ÿһ��·����������
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);       //����ѡ��
            trackBack(nums, temp, i + 1);  //�ݹ������һ��
            temp.pop_back();               //����ѡ��
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        trackBack(nums, temp, 0);
        return ans;
    }
};