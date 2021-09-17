# Descroption: LeetCode 175. 组合两个表
# Author: EmoryHuang
# Date: 2021-09-17 19:38:38
# Method:
#   左连接 LEFT JOIN
# Write your MySQL query statement below
SELECT A.FirstName, A.LastName, B.City, B.State
FROM Person A
LEFT JOIN Address B
ON A.PersonId = B.PersonId
