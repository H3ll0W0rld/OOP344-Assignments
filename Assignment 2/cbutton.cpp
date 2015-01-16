/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

//cbutton.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "cbutton.h"
#include <cstring>
#include "console.h"
#include "consoleplus.h"
using namespace std;

namespace cio {
void CButton:: allocateAndCopy(const char* str) {
	unsigned int i;
	char* temp = new char[strlen(str) + 3];							//prefix + suffix + 1
	temp[0]=' ';

	for (i = 1; i < strlen(str) + 1; i++) {
		temp[i] = str[i - 1];
	}
	temp[i] = ' ';
	temp[i + 1] = '\0';
	data((void*)temp);												//setting CField new string with prefix and suffix
}
CButton::CButton(const char *Str, int Row, int Col, bool Bordered, const char* Border) 
		: CField(Row, Col, (Bordered) ? (strlen(Str) + 4) : (strlen(Str) + 2), (Bordered) ? (3) : (1), NULL, Bordered , Border) {	
			allocateAndCopy(Str);									//leave enough space for the prefix/suffix characters [ ] 			
}
CButton::~CButton() {												//destructor, deallocate memory
	if(data()) {
		delete[] (char*)_data;
	}
}
void CButton::draw(int fn) {										//draw function which draw border and string
	CFrame::draw();
	if(bordered()) {
		cio::display((char*)data(), absrow() + 1, abscol() + 1, 0);
	}
	else {
		cio::display((char*)data(), absrow(), abscol(), 0);
	}
}
int CButton:: edit() {												//edit function which does multiple things in once
	char* str = new char [strlen((char*)data()) + 1];				//setting string with "[" and "]"
	strcpy(str, (char*)data());										//Cfield getters
	str[0] = '[';
	str[strlen(str) - 1] = ']';
	str[strlen(str)] = '\0'; 
	data((void*)str);												//Cfield setters
	CButton::draw();												//draw new string
	CFrame::goMiddle();												//goto the middle of string
	int key;
	console >> key;													//take key and return key if ESCAPE or SPACE
	if (key == ENTER || key == SPACE) {
		key = C_BUTTON_HIT;
	}
	str[0] = ' ';													//set string to previous state
	str[strlen(str) - 1] = ' ';
	data((void*)str);												//Cfield setters
	CButton::draw();												//draw new string
	CFrame::goMiddle();												//goto the middle of string
	return key;														//return key
}
bool CButton:: editable()const {									//return true
	return true;
}
void CButton:: set(const void* str) {								//set new string and height and width
	if(data()) {
		delete[] (char*)data();
	}
	allocateAndCopy((char*)str);
	CFrame::height((CFrame::bordered()) ? (3) : (1));
	CFrame::width((CFrame::bordered()) ? (strlen((char*)str) + 4) : (strlen((char*)str) + 2));
}
}																	//end of cio