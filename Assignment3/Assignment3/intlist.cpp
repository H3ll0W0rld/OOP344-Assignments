/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

//intlist.cpp 
//IntListNode class begin
#include <iostream>
#include "intlist.h"
IntListNode::IntListNode(int val, IntListNode* next) {						//two-arguments constructor, initialize values 
	_value = val;
	_next = next;
}
IntListNode::IntListNode(const IntListNode& src) {							//copy-constructor
	_value = src._value;
	_next = NULL;
}
IntListNode& IntListNode::operator=(const IntListNode& src) {				//assignment operator
	if (this != &src) {
		_value = src._value;
		_next = NULL;
	}
	return *this;
}
int IntListNode::val() const {												//value getters, returns current value 
	return _value;
}
void IntListNode::val(int v) {												//value setters
	_value = v;
}
IntListNode* IntListNode::next() const {									//next getters, returns address of next pointer
	return _next;
}
IntListNode::~IntListNode(){ };												//empty destructor
//End of IntListNode class


//IntList class begin
IntList::IntList() {														//constructor, assign safe empty state to variables
	_size = 0;
	_head = NULL;
}
int IntList::size() const{													//returns number of nodes in the list 
	return _size;
}
IntListNode* IntList::head() const {										//returns address of the head/ first pointer
	return _head;
}
void IntList::push(int v) {													//push function, adds node at the end of the list
	IntListNode* n = new IntListNode(v);
	IntListNode* h = _head;
	for (; h&&h->next(); h = h->next());
	if (h) {
		h -> _next = n;
	}
	else {
		_head = n;
	}
	_size++;
}
void IntList::pop() {														//pop function, remove last node
	if (_size == 0) return;
	if (_size == 1){
		delete _head;
		_head = NULL;
	}
	else {
		IntListNode* h = _head;
		for (int i = 0, end = _size - 2; i < end;i++, h = h->next());
		delete h->_next;
		h->_next = NULL;
	}
	_size--;
}
void IntList::clear() {														//clear function, remove all nodes from the list
	while (size() > 0) {
		pop();
	}
}
IntList::IntList(const IntList& src) {										//copy constructor
	_size = 0;
	_head = NULL;
	*this = src;
}
IntList& IntList::operator=(const IntList& src) {							//assignment operator
	if (this != &src) {
			clear();	
			IntListNode * node = src._head;
			for (int i = 0; i < src.size(); i++) {    
				push(node->_value);
				node = node ->_next;
			}
	}
	return *this;
}
IntList::~IntList() {														//destructor, which destructs all the nodes
	clear();
}	
//IntList class end 