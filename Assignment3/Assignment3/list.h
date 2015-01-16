/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

//List.h
//Templated Linked List
//listnode class begin
template<class U>											//Forward declaration for List class
class List;
template<class T>
class ListNode {											//ListNode class contains value and next pointer
	T _value;
	ListNode* _next;
	template<class U>
	friend class List;
public:
ListNode(const T& val = T(), ListNode* n = NULL) {			//two argument constructor
		_value = val;
		_next = n;
}
ListNode(const ListNode& src) {								//copy constructor
		_value = src._value;
		_next = NULL;
}
ListNode& operator=(const ListNode& src) {					//assignment operator
		if (this != &src) {
		_value = src._value;
		_next = NULL;
	}
	return *this;
}
T val() const {												//value getters, which returns value 
	return _value;
}
void val(const T& v) {										//value setters, sets the value						
	_value = v;
}
ListNode<T>* next() const {									//next getters
	return _next;
}
~ListNode() {}												//destructor
}; 
//Listnode class end

//List class begin
template<class T>											//List class which handles nodes
class List {									
	ListNode<T>* _head;
	int _size;
public:
List() {													//list constructor
	_size = 0;
	_head = NULL;
}
List(const List& src) {										//copy constructor
	_size = 0;
	_head = NULL;
	*this = src;
}
List& operator=(const List& src) {							//assignment operator
	if (this != &src) {
			clear();	
			ListNode<T> * node = src._head;
			for (int i = 0; i < src.size(); i++) {    
				push(node->_value);
				node = node ->_next;
			}
	}
	return *this;
}

int size() const {											//size getters
	return _size;
}
ListNode<T>* head() const {									//head getters, returns first node
	return _head;
}
void push(const T& v) {										//push function, add node at the end of the list
	ListNode<T>* n = new ListNode<T>(v);
	ListNode<T>* h = _head;
	for (; h&&h->next(); h = h->next());
	if (h) {
		h -> _next = n;
	}
	else {
		_head = n;
	}
	_size++;
}
void pop() {												//pop function, remove last node
	if (_size == 0) return;
	if (_size == 1){
		delete _head;
		_head = NULL;
	}
	else {
		ListNode<T>* h = _head;
		for (int i = 0, end = _size - 2; i < end;i++, h = h->next());
		delete h->_next;
		h->_next = NULL;
	}
	_size--;
}
void clear() {												//clear function, remove all nodes
	while (size() > 0){
		pop();
	}
}
~List() {													//list destructor
	clear();
}
}; //List class end

