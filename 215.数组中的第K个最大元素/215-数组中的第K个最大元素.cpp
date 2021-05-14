class Solution {
   public:
    // int quickFind(vector<int>& nums, int left, int right, int k) {
    //     int keyPos = left + rand() % (right - left);  //初始随机位置
    //     swap(nums[keyPos], nums[left]);
    //     int start = left, end = right - 1, key = nums[left];
    //     while (start < end) {
    //         while (start < end && nums[end] >= key) end--;
    //         nums[start] = nums[end];
    //         while (start < end && nums[start] <= key) start++;
    //         nums[end] = nums[start];
    //     }
    //     nums[start] = key;       // start 为划分位置
    //     if (start == right - k)  //找到第 k 大
    //         return nums[start];
    //     else if (start > right - k)
    //         return quickFind(nums, left, start, k - (right - start));  //在前半部分
    //     else
    //         return quickFind(nums, start + 1, right, k);  //在后半部分
    // }
    int findKthLargest(vector<int>& nums, int k) { 
        int len = nums.size();
        if(len==0 || k > len) return 0;
        priority_queue<int,vector<int>,greater<int>> st;
        for(int i=0;i<len;i++){
            st.push(nums[i]);
            if(st.size()>k) st.pop();
        }
        return st.top();
    }
};
