'''
Descroption: LeetCode 535. TinyURL �ļ��������
Author: EmoryHuang
Date: 2021-08-20 16:17:03
Method:
ʵ���Ͼ�����ĽǶ���������ȫ����ֱ�ӷ���ԭ�ַ���
��Ȼ�������Ҫ���ܵĻ������ù�ϣ������ַ�ӳ�䣬�ƶ����� ASCII ��
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