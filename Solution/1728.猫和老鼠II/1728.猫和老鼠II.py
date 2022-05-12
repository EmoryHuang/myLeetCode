'''
Descroption: LeetCode 1728. è������ II
Author: EmoryHuang
Date: 2022-05-10 09:25:34
Method:
dfs
��Ϊ���è��Ӯ��è�϶�ֱ��ʳ����߻�׽��������Ҳͬ����ֻҪ��һ����Ӯ�Ͳ�����Ȧ��������ո�x2��
dfs ģ�⣬����è�������λ�ã��Լ���ǰ�����������������Ƿ���Ӯ
'''


class Solution:
    def canMouseWin(self, grid: List[str], catJump: int, mouseJump: int) -> bool:
        m, n = len(grid), len(grid[0])
        wall = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 'M':
                    mouse = (i, j)
                elif grid[i][j] == 'C':
                    cat = (i, j)
                elif grid[i][j] == 'F':
                    food = (i, j)
                elif grid[i][j] == '#':
                    wall += 1
        max_turn = (n * m - wall) * 2

        @lru_cache(None)
        def dfs(cat, mouse, step):
            if step > max_turn or cat == mouse or cat == food:
                return False
            if mouse == food:
                return True
            # ��ǰ�غ��ж�
            if step % 2 == 0:
                max_jump, cur_pos = mouseJump, mouse
                is_cat = False
            else:
                max_jump, cur_pos = catJump, cat
                is_cat = True

            # �������ƶ�
            for dx, dy in {(0, 1), (1, 0), (-1, 0), (0, -1)}:
                for jump in range(max_jump + 1):
                    # è��ԭ�ز�����������
                    if not jump and not is_cat:
                        continue
                    nx, ny = cur_pos[0] + jump * dx, cur_pos[1] + jump * dy
                    if not (0 <= nx < m and 0 <= ny < n) or grid[nx][ny] == '#':
                        break
                    if not is_cat and dfs(cat, (nx, ny), step + 1):
                        return True
                    elif is_cat and not dfs((nx, ny), mouse, step + 1):
                        return False
            return is_cat

        return dfs(cat, mouse, 0)