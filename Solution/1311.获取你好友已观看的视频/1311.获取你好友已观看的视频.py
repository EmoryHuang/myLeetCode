'''
Descroption: LeetCode 1311. 获取你好友已观看的视频
Author: EmoryHuang
Date: 2021-08-04 10:33:20
Method:
bfs获取深度为level的节点
统计深度为level的节点的观看视频统计
然后按照给定要求进行排序
'''

class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]],
                               friends: List[List[int]], id: int,
                               level: int) -> List[str]:
        n = len(watchedVideos)
        q = deque([id])
        vis = [False] * n
        vis[id] = True
        # bfs获取深度为level的节点
        for _ in range(level):
            nl = len(q)
            for i in range(nl):
                u = q.popleft()
                for v in friends[u]:
                    if not vis[v]:
                        q.append(v)
                        vis[v] = True
        # 统计深度为level的节点的观看视频统计
        cnt = Counter()
        for _ in range(len(q)):
            u = q.pop()
            for watch in watchedVideos[u]:
                cnt[watch] += 1
        videos = list(cnt.items())
        videos.sort(key=lambda x: (x[1], x[0]))
        ans = [video[0] for video in videos]
        return ans