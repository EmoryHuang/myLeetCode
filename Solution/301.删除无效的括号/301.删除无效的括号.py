'''
Descroption: LeetCode 301. 删除无效的括号
Author: EmoryHuang
Date: 2021-10-27 13:58:57
Method:
dfs + 剪枝
遇到 ( 加 1 分，遇到 ) 减 1 分，那么合法字符串的得分为 0
使用 cur 记录当前的合法字符串
如果是字母，则加入 cur 正常递归
如果是 ( 并且加入后合法，那么可以选择加入或者不加入 cur
如果是 ) 并且加入后合法，那么可以选择加入或者不加入 cur
同时，使用 maxl 记录最长的合法字符串
'''


class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        def dfs(cur: str, idx: int, score: int):
            if score < 0 or score > self.maxs:
                return
            if idx == len(s):
                # 合法字符串的得分为 0
                # 更新删除之后的最大长度 maxl
                if score == 0 and len(cur) >= self.maxl:
                    # 如果超过了 maxl 则说明之前删除的不是最小数量，重新记录
                    if len(cur) > self.maxl:
                        ans.clear()
                    self.maxl = len(cur)
                    ans.add(cur)
                return

            if s[idx] == '(':
                # 如果是 ( 并且加入后合法，那么可以选择加入或者不加入 cur
                dfs(cur + s[idx], idx + 1, score + 1)
                dfs(cur, idx + 1, score)
            elif s[idx] == ')':
                # 如果是 ) 并且加入后合法，那么可以选择加入或者不加入 cur
                dfs(cur + s[idx], idx + 1, score - 1)
                dfs(cur, idx + 1, score)
            elif s[idx].isalpha():
                # 如果是字母，则加入 cur 正常递归
                dfs(cur + s[idx], idx + 1, score)

        ans = set([''])
        # 记录 ( 和 ) 的数量
        cnt = Counter(s)
        # 最大的可能得分为 min(左括号的数量，右括号的数量)
        self.maxs = min(cnt['('], cnt[')'])
        # 记录最大长度
        self.maxl = 0
        dfs('', 0, 0)
        return list(ans)
