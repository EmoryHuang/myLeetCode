class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        vector<int> dp(len,1);// ��ʼΪ1
        int maxInd = 0;// �Ӽ������Ԫ��
        for(int i=0;i<len;i++){
            for(int j =0;j<i;j++){
                if(nums[i]%nums[j]==0)
                    dp[i] = max(dp[i],dp[j]+1);
            }
            if(dp[i] > dp[maxInd]) maxInd=i;
        }
        // �������Ԫ��Ѱ������Ԫ��
        vector<int> ans;
        ans.push_back(nums[maxInd]);// ���Ԫ��
        for(int i=len-1;i>=0 && dp[maxInd]>1;i--){
            if(dp[maxInd] - 1 == dp[i] && nums[maxInd]% nums[i]==0){
                ans.push_back(nums[i]);
                maxInd=i;
            }
        }
        return ans;
    }
};