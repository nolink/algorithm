class Solution {
public:
    bool hasCircle(vector<vector<int>>& graph, vector<bool>& inGraph, vector<bool>& visited, int current){
        visited[current] = true;
        inGraph[current] = true;
        for(auto adj : graph[current]){
            if(!visited[adj]){
                if(hasCircle(graph, inGraph, visited, adj)) return true;
            }else if(inGraph[adj]){
                return true;
            }
        }
        inGraph[current] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<bool> visited(numCourses, false);
        vector<bool> inGraph(numCourses, false);
        for(auto p : prerequisites){
            graph[p.first].push_back(p.second);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(hasCircle(graph, inGraph, visited, i)) return false;
            }
        }
        return true;
    }
};
