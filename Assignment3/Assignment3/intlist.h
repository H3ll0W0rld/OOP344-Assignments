/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

//intlist.h
//IntListNode class begin 
class IntListNode {
	int _value;
	IntListNode* _next;
	friend class IntList;
public:
	IntListNode(int val = int(), IntListNode* n = NULL);
	IntListNode(const IntListNode& src);
	IntListNode& operator=(const IntListNode& src);
	~IntListNode();
	int val() const;
	void val(int);
	IntListNode* next() const;
}; 

//IntList begin
class IntList {
	IntListNode* _head;
	int _size;
public:
	IntList();
	IntList(const IntList& src);
	IntList& operator=(const IntList& src);
	int size() const;
	IntListNode* head() const;
	void push(int val);
	void pop();
	void clear();
	~IntList();
}; 