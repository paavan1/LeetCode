#include<stdlib.h>
#include<map>

using namespace std;
struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


    RandomListNode *copyRandomList(RandomListNode *head) {

        map<RandomListNode*, RandomListNode*> visited;

        RandomListNode* virtualHead = new RandomListNode(0), *p = head, *q = virtualHead;

        while(p)
        {

            if(visited.find(p) == visited.end())
            {
                visited.insert(pair<RandomListNode*,RandomListNode*>(p,new RandomListNode(p->label)));
            }

            q->next = visited[p];

            q = q->next;

            if(p->random && visited.find(p->random) == visited.end())
            {
                visited.insert(pair<RandomListNode*,RandomListNode*>(p->random,new RandomListNode(p->random->label)));
            }

            if(p->random)
            {
                q->random = visited[p->random];
            }

            p = p->next;
        }

        return virtualHead->next;
    }
