'''
Descroption: LeetCode 929. 独特的电子邮件地址
Author: EmoryHuang
Date: 2021-07-31 14:11:33
Method:
简单题，split分割字符串，replace 替换 name 中的 '.'
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