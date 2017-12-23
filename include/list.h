#ifndef __AISD_LIST__
#define __AISD_LIST__

#include <iostream>
using namespace std;

typedef int DataType;

struct Node
{
  DataType data;
  Node* next;
public:
  Node(DataType a=0,Node* n=NULL)
  {
	  data=a; 
	  next=n;
  };
  ~Node(){};// здесь могут быть конструкторы, методы, деструктор Node
  Node& operator=(const Node& node2)
  {
	   if(this!=&node2)
	   {
		   data = node2.data;
		   next = node2.next;
	   }
	   return *this;
  };
  bool operator==(const Node& node2) const
  {
	   if (data != node2.data) return false;
	   else return true;
  };
};

class List
{
  Node* head;// любые поля
public:
  List() 
  {
	  head=NULL;
  };
  List(const List& list2);
  List& operator=(const List& list2);
  ~List() 
  {
	  Node *tmp=head,*n;
	  if(head!=0)
	  {
		while(tmp->next!=NULL)
		{
		  n=tmp->next->next;
		  delete tmp->next;
		  tmp->next=n;
		}
		delete tmp;
	  }
  };
  void InsertToHead(const DataType& d); // вставить элемент d первым
  void InsertToTail(const DataType& d); // вставить элемент d последним
  void InsertAfter(Node* node, const DataType& d); // вставить элемент d после звена node
  void Delete(const DataType& d); // удалить звено со значением data = d
  Node* Search(const DataType& d); // найти указатель на звено со значением data = d
  void Clean(); // удалить все звенья
  int GetSize(); // узнать число звеньев в списке
  Node* GetHead(); // получить указатель на первое звено списка
  bool operator ==(const List & list2) const;
  void Inverse(); // инвертировать список, т.е. звенья должны идти в обратном порядке
  List Merge(Node* node, const List& list2); // создать список3, добавив список2 в текущий список после указателя node  
  List Merge(const List& list2); // создать список3, добавив в конец текущего списка список2

  friend ostream& operator<<(ostream& os, const List& l);
};

#endif