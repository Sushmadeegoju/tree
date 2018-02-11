#include<iostream>
using namespace std;
struct node * insert(node * r,int n);
struct node
{
	int height=1;
	int key;
	int bal;
	node * lptr=NULL;
	node * rptr=NULL;
}*root;

void preorder(struct node *p)
{

    if(p!=NULL)
    {
        preorder(p->lptr);
        cout<<(p->key)<<"  "<<"height:"<<p->height<<"  "<<"balance:"<<p->bal<<endl;
        preorder(p->rptr);
    }
    else
    return;
}

int height(struct node *p)
{
	if(p==NULL)
	return 0;
	else
	return p->height;
}

int getbal(struct node* r)
{
	if(r==NULL)
	return 0;
	return height(r->lptr)-height(r->rptr);
}


int max(int a,int b)
{
	if(a>=b)
	return a;
	else
	return b;
}
struct node * rotateleft(node* r)
{
	node *y=r->rptr;
	node * t2=y->lptr;
	y->lptr=r;
	r->rptr=t2;
	r->height=1+max(height(r->lptr),height(r->rptr));
	y->height=1+max(height(r->lptr),height(r->rptr));
	r->bal=getbal(r);
	y->bal=getbal(y);
	return y;
}
struct node * rotateright(node * r)
{
	node * y=r->lptr;
	node *t2=y->rptr;
	y->rptr=r;
	r->lptr=t2;
	r->height=1+max(height(r->lptr),height(r->rptr));
	y->height=1+max(height(r->lptr),height(r->rptr));
	r->bal=getbal(r);
	y->bal=getbal(y);
	return y;
}
struct node * insert(node * r,int n)
{
	if(r==NULL)
	{
		r=new node;
		r->key=n;
	    r->bal=getbal(r);
	    r->height=1+max(height(r->lptr),height(r->rptr));
		return r;
	}
	else
	{
		if(n>=(r->key))
		r->rptr=insert(r->rptr,n);
		else
		r->lptr=insert(r->lptr,n);
		r->height=1+max(height(r->lptr),height(r->rptr));
		r->bal=getbal(r);
		int bal=r->bal;
		if(bal<-1&&n>=r->rptr->key)
		{
			cout<<"right right"<<endl;
			return rotateleft(r);
		}
		if(bal>1&&n<r->lptr->key)
		{
			cout<<"left left"<<endl;
			return rotateright(r);
		}
		if(bal>1&&n>=r->lptr->key)
		{
			cout<<"left right"<<endl;
			r->lptr=rotateleft(r->lptr);
			return rotateright(r);
		}
		if(bal<-1&&n<r->rptr->key)
		{
			cout<<"right left"<<endl;
			r->rptr=rotateright(r->rptr);
			return rotateleft(r);
		}
		return r;
	}
	
	
	
}

main()
{
	root=NULL;
	int n;
	while(1)
	{
		cin>>n;
		root=insert(root,n);
		root->height=1+max(height(root->lptr),height(root->rptr));
		preorder(root);
	}
}
