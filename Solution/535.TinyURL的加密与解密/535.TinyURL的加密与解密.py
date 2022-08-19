'''
Descroption: LeetCode 535. TinyURL 的加密与解密
Author: EmoryHuang
Date: 2021-08-20 16:17:03
Method:
实际上就做题的角度来讲，完全可以直接返回原字符串
当然如果你想要加密的话可以用哈希表打乱字符映射，移动几个 ASCII 等
'''


class Codec:
    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        return longUrl

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        return shortUrl


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))