'''
Descroption: LeetCode 890. ���Һ��滻ģʽ
Author: EmoryHuang
Date: 2022-06-12 09:49:40
Method:
ʹ�ù�ϣ���¼�ַ�֮���ӳ���ϵ
�������е��ʣ����μ��ģʽ�Ƿ�ƥ��
'''


class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def match(word, pattern):
            map = defaultdict(str)
            for ch, p in zip(word, pattern):
                if p in map:
                    if map[p] != ch:
                        return False
                else:
                    map[p] = ch
            return True

        return [w for w in words if match(w, pattern) and match(pattern, w)]