/*
 * @Descroption: LeetCode 690. Ա������Ҫ��
 * @Author: EmoryHuang
 * @Date: 2021-05-01 19:13:36
 * @����˼·:
 * ͳ������� importance ֵ��ֱϵ������ importance ֵ��ͬʱ���ĳ���������������Ļ�����ݹ����
 */

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
   public:
    int getImportance(vector<Employee*> employees, int id) {
        for (Employee* e : employees) {
            if (e->id == id) {
                if (e->subordinates.size() == 0) {  // û������
                    return e->importance;
                }
                for (int sub : e->subordinates) {
                    e->importance += getImportance(employees, sub);  //�ݹ����
                }
                return e->importance;
            }
        }
        return 0;
    }
};