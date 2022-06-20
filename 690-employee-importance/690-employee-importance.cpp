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
    
    int ans;
    
    void dfs(vector<Employee*>&employees, int id, unordered_map<int, int>&idx){
        
        int d = idx[id];
        ans += employees[d]->importance;
        
        for(auto sub : employees[d]->subordinates){
            dfs(employees, sub, idx);
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        
        unordered_map<int, int>idx;
        
        for(int i=0; i<employees.size(); i++){
            idx[employees[i]->id] = i;
        }
        
        ans = 0;
        
        dfs(employees, id, idx);
        
        return ans;
    }
};