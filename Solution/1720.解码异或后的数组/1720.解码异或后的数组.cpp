/*
 * @Descroption: LeetCode 1720. 解码异或后的数组
 * @Author: EmoryHuang
 * @Date: 2021-05-06 18:24:36
 * @解题思路:
 * 异或运算具有如下性质：
 * - 异或运算满足交换律和结合律；
 * - 任意整数和自身做异或运算的结果都等于 0，即 `x^x=0`；
 * - 任意整数和 0 做异或运算的结果都等于其自身，即 `x^0 = 0^x = x`。
 * a^b = c ， a^b^b = a， 即 c^b=a 同理 c^a =b
 * 因此有
 * `encode[i] = decode[i] ^ decode[i+1]`
 * `decode[i+1] = decode[i] ^ encode[i]`
 */

class Solution {
   public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        for (int i = 0; i < encoded.size(); i++) {
            ans.push_back(ans.back() ^ encoded[i]);
        }
        return ans;
    }
};