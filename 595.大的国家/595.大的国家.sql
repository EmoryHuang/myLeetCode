/*
 * @Descroption: LeetCode 595. ��Ĺ���
 * @Author: EmoryHuang
 * @Date: 2021-05-29 15:41:00
 * @����˼·: ��SQL���
 *
 */
# Write your MySQL query statement below
select name, population, area
from world
where area > 3000000 or population > 25000000