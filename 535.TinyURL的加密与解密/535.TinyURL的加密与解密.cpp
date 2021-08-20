/*
 * @Descroption: LeetCode 535. TinyURL 的加密与解密
 * @Author: EmoryHuang
 * @Date: 2021-08-20 16:17:25
 * @Method:
 * 实际上就做题的角度来讲，完全可以直接返回原字符串
 * 当然如果你想要加密的话可以用哈希表打乱字符映射，移动几个 ASCII 等
 */

class Solution {
   public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) { return longUrl; }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) { return shortUrl; }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));