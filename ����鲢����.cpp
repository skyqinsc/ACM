#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define EPS 1e-8
#define x first
#define y second
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x):val(x){next=nullptr;}
};

ListNode* merge_list(ListNode *h1,ListNode *h2);

ListNode *qSort_list(ListNode * h){
    ListNode *sl=h,*fa=h;
    if(h==nullptr||h->next==nullptr) return h;
    while(fa->next&&fa->next->next){
        fa=fa->next->next;
        sl=sl->next;
    }
    fa=sl->next;
    sl->next=nullptr;
    ListNode *h1=qSort_list(h);
    ListNode *h2=qSort_list(fa);
    ListNode* ppp=merge_list(h1,h2);
    return ppp;
}

ListNode* merge_list(ListNode *h1,ListNode *h2){
    ListNode *rHead=nullptr,*p=nullptr;
    if(h1->val < h2->val) rHead=h1,h1=h1->next;
    else rHead=h2,h2=h2->next;
    p=rHead;
    while(h1&&h2){
        if(h1->val < h2->val) p->next=h1,h1=h1->next;
        else p->next=h2,h2=h2->next;
        p=p->next;
    }
    if(h1) p->next=h1;
    if(h2) p->next=h2;
    return rHead;
}

int main(){
    //5 3 8 3 7 9 5 6
    ListNode *p[10];
    p[0]=new ListNode(5);
    p[1]=new ListNode(3); p[0]->next=p[1];
    p[2]=new ListNode(8); p[1]->next=p[2];
    p[3]=new ListNode(3); p[2]->next=p[3];
    p[4]=new ListNode(7); p[3]->next=p[4];
    p[5]=new ListNode(9); p[4]->next=p[5];
    p[6]=new ListNode(5); p[5]->next=p[6];
    p[7]=new ListNode(6);p[6]->next=p[7];
    ListNode *h=qSort_list(p[0]);
    while(h){
        printf("%d  ",h->val);
        h=h->next;
    }
    return 0;
}
