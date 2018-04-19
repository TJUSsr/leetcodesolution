//
// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
//
//
//
//
// OJ's undirected graph serialization:
//
//
// Nodes are labeled uniquely.
//
//
// We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
//
//
//
//
// As an example, consider the serialized graph {0,1,2#1,2#2,2}.
//
//
//
// The graph has a total of three nodes, and therefore contains three parts as separated by #.
//
// First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
// Second node is labeled as 1. Connect node 1 to node 2.
// Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
//
//
//
//
// Visually, the graph looks like the following:
//
//        1
//       / \
//      /   \
//     0 --- 2
//          / \
//          \_/
//
//
//
//


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    //BFS
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return nullptr;
        queue<UndirectedGraphNode*> que;
        que.push(node);
        mp[node]=new UndirectedGraphNode(node->label);
        while(!que.empty()){
            auto cur=que.front();
            que.pop();
            for(const auto nei:cur->neighbors){
                if(!mp.count(nei)){
                    mp[nei]=new UndirectedGraphNode(nei->label);
                    que.push(nei);
                }
                mp[cur]->neighbors.push_back(mp[nei]);
            }
        }
        return mp[node];
    }
    /*DFS
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return nullptr;
        if(!mp.count(node)){
            mp[node]=new UndirectedGraphNode(node->label);
            for(const auto& nei:node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(nei));
            }
        }
        return mp[node];
    }*/
private:
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> mp;
};
