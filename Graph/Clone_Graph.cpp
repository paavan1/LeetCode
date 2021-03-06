#include<vector>
#include<stdlib.h>
#include<map>

using namespace std;

struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
};



    UndirectedGraphNode* dfs(UndirectedGraphNode* node , map<UndirectedGraphNode*, UndirectedGraphNode*>& visited)
    {
        if(visited.find(node) != visited.end()) return visited[node];

        UndirectedGraphNode* cloneNode = new UndirectedGraphNode(node->label);

        visited.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(node, cloneNode));

        for(int i = 0; i < node->neighbors.size(); i++)
        {
            cloneNode->neighbors.push_back(dfs(node->neighbors[i],visited));
        }

        return cloneNode;
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

        if(node == NULL) return NULL;

        map<UndirectedGraphNode*, UndirectedGraphNode*> visited;

        return dfs(node,visited);
    }

