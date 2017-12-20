#include "list.h"

List::List(const List& list2)
{
	if(list2.head!=NULL) head=list2.head;
	else throw "ps";
};

List& List::operator=(const List& list2)
{
	if(list2.head!=NULL) head=list2.head;
	else throw "ps";
	return *this;
};

void List::InsertToHead(const DataType& d)
{
	Node *n=new Node(d,head);
	head=n;
};

void List::InsertToTail(const DataType& d)
{
	Node *tmp;
	tmp=head;
	if(head==NULL) head = new Node(d,NULL);
	else 
	{
		while(tmp->next!=NULL)
			tmp=tmp->next;
		tmp->next=new Node(d,NULL);
	}
}; 

void List::InsertAfter(Node* node, const DataType& d) 
{
	Node *n=new Node(d,node->next);
	node->next=n;
};

void List::Delete(const DataType& d)
{
	Node *pred,*tmp;
	tmp=head;
	pred=NULL;
	while((tmp->data!=d)&&(tmp!=NULL))
	{
		pred=tmp;
		tmp=tmp->next;
	}
	if(pred!=NULL) pred->next=tmp->next;
	else head=tmp->next;
	delete tmp;
};

Node* List::Search(const DataType& d)
{
	Node *tmp;
	tmp=head;
	while((tmp->data!=d)&&(tmp->next!=NULL))
			tmp=tmp->next;
	return tmp;
};

void List::Clean()
{
	Node *tmp=head,*n;
	while(tmp->next!=NULL)
	{
		n=tmp->next->next;
		delete tmp->next;
		tmp->next=n;
	}
	tmp->data=0;
};

int List::GetSize()
{
	Node *tmp;
	int size=0;
	tmp=head;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
		size++;
	}
	return size;		
};

Node* List::GetHead()
{
	return head;
}; 

void List::Inverse()
{
	Node *tmp1,*tmp2,*tmp3;
	tmp1=head;
	tmp2=head->next;
	tmp1->next=NULL;
	while(tmp2!=NULL)
	{
		tmp3=tmp2->next;
		tmp2->next=tmp1;
		tmp1=tmp2;
		tmp2=tmp3;
	}
};

List List::Merge(Node* node, const List& list2)
{
	List newlist;
	newlist.head=head;
	Node *tmp1,*tmp2;
	tmp1=node->next;
	node->next=list2.head;
	tmp2=list2.head;
	while(tmp2->next!=NULL)
		tmp2=tmp2->next;
	tmp2->next=tmp1;
	return newlist;
}; 

List List::Merge(const List& list2)
{
	List newlist;
	newlist.head=head;
	Node *tmp;
	tmp=head;
	while(tmp->next!=NULL)
		tmp=tmp->next;
	tmp->next=list2.head;
	return newlist;
}; 

bool List::operator ==(const List & list2) const
{
	Node *tmp1,*tmp2;
	tmp1=head;
	tmp2=head;
	while((tmp1->next!=NULL)&&(tmp2->next!=NULL))
	{
		if(tmp1!=tmp2)return false;
		tmp1=tmp1->next;
		tmp2=tmp2->next;
	}
	if(((tmp1->next!=NULL)&&(tmp2->next==NULL))||((tmp1->next==NULL)&&(tmp2->next!=NULL)))return false;
	return true;
}
