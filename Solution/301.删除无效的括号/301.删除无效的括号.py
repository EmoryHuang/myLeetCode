'''
Descroption: LeetCode 301. ɾ����Ч������
Author: EmoryHuang
Date: 2021-10-27 13:58:57
Method:
dfs + ��֦
���� ( �� 1 �֣����� ) �� 1 �֣���ô�Ϸ��ַ����ĵ÷�Ϊ 0
ʹ�� cur ��¼��ǰ�ĺϷ��ַ���
�������ĸ������� cur �����ݹ�
����� ( ���Ҽ����Ϸ�����ô����ѡ�������߲����� cur
����� ) ���Ҽ����Ϸ�����ô����ѡ�������߲����� cur
ͬʱ��ʹ�� maxl ��¼��ĺϷ��ַ���
'''


class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        def dfs(cur: str, idx: int, score: int):
            if score < 0 or score > self.maxs:
                return
            if idx == len(s):
                # �Ϸ��ַ����ĵ÷�Ϊ 0
                # ����ɾ��֮�����󳤶� maxl
                if score == 0 and len(cur) >= self.maxl:
                    # ��������� maxl ��˵��֮ǰɾ���Ĳ�����С���������¼�¼
                    if len(cur) > self.maxl:
                        ans.clear()
                    self.maxl = len(cur)
                    ans.add(cur)
                return

            if s[idx] == '(':
                # ����� ( ���Ҽ����Ϸ�����ô����ѡ�������߲����� cur
                dfs(cur + s[idx], idx + 1, score + 1)
                dfs(cur, idx + 1, score)
            elif s[idx] == ')':
                # ����� ) ���Ҽ����Ϸ�����ô����ѡ�������߲����� cur
                dfs(cur + s[idx], idx + 1, score - 1)
                dfs(cur, idx + 1, score)
            elif s[idx].isalpha():
                # �������ĸ������� cur �����ݹ�
                dfs(cur + s[idx], idx + 1, score)

        ans = set([''])
        # ��¼ ( �� ) ������
        cnt = Counter(s)
        # ���Ŀ��ܵ÷�Ϊ min(�����ŵ������������ŵ�����)
        self.maxs = min(cnt['('], cnt[')'])
        # ��¼��󳤶�
        self.maxl = 0
        dfs('', 0, 0)
        return list(ans)
