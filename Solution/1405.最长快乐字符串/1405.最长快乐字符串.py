'''
Descroption: LeetCode 1405. 最长快乐字符串
Author: EmoryHuang
Date: 2022-02-07 10:20:58
Method:
按照剩余数量降序排序
贪心策略，每次尽可能优先使用当前数量最多的字母
使用数量最多的字母: 结果字符串长度小于 2; 最后两个字符与其不相同; 数量最多的字母还有
否则使用数量第二多的字母
'''


class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        ans = ''
        cnt = [[a, 'a'], [b, 'b'], [c, 'c']]
        while True:
            # 按照剩余数量降序排序
            cnt.sort(reverse=True)
            if cnt[0][0] and (len(ans) < 2 or not ans[-2] == ans[-1] == cnt[0][1]):
                # 使用数量最多的字母
                #   数量最多的字母还有 and (结果字符串长度小于 2 or 最后两个字符与其不相同)
                ans += cnt[0][1]
                cnt[0][0] -= 1
            elif cnt[1][0]:
                # 使用数量第二多的字母
                ans += cnt[1][1]
                cnt[1][0] -= 1
            else:
                break
        return ans
