'''
Descroption: LeetCode 691. 贴纸拼词
Author: EmoryHuang
Date: 2022-05-14 09:11:58
Method:
记忆化搜索 + 状态压缩
使用 mask 来表示 target 中的每个字母是否找到
遍历 stickers 中的每个字符串，来寻找 target 中缺失的字符
如果当前字符不存在并且在 sticker 中，则更新 mask 并继续向下搜索
'''


class Solution:
    def minStickers(self, stickers: List[str], target: str) -> int:
        @lru_cache(None)
        def dp(mask):
            # mask 表示 target 当前缺失字符的位置
            if mask == 0:
                return 0
            ans = m + 1

            # 遍历 stickers 中的每个字符串，来寻找 target 中缺失的字符
            for sticker in stickers:
                cur = mask  # 当前状态
                cnt = Counter(sticker)
                for i, c in enumerate(target):
                    # 如果当前字符不存在并且在 sticker 中
                    if cnt[c] and (mask >> i & 1):
                        cnt[c] -= 1
                        cur ^= 1 << i  # 更新当前状态
                if cur < mask:
                    # 如果当前状态更小，则继续向下搜索
                    ans = min(ans, 1 + dp(cur))
            return ans

        m = len(target)
        # 初始化 mask 全为 1
        ans = dp((1 << m) - 1)
        return ans if ans <= m else -1