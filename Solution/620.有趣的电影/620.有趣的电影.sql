/*
 * @Descroption: LeetCode 620. ��Ȥ�ĵ�Ӱ
 * @Author: EmoryHuang
 * @Date: 2021-04-28 13:50:36
 * @����˼·:
 * �򵥵� MySQL ���
 */

# Write your MySQL query statement below
select * 
from cinema 
where description != 'boring' and id % 2 = 1 
order by rating desc