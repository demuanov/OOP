#pragma once
#include "stdafx.h"
using namespace std;

template <class T>
class Container
{
	struct Element
	{
		Element *next;
		T value;
	};

public:
	Container()
	{
		head = NULL;
		tail = NULL;
		size = 0;


	}
	virtual ~Container()
	{
		while (size > 0)
		{
			del_first();
		}
	}

	void add_first(const T&x)
	{
		Element *first = new Element();
		first->value = x;
		first->next = head;
		if (head != NULL)
		{
			head = first;
		}
		else
		{
			head = first;
			tail = first;
		}
		size++;

	}


	void add_last(const T&x)
	{
		Element *lastElement =new Element();
		lastElement->value = x;
		if (head != NULL)
		{
			tail->next = lastElement;
			tail = lastElement;
		}
		else
		{
			head = lastElement;
			tail = lastElement;
		}
		size++;
	}

	void del_first()
	{		
		if (head != NULL)
		{
			if (tail != head)
			{
				Element *delElement = head;
				head = head->next;
				delete delElement;
			}
			else
			{
				delete head;
				head = NULL;
				tail = NULL;
			}

		}
		else
			throw "None first Element";
		size--;
	}

	void del_last()
	{
		if (isEmpty()) throw "None last Element";
			
		
			if (head != tail)
			{
				Element *last = head;
				while (last->next != tail)
				{
					last = last->next;
				}
				delete tail;
				tail = last;
				last->next = NULL;
			}
			else
			{

				delete head;
				head = NULL;
				tail = NULL;
			}
			size--;
		}

	

	T get_first()
	{
		if (head == NULL) throw "None first element";
		else
		{
			return head->value;
		}	
			
	}

	T get_last()
	{
		if (head == NULL) throw "None first element";
		else
		{
			return tail->value;
		}
	}

	void print()
	{
		if (head != NULL) {
			Element *elem = head;
			while (elem != NULL)
			{
				std::cout << elem->value << std::endl;
				elem = elem->next;
			}
		}
	}


	
	bool isEmpty()
	{
		if (size > 0)
			return false;
		else
			return true;
	}
		
	
	int getsize()
	{
		return size;
	}

	void terminator()
	{
		while (size>0)
		{
			del_first();
		}
	}
private:
	int size = 0;
	Element *head;
	Element *tail;
	

};


