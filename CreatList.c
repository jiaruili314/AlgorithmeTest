//创建链表

#include <stdio.h>
struct listNode{
    int val;
    listNode *next;
};

int main (){
    listNode a;
    listNode b;
    listNode c;
    listNode d;
    listNode e;

    a.val = 10;
    b.val = 20;
    c.val = 30;
    d.val = 40;
    e.val = 50;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    listNode *head = &a;

    while (head) {
        printf("%d\n",head->val);
        head = head -> next;
    }
}

