class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        int flag = 0;// �ڶ�����
        int ans = 1;
        for(int i = 1;i<len;i++){
            // ǰһ����ͺ�һ������������
            if((flag >=0 && nums[i]-nums[i-1] <0) || (flag<=0 && nums[i]-nums[i-1] >0)){
                flag = nums[i]-nums[i-1];
                ans++;
            }
        }
        return ans;
    }
};