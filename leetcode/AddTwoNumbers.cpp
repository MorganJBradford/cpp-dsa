#include <iostream>
#include <stdlib.h>
#include "../Timer.cpp"
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {};

    void Print() {
        ListNode* currNode = this;
        while (currNode) {
            std::cout << currNode->val << std::endl;
            currNode = currNode->next;
        }
    }




};

ListNode* addTwoIterative(ListNode* l1, ListNode* l2) {
    std::cout << "Iterative " << std::endl;
    Timer timer;
    int c = 0;
    std::cout << "Initial c" << c << std::endl;
    ListNode newHead(0);
    ListNode *t = &newHead;
    int i = 1;
    while(c || l1 || l2) {
        std::cout << "c: " << c << std::endl;
        c += (l1? l1->val : 0) + (l2? l2->val : 0);
        std::cout << "Iteration " << i << " c+=: " << c << std::endl;
        t->next = new ListNode(c%10);
        std::cout << "Iteration " << i << " c%10: " << c%10 << std::endl;
        t = t->next;
        c /= 10;
        std::cout << "Iteration " << i << " c /= 10: " << c%10 << std::endl;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
        i++;
    }
    return newHead.next;
}

ListNode* addTwoRecursiveHelper(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) return nullptr;
    int c = (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
    ListNode* newHead = new ListNode(c % 10);
    ListNode* next = l1 ? l1->next : nullptr;
    c /= 10;
    if (next) next->val += c;
    else if (c) next = new ListNode(c);
    newHead->next = addTwoRecursiveHelper(l2 ? l2->next : nullptr, next);
    return newHead;
}

ListNode* addTwoRecursive(ListNode* l1, ListNode* l2) {
    std::cout << "Recursive " << std::endl;
    Timer timer; // Start the timer here
    return addTwoRecursiveHelper(l1, l2);
}

void PrintNodes(ListNode* node) {
    ListNode* curr = node;
    while (curr) {
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
}
void FillList(ListNode* node, int length) {
        ListNode* curr = node;
        for (int i = 0; i < length; ++i) {
            ListNode* newNode = new ListNode(rand() % 3 + 1);
            curr->next = newNode;
            curr = newNode;
        }
    }
int main()
{
    ListNode* lo3 = new ListNode(3);
    ListNode* lo2 = new ListNode(4, lo3);
    ListNode* lo1 = new ListNode(2, lo2);

    ListNode* lt3 = new ListNode(4);
    ListNode* lt2 = new ListNode(6, lt3);
    ListNode* lt1 = new ListNode(5, lt2);
    ListNode* rln = addTwoIterative(lo1, lt1);
    return 0;
}
