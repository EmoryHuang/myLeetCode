'''
Descroption: LeetCode 1834. 单线程 CPU
Author: EmoryHuang
Date: 2021-09-11 19:42:08
Method:
排序 + 小根堆
给所有的任务添加编号并按进入时间排序
维护一个小根堆
若当前时间 >= 新项目的开始时间，则将所有可以执行的项目入堆
如果没有项目可以执行，则修改当前时间为下个任务的开始时间
'''


class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        n = len(tasks)
        tasks = [[ent, dur, idx] for idx, (ent, dur) in enumerate(tasks)]  # 添加序号
        # 按进入时间排序
        tasks.sort(key=lambda x: x[0])
        ans, heap = [], []
        cur_t, cur_id = tasks[0][0], 0
        while len(ans) < n:
            # 若当前时间 >= 新项目的开始时间
            # 则将所有可以执行的项目入堆排序
            while cur_id < n and cur_t >= tasks[cur_id][0]:
                ent, dur, idx = tasks[cur_id]
                heapq.heappush(heap, [dur, idx, ent])
                cur_id += 1
            if not heap:
                # 如果没有项目可以执行，则修改当前时间为下个任务的开始时间
                cur_t = tasks[cur_id][0]
                continue
            # 执行项目
            [dur, idx, ent] = heapq.heappop(heap)
            ans.append(idx)
            cur_t += dur
        return ans
