/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    void cloneInsert(RandomListNode* node)
    {
        if (node) {
            auto* newNode = new RandomListNode(node->label);
            // insert
            newNode->next = node->next;
            node->next = newNode;
        }
    }
    
    RandomListNode* nextOriginal(RandomListNode* node)
    {
        return (node && node->next && node->next->next ? node->next->next : nullptr);
    }

    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) {
            return nullptr;    
        }
        
        auto *node = head;
        
        // clone and insert new node after node
        while (node) {
            cloneInsert(node);
            node = nextOriginal(node);
            if (node && node == head) {
                node = nullptr;
            } 
        }
        
        // set newNode->random
        node = head;
        while (node) {
            if (node->random) {
                auto* newNode = node->next;
                if (newNode) {
                    newNode->random = node->random->next;
                }
            }
            node = nextOriginal(node);
            if (node && node == head) {
                node = nullptr;
            }
        }
        
        // split
        auto* newHead = head->next;
        
        node = head;
        while (node) {
            auto* next = nextOriginal(node);
            auto* newNode = node->next;
            node->next = newNode->next;
            newNode->next = (newNode->next ? newNode->next->next : nullptr);

            node = next;
            if (node && node == head) {
                node = nullptr;
            }
        }

        return newHead;        
    }
};