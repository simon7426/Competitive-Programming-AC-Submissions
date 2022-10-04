#include<bits/stdc++.h>
using namespace std;

struct item
{
    int prio,val,cnt,sum;
    bool rev;
    item *l, *r;
};

item treap [100010];
int t_cnt=0;
vector<int> ran;
item *root;


int cnt(item *t)
{
    return t? t->cnt:0;
}

int sum(item *t)
{
    return t? t->sum:0;
}

void update_cnt(item *t)
{
    if(!t) return;
    t->cnt=1+cnt(t->l)+cnt(t->r);
    t->sum=t->val+sum(t->l)+sum(t->r);
}

void push(item *t)
{
    if(!t->l&&!t->r) return;
    if(t && t->rev)
    {
        t->rev = false;
        swap(t->l,t->r);
        if(t->l) t->l->rev^=1;
        if(t->r) t->r->rev^=1;
    }
}

void merge(item *&t,item *l,item *r)
{
    if(l) push(l);
    if(r) push(r);
    if(!l)
        t=r;
    else if(!r)
        t=l;
    else if(l->prio < r->prio)
        merge(l->r,l->r,r),t=l;
    else
        merge(r->l,l,r->l),t=r;
    update_cnt(t);
}

void split (item *t, item *&l,item *&r,int key)
{
    if(t) push(t);
    if(!t)
       {
           l = r= NULL;
           return;
       }

    else if(key<=cnt(t->l))
    {
        split(t->l,l,t->l,key),r=t;
    }
    else
    {
        split(t->r,t->r,r,key-cnt(t->l)-1),l=t;
    }
    update_cnt(t);
}

void add(item *&t,item *it,int idx)
{
    if(!t) t=it;
    else if(it->prio < t->prio)
        split(t,it->l,it->r,idx),t=it;
    else
    {
        if(idx<= cnt(t->l))
            add(t->l, it, idx);
        else
            add(t->r,it,idx-cnt(t->l)-1);
    }
    update_cnt(t);
}

void add(int idx,int val)
{
    item *it = &treap[t_cnt];
    it->val=val;
    it->prio=ran[t_cnt];
    ++t_cnt;
    it->cnt=1;
    it->rev=0;
    add(root,it,idx);
}

void remove(item *&t,int idx)
{
    if(idx==cnt(t->l))
        merge(t,t->l,t->r);
    else
    {
        if(idx < cnt(t->l))
            remove(t->l,idx);
        else
            remove(t->r,idx-cnt(t->l)-1);
    }
    update_cnt(t);
}

void remove(int idx)
{
    remove(root,idx);
}

void reverse(item *t,int l,int r)
{
    item *t1, *t2, *t3;
    split(t,t1,t2,l);
    split(t2,t2,t3,r-l+1);
    t2->rev^=1;
    merge(t,t1,t2);
    merge(t,t,t3);
}

void replace(item *&t,int idx,int val)
{
    if(idx==cnt(t->l))
        t->val=val;
    else
    {
        if(idx< cnt(t->l))
            replace(t->l,idx,val);
        else
            replace(t->r,idx-cnt(t->l)-1,val);
    }
    update_cnt(t);
}

int query(int a,int b)
{
    item *l1,*r1;
    split(root,l1,r1,b+1);
    item *l2,*r2;
    split(l1,l2,r2,a);
    int ans=sum(r2);

    item *t;
    //cout<<ans<<endl;
    merge(t,l2,r2);

    merge(root,t,r1);
    return ans;
}

void replace(int idx,int val)
{
    replace(root,idx,val);
}

void output(item *t)
{
    if(!t) return;
    push(t);
    output(t->l);
    printf("%d %d\n",t->val,t->sum);
    output(t->r);
}
int a[100010];

main()
{
    int n,q,i,j;
    cin>>n>>q;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=1;i<=n+q;i++)
        ran.push_back(i);
    random_shuffle(ran.begin(),ran.end());
    for(i=0;i<n;i++)
    {
        add(i,a[i]);
    }
    for(i=0;i<q;i++)
    {
        int id,l,r;
        cin>>id>>l>>r;
        if(id==1)
        {
            add(l-1,r);
        }
        else if(id==2)
        {
            remove(l-1);
        }
        else if(id==3)
            replace(l-1,r);
        else if(id==4)
        {
            reverse(root,l-1,r-1);
        }
        else
        {
        int res=query(l-1,r-1);
        cout<<res<<endl;
        }
    }

}

