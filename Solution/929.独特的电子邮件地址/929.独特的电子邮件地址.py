'''
Descroption: LeetCode 929. ���صĵ����ʼ���ַ
Author: EmoryHuang
Date: 2021-07-31 14:11:33
Method:
���⣬split�ָ��ַ�����replace �滻 name �е� '.'
'''


class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        ans = set()
        for email in emails:
            name, doamin = email.split('@')
            if '+' in name:
                name = name[:name.find('+')]
            name = name.replace('.', '')
            ans.add(name + '@' + doamin)
        return len(ans)