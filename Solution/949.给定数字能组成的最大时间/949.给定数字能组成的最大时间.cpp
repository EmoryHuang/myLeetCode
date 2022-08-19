/*
 * @Descroption: LeetCode 949. 给定数字能组成的最大时间
 * @Author: EmoryHuang
 * @Date: 2021-06-04 15:32:00
 * @解题思路:
 * 暴力遍历
 */

class Solution {
   public:
    string largestTimeFromDigits(vector<int>& arr) {
        string ans = "";
        int maxt = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    if (j != i && k != i && k != j) {
                        int l = 6 - i - j - k;  // l就是0+1+2+3-i-j-k的序号
                        int hour = arr[i] * 10 + arr[j];
                        int min = arr[k] * 10 + arr[l];
                        int time = hour * 60 + min;
                        if (hour < 24 && min < 60 && time >= maxt) {
                            maxt = time;
                            ans = to_string(arr[i]) + to_string(arr[j]) + ":" + to_string(arr[k]) +
                                  to_string(arr[l]);
                        }
                    }
        return ans;
    }
};