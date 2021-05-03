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
        for(Employee* e : employees){
            if(e->id==id){
                if(e->subordinates.size()==0){
                    return e->importance;
                }
                for(int sub : e->subordinates){
                    e->importance += getImportance(employees,sub);
                }
                return e->importance;
            }
        }
        return 0;
    }
};