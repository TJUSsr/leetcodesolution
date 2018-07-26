// There are a total of n courses you have to take, labeled from 0 to n-1.
//
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
//
// Example 1:
//
//
// Input: 2, [[1,0]] 
// Output: true
// Explanation:&nbsp;There are a total of 2 courses to take. 
// &nbsp;            To take course 1 you should have finished course 0. So it is possible.
//
// Example 2:
//
//
// Input: 2, [[1,0],[0,1]]
// Output: false
// Explanation:&nbsp;There are a total of 2 courses to take. 
// &nbsp;            To take course 1 you should have finished course 0, and to take course 0 you should
// &nbsp;            also have finished course 1. So it is impossible.
//
//
// Note:
//
//
// 	The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// 	You may assume that there are no duplicate edges in the input prerequisites.
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visit(numCourses,1);
        vector<vector<int>> g(numCourses);
        unordered_set<int> t;
        for(const auto& p:prerequisites){
            g[p.first].push_back(p.second);
        }
        for(int i=0;i<numCourses;++i){
            if(!DFS(g,visit,i,t))
                return false;
        }
        return true;
    }
    bool DFS(const vector<vector<int>>& g,vector<int>& visit, int i,unordered_set<int>& t){
        if(visit[i]==-1)
            return false;
        bool res=true;
        visit[i]=-1;
        for(const auto& n:g[i]){
            if(t.count(n))
                continue;
            else
                res=res&&DFS(g,visit,n,t);
            if(res)
                t.insert(n);
        }
        if(res)
            t.insert(i);
        visit[i]=1;
        return res;
    }
};
