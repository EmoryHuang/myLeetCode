/*
 * @Descroption: LeetCode 620. 有趣的电影
 * @Author: EmoryHuang
 * @Date: 2021-04-28 13:50:36
 * @解题思路:
 * 简单的 MySQL 语句
 */

# Write your MySQL query statement below
select * 
from cinema 
where description != 'boring' and id % 2 = 1 
order by rating desc