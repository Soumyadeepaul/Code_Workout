//https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/?envType=problem-list-v2&envId=linked-list


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Iterator {
public:
    // Returns the tail of the flattened list starting from head
    Node* iterator(Node* head) {
        Node* curr = head;
        Node* nextt = head ? head->next : nullptr;
        Node* tail = nullptr;

        while (curr != nullptr) {
            tail = curr;

            if (curr->child == nullptr) {
                curr = nextt;
                if (curr != nullptr)
                    nextt = curr->next;
            } else {
                // Recursively flatten the child list
                Node* childTail = iterator(curr->child);

                // Connect current <-> child
                curr->next = curr->child;
                curr->child->prev = curr;

                // Connect child's tail <-> next
                if (nextt != nullptr) {
                    childTail->next = nextt;
                    nextt->prev = childTail;
                }

                // Remove child pointer
                curr->child = nullptr;

                // Move curr forward
                curr = nextt;
                if (curr != nullptr)
                    nextt = curr->next;

                tail = childTail; // update tail to child's tail
            }
        }

        return tail;
    }
};


class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        Iterator i;
        i.iterator(head);
        return head;
    }
};
