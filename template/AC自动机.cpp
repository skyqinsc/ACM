#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define INF 0x7fffffff
#define SUP 0x80000000
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef long long LL;
const int N=100007;

const int kind=26;
struct Node{
    Node *fail;   //Ê§°ÜÖ¸Õë
    Node *next[kind];
    int cnt;  //±ê¼Ç
    Node(){
        fail=NULL;
        cnt=0;
        memset(next,NULL,sizeof(next));
    }
};

char keyword[51];
char str[1000001];

void Insert(char *s,Node *root)
{
    Node *p=root;
    int i=0,idx;
    while(s[i])
    {
        idx=s[i]-'a';
        if(p->next[idx]==NULL) p->next[idx]=new Node();
        p=p->next[idx];
        i++;
    }
    p->cnt++;
}

void BuildAc(Node *root)
{
    queue<Node*> que;
    root->fail=NULL;
    que.push(root);

    while(!que.empty())
    {
        Node *tmp=que.front();
        que.pop();
        Node *p=NULL;
        for(int i=0;i<26;i++){
            if(tmp->next[i]!=NULL){
                if(tmp==root) tmp->next[i]->fail=root;
                else{
                    p=tmp->fail;
                    while(p!=NULL){
                        if(p->next[i]!=NULL){
                            tmp->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL) tmp->next[i]->fail=root;
                }
                que.push(tmp->next[i]);
            }
        }
    }
}


int Query(char *s,Node *root)
{
    int i=0,ret=0,idx;
    Node *p=root;
    while(s[i]){
        idx=s[i]-'a';
        while(p->next[idx]==NULL&&p!=root) p=p->fail;
        p=p->next[idx];
        p=(p==NULL)?root:p;
        Node *tmp=p;
        while(tmp!=root&&tmp->cnt!=0){
            ret+=tmp->cnt;
            tmp->cnt=0;
            tmp=tmp->fail;
        }
        i++;
    }
    return ret;
}


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        Node *root=new Node();
        for(int i=0;i<n;i++)
        {
            scanf("%s",keyword);
            Insert(keyword,root);

        }
        BuildAc(root);
        scanf("%s",str);
        printf("%d\n",Query(str,root));
    }
    return 0;
}
