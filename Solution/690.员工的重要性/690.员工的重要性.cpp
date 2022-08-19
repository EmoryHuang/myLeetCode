/*
 * @Descroption: LeetCode 690. 员工的重要性
 * @Author: EmoryHuang
 * @Date: 2021-05-01 19:13:36
 * @解题思路:
 * 统计自身的 importance 值和直系下属的 importance 值。同时如果某个下属还有下属的话，则递归求解
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
                if (e->subordinates.size() == 0) {  // 没有下属
                    return e->importance;
                }
                for (int sub : e->subordinates) {
                    e->importance += getImportance(employees, sub);  //递归求解
                }
                return e->importance;
            }
        }
        return 0;
    }
};