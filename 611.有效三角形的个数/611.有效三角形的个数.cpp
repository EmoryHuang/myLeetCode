class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=nums.size()-1;i>=2;i--){ // ö�����
            int j=0;
            int k=i-1;
            while(j<k){//˫ָ��
                if(nums[i] < nums[j]+nums[k]){
                    cnt += k-j;// [left, right - 1]����������
                    k--;
                }else
                    j++;
            }
        }
        return cnt;
    }
};