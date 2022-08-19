/*
 * @Descroption: LeetCode 627. 变更性别
 * @Author: EmoryHuang
 * @Date: 2021-04-28 15:10:36
 * @解题思路:
 * 简单的 MySQL 语句
 */

# Write your MySQL query statement below
update salary
set sex = if(sex='m','f','m');