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

    ListNode* reverseList (ListNode* head, int m, int n){
        int change_len = n - m + 1;
        ListNode *pre_head = NULL;
        ListNode *result = head;
        // Serch the beginning of the reverse and storage the place of pre_head
        while(head && --m){
            pre_head = head;
            head = head -> next;
        }
        ListNode* modify_list_tail = head;

        //Start reverse
        ListNode *new_head = NULL;
        while (head && change_len){
            ListNode* next = head ->next;
            head -> next = new_head;
            new_head = head;
            head = next;
            change_len --;
        }

        //Connection
        modify_list_tail -> next = head;
        if(pre_head)
            pre_head -> next = new_head;
        else
            result = new_head;

        return result;
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

    head = solve.reverseList(&a,2,4);

    printf("After reverse:\n");
    while(head){
        printf("%d\n", head->val);
        head = head -> next;
    }

    return 0;
}
