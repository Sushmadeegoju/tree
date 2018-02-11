#include<iostream>
using namespace std;

struct node
{
	struct node* ln=NULL;
	struct node* rn=NULL;
	int value;
}*root=NULL;

struct node * ipn(int a[],int c,int n)
{
   	struct node *temp=new node;
   	temp->value=a[c-1];
    if(2*c<=n)
    {
        temp->ln=ipn(a,2*c,n);
	}
	if(2*c+1<=n)
	{
        temp->rn=ipn(a,2*c+1,n);
	}
	return temp;
}
void display(struct node * r)
{
	if(r!=NULL)
	{
		display(r->ln);
		cout<<r->value<<"  ";
		display(r->rn);
	}
}

main()
{
	int n,i;
	cout<<"enter no of nodes";
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	root=ipn(a,1,n);
	display(root);
}


