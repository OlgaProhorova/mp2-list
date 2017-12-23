#include "list.h"

List::List(const List& list2)
{
	if (list2.head != NULL)
	{
		head = new Node (list2.head->data,list2.head->next);
		Node *tmp = head;
		Node *tmp2 = list2.head->next;
		while (tmp2 != NULL)
		{
			tmp->next = new Node(tmp2->data, tmp2->next);
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
	}
	else
		head = NULL;
};

List& List::operator=(const List& list2)
{
	if (this != &list2)
	{
		Clean();
		if (list2.head == NULL)
		{
			head = NULL;
		}
		else
		{
			head = new Node (list2.head->data,list2.head->next);
			Node *tmp = head;
			Node *tmp2 = list2.head->next;
			while (tmp2 != NULL)
			{
				tmp->next = new Node(tmp2->data, tmp2->next);
				tmp = tmp->next;
				tmp2 = tmp2->next;
			}
		}
	}
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
	if (head == NULL) throw "Empty list.";
	if (node!=NULL)
	{

		Node*tmp = head;
		while (tmp!=node)
		{
			tmp=tmp->next;
		}
		tmp->next = new Node(d,tmp->next);
	}
};

void List::Delete(const DataType& d)
{
	Node* tmp = head, *prev=NULL;
	if (tmp != NULL)
	{
		while ((tmp != NULL)&&(tmp->data!=d))
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if(tmp!=NULL)
		{
			if(prev!=NULL)
				prev->next = tmp->next; 
			else 
				head = tmp->next; 
			delete tmp;
		}
	}
};

Node* List::Search(const DataType& d)
{
	Node* tmp = head;
	while (tmp!=NULL)
	{
		if(tmp->data==d) return tmp;
		else tmp = tmp->next;
	}
	return tmp;
};

void List::Clean()
{
	Node *tmp1 = head;
	Node *tmp2 = head;
	if (tmp1 != NULL)
	{
		while (tmp1->next != NULL)
		{
			tmp2 = tmp1->next;
			delete tmp1;
			tmp1 = tmp2;
		}
		delete tmp1;
		head = NULL;
	}
};

int List::GetSize()
{
	Node *tmp=head;
	int size=0;
	while(tmp!=NULL)
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
	if (head != NULL)
	{
		Node *tmp1 = head;
		Node *tmp2 = NULL;
		Node *tmp3 = head->next;
		if ((tmp1 != NULL) && (tmp1->next != NULL))
		{
			do
			{
				tmp3 = tmp1->next;
				tmp1->next = tmp2;
				tmp2 = tmp1;
				tmp1 = tmp3;
			} while (tmp1 != NULL);
			head = tmp2;
		}
	}
};

List List::Merge(Node* node, const List& list2)
{
	if (head != NULL)
	{
		List list3;
		list3.head = new Node(head->data, NULL);
		Node* tmp = list3.head;
		Node* tmp1 = head;
		while ((tmp1->next!=NULL) && (tmp1 != node))
		{
			tmp->next = new Node(tmp1->next->data, NULL);
			tmp = tmp->next;
			tmp1 = tmp1->next;
		}
		if (node != NULL)
		{
			Node* tmp2 = list2.head;
			while (tmp2 != NULL)
			{
				tmp->next = new Node(tmp2->data,NULL);
				tmp = tmp->next;
				tmp2 = tmp2->next;
			}
			while (tmp1->next!=NULL)
			{
				tmp->next = new Node(tmp1->next->data, NULL);
				tmp = tmp->next;
				tmp1 = tmp1->next;
			}
		}
		return list3;
	}
	else
	{
		List l3(list2);
		return l3;
	}
}; 

List List::Merge(const List& list2)
{

	if (head != NULL)
	{
		if (list2.head == NULL)
			return *this;
		List list3(*this);
		Node* tmp = list3.head, *tmp2 = list2.head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node(list2.head->data,NULL);
		tmp = tmp->next;
		tmp2 = tmp2->next;
		while (tmp2)
		{
			tmp->next = new Node(tmp2->data, NULL);
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		return list3;
	}
	else
	{
		List l3(list2);
		return l3;
	}
}; 

bool List::operator ==(const List & list2) const
{
	Node *tmp1,*tmp2;
	tmp1=head;
	tmp2=list2.head;
	if((head==NULL)&&(list2.head==NULL)) return true;
	while((tmp1!=NULL)&&(tmp2!=NULL))
	{
		if(tmp1->data!=tmp2->data)return false;
		tmp1=tmp1->next;
		tmp2=tmp2->next;
	}
	if((tmp1!=NULL)||(tmp2!=NULL))return false;
	return true;
}

ostream& operator<<(ostream& os, const List& l)
{
	List list;
	Node*tmp = list.head;
	while (tmp != NULL)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	return os;

}