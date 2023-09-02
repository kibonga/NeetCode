#pragma once
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
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

ListNode* add_two_numbers(ListNode* a, ListNode* b) {
    ListNode* head = nullptr;
    ListNode* curr = nullptr;
    stack<int> s1;
    stack<int> s2;

    curr = a;
    while (a) {
        s1.push(a->val);
        a = a->next;
    }

    curr = b;
    while (b) {
        s2.push(b->val);
        b = b->next;
    }

    int len = s1.size() > s2.size() ? s1.size() : s2.size();
    int is_equal;
    int total = 0;
    int n = 1;

    while (s1.size() || s2.size()) {
        if (s1.size() && !s2.size()) {
            total += s1.top() * n;
            s1.pop();
        }
        else if(s2.size() && !s1.size()) {
            total += s2.top() * n;
            s2.pop();
        }
        else {
            total += (s1.top() * n + s2.top() * n);
            s1.pop();
            s2.pop();
        }
        n *= 10;
    }

    int sum = total;
    int d;

    int res = 8 % 10;

    curr = head;
    while (total % 10 || total / 10) {
        d = total % 10;
        if (!head) {
            head = new ListNode(d);
            curr = head;
        }
        else {
            curr->next = new ListNode(d);
            curr = curr->next;
        }
        total /= 10;
    }

    return head;
}
