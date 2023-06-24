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
    int solve(int id,unordered_map<int,vector<int>>&adj,unordered_map<int,int>&imp){
        int ans = imp[id];
        for(auto it: adj[id]){
            ans += solve(it,adj,imp);
        }
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {    
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>imp;
        for(auto it: employees){
            adj[it->id] = it->subordinates;
            imp[it->id] = it->importance;
        }
        return solve(id,adj,imp);
    }
};