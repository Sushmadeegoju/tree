hello
#include<iostream>
using namespace std;
struct node * insert(struct node *r,int n);
void inorder(struct node * r);
int search(struct node * r,int n );
struct node * del(struct node * r,int n);
void levelorder(struct node *root);
void givenorder(struct node *r,int l);
void morristraversal(struct node *root);

struct node
{
	struct node * lptr=NULL;
	struct node * rptr=NULL;
	int value;
}*root;


main()
{
	int s,n;
    root=NULL;
	while(1)
	{
		cout<<"enter one among the folllowing"<<endl<<"1.insert"<<endl<<"2.inorder"<<endl<<"3.level order"<<endl<<"4.search"<<endl<<"5.delete"<<endl<<"6.morris traversal(no recursion and no stack)"<<endl<<"7.exit"<<endl;
		cin>>s;
		switch(s)
		{
			case 1:
				cout<<"enter the number to be inserted";
				cin>>n;
				insert(root,n);
				if(root==NULL)
				cout<<"yup";
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				levelorder(root);
				break;
			case 4:
				cout<<"enter the element to be searched";
				cin>>n;
				if(search(root,n))
				cout<<"the element is found";
				else
				cout<<"the element is not found";
				break;
			case 5:
				cout<<"enter the node to be deleted";
				cin>>n;
				root=del(root,n);
				break;
			case 6:
				morristraversal(root);
				break;
			case 7:
				return 0;
		}
	}
}

struct node* insert(struct node *r,int n)
{
	if(r==NULL)
	{
		if(root==NULL)
		{
			root=new node;
			root->value=n;
		}
		else
		{
		r=new node;
		r->value=n;
		return r;
    	}
		
	}
	else if((r->value)>n)
	r->lptr=insert(r->lptr,n);
	else
    r->rptr=insert(r->rptr,n);
}

void inorder(struct node * r)
{
	if(r==NULL)
	{
		return;
	}
	inorder(r->lptr);
	cout<<(r->value)<<endl;
	inorder(r->rptr);
}

int search(struct node * r,int n )
{
	if(r!=NULL)
	{
	int k=0;
	if(r->value==n)
	k=1;
	else if(r->value>n)
	k=search(r->lptr,n);
	else
	k=search(r->rptr,n);
	return k;
}
}
struct node * insuc(struct node *r)
{
	struct node * current=r->rptr;
	while(current->lptr!=NULL)
	{
		current=current->lptr;
	}
	return current;
}

struct node * del(struct node * r,int n)
{
	if(r==NULL)
	return r;
	else if(n<r->value)
	r->lptr=del(r->lptr,n);
	else if(n>r->value)
	r->rptr=del(r->rptr,n);
	else
	{
		if(r->lptr==NULL)
		{
			struct node *temp;
	    	temp=r->rptr;
	    	delete(r);
	    	return temp;
		}
		else if(r->rptr==NULL)
		{
			struct node * temp;
			temp=r->lptr;
			delete(r);
			return temp;
		}
		struct node *t=insuc(r);
		r->value=t->value;
		r->rptr=del(r->rptr,t->value);
	}
	return r;
}

int height(struct node *r)
{
	if(r==NULL)
	return 0;
	else
	{
		if(height(r->lptr)>height(r->rptr))
		return 1+height(r->lptr);
		else
		return 1+height(r->rptr);
	}
}


void levelorder(struct node *root)
{
	int h=height(root);
	for(int i=1;i<=h;i++)
	{
		givenorder(root,i);
		cout<<endl;
	}
}

void givenorder(struct node *r,int l)
{
	if(r==NULL)
	return ;
	else
	{
		if(l==1)
		cout<<r->value<<" ";
		else if(l>1)
		{
			givenorder(r->lptr,l-1);
			givenorder(r->rptr,l-1);
		}
	}
}

void morristraversal(struct node *root)
{
	struct node * pre,*current;
	current=root;
	while(current!=NULL)
	{
		if(current->lptr==NULL)
		{
			cout<<current->value<<"  ";
			current=current->rptr;
		}
		else
		{
			pre=current->lptr;
			while(pre->rptr!=NULL&&pre->rptr!=current)
			pre=pre->rptr;
			if(pre->rptr==NULL)
			{
				pre->rptr=current;
				current=current->lptr;
			}
			else if(pre->rptr==current)
			{
				pre->rptr=NULL;
				cout<<current->value<<"  ";
				current=current->rptr;
			}
		}
	}
}



