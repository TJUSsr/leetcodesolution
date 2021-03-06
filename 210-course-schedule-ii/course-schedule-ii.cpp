// There are a total of n courses you have to take, labeled from 0 to n-1.
//
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
//
// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
//
// Example 1:
//
//
// Input: 2, [[1,0]] 
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
//              course 0. So the correct course order is [0,1] .
//
// Example 2:
//
//
// Input: 4, [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,1,2,3] or [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
//              courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
//              So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
//
// Note:
//
//
// 	The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// 	You may assume that there are no duplicate edges in the input prerequisites.
//
//


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visit(numCourses,1);
        vector<vector<int>> g(numCourses);
        vector<int> res;
        unordered_set<int> s;
        for(const auto& p:prerequisites){
            g[p.first].push_back(p.second);
        }
        for(int i=0;i<numCourses;++i){
            if(s.count(i))
                continue;
            if(!DFS(g,visit,res,s,i))
                return vector<int>();
        }
        return res;
        
    }
private:
    bool DFS(const vector<vector<int>>& g, vector<int>& visit, vector<int>& res, unordered_set<int>& s, int st){
        if(visit[st]==-1)
            return false;
        visit[st]=-1;
        bool r=true;
        for(const auto n:g[st]){
            if(s.count(st))
                continue;
            else
                r=r&&DFS(g,visit,res,s,n);
        }
        if(r&&!s.count(st)){
            s.insert(st);
            res.push_back(st);
        }
        visit[st]=1;
        return r;
    }
};
