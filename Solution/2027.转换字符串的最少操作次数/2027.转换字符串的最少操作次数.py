class Solution:
    def minimumMoves(self, s: str) -> int:
        covered = -1
        res = 0
        for i, c in enumerate(s):
            if c == 'X' and i > covered:
                res += 1
                covered = i + 2
        return res
