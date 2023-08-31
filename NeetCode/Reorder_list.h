#pragma once
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void display(ListNode* head) {
    ListNode* curr = head;
    cout << "List = ";
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode* reorder(ListNode* head) {
    ListNode* curr = head;
    ListNode* temp = nullptr;
    stack<ListNode*> stack;
    int n = 0;

    while (curr) {
        n++;
        stack.push(curr);
        curr = curr->next;
    }

    curr = head;

    for (int i = 0; i < (n / 2); i++) {
        temp = curr->next;
        curr->next = stack.top();
        stack.pop();
        stack.top()->next = nullptr;
        if (!curr->next) {
            curr->next = temp;
            break;
        }
        curr->next->next = temp;
        curr = temp;
    }

    return head;
}
