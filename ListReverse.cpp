//reverse list


#include<iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v): val(v), next(NULL){}  //construction
};


class Solution{

public:
    ListNode* reverseList(ListNode* head){
        ListNode *new_head = NULL;
        while(head){

            ListNode *next = head->next;
            head -> next = new_head;
            new_head = head;
            head = next;
        }
        return new_head;

    }
};


int main(){

    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    ListNode *head = &a;

    Solution solve;
    printf("Before reverse:\n");
    while(head){
        printf("%d\n", head->val);
        head = head -> next;

    }
    head = solve.reverseList(&a);

    printf("After reverse:\n");
    while(head){
        printf("%d\n", head->val);
        head = head -> next;
    }


}
