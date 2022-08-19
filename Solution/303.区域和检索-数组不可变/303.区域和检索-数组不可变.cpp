/*
 * @Descroption: LeetCode 303. ����ͼ��� - ���鲻�ɱ�
 * @Author: EmoryHuang
 * @Date: 2021-03-26 09:43:36
 * @����˼·:
 * �����ص��뷨�Ǵ洢���� `nums` ��ֵ��ÿ�ε��� `sumRange` ʱ��
 * ͨ��ѭ���ķ����������� `nums` ���±� `i` ���±� `j` ��Χ�ڵ�Ԫ�غ�
 *
 * �����ȴ���һ��ǰ׺�����飬������Ŵ�ԭ����ÿ���ۼӵĺͣ������������ü�����ֱ�ӵó����
 */

class NumArray {
   public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr.push_back(0);
        int sum = 0;
        for (int i = 1; i <= nums.size(); i++) {
            sum += nums[i - 1];
            arr.push_back(sum);
        }
    }

    int sumRange(int left, int right) { return arr[right + 1] - arr[left]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */