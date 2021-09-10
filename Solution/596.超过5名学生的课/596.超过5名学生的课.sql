/*
 * @Descroption: LeetCode 596. 超过5名学生的课
 * @Author: EmoryHuang
 * @Date: 2021-05-29 15:46:00
 * @解题思路: 利用 group by 为 class 分组后，
 * 直接用 count() 统计每组学生个数
 * distinct 去掉重复学生
 */

# Write your MySQL query statement below
select class
from courses
group by class
having count(distinct student) >= 5