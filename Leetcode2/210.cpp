class Solution {
public:
    bool hasCircle(vector<vector<int>>& graph, vector<bool>& inGraph, vector<bool>& visited, vector<int>& rorder, int current){
        visited[current] = true;
        inGraph[current] = true;
        for(auto adj : graph[current]){
            if(!visited[adj]){
                if(hasCircle(graph, inGraph, visited, rorder, adj)){
                    return true;
                }
            }else if(inGraph[adj]){
                return true;
            }
        }
        inGraph[current] = false;
        rorder.push_back(current);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<bool> inGraph(numCourses, false);
        vector<bool> visited(numCourses, false);
        vector<int> ret;
        for(auto p : prerequisites){
            graph[p.first].push_back(p.second);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && !graph[i].empty()){
                if(hasCircle(graph, inGraph, visited, ret, i)){
                    return {};
                }
            }
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]) ret.push_back(i);
        }
        return ret;
    }
};
