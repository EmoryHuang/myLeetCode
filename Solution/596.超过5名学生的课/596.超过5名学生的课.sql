/*
 * @Descroption: LeetCode 596. ����5��ѧ���Ŀ�
 * @Author: EmoryHuang
 * @Date: 2021-05-29 15:46:00
 * @����˼·: ���� group by Ϊ class �����
 * ֱ���� count() ͳ��ÿ��ѧ������
 * distinct ȥ���ظ�ѧ��
 */

# Write your MySQL query statement below
select class
from courses
group by class
having count(distinct student) >= 5