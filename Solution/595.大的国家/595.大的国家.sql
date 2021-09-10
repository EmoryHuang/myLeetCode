/*
 * @Descroption: LeetCode 595. 大的国家
 * @Author: EmoryHuang
 * @Date: 2021-05-29 15:41:00
 * @解题思路: 简单SQL语句
 *
 */
# Write your MySQL query statement below
select name, population, area
from world
where area > 3000000 or population > 25000000