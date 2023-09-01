#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;

struct LinkedNode {
    int val;
    LinkedNode* next;
    LinkedNode(int x) : val(x), next(nullptr) {}
};

void display(LinkedNode* head) {
    LinkedNode* curr = head;
    cout << "List = ";
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

LinkedNode* reverse(LinkedNode* head) {
    LinkedNode* curr = head;
    LinkedNode* prev = nullptr;
    LinkedNode* temp = nullptr;

    while (curr) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    head = prev;
    
    return head;
}

LinkedNode* reorder(LinkedNode* head) {
    LinkedNode* f = head;
    LinkedNode* s = head;
    LinkedNode* f_temp = nullptr;
    LinkedNode* s_temp = nullptr;

    while (f->next && f->next->next) {
        s = s->next;
        f = f->next->next;
    }

    s_temp = s->next;
    s->next = nullptr;

    if (f->next) {
        f = f->next;
    }
    
    f_temp = reverse(s_temp);

    f = f_temp;
    s = head;

    while (f) {
        s_temp = s->next;
        f_temp = f->next;

        s->next = f;
        f->next = s_temp;

        s = s_temp;
        f = f_temp;
    }

    return head;
}