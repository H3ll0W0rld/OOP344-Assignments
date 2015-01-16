/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

//CLabel.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "clabel.h"
#include "consoleplus.h"
#include <cstring>
#include "console.h"
using namespace std; 

namespace cio {
CLabel::CLabel(const char* lbl_data, int row, int col, int length) : CField(row, col, length) {
	if(strlen(lbl_data) > length) {									//constructor which allocate memory as 
		width(length - 2);											//per length and string length
		allocateAndCopy(lbl_data);  	
	}
	else {
		if(length > 0) {
			width(length);
			allocateAndCopy(lbl_data);
		}
		else {
			width(strlen(lbl_data));
			allocateAndCopy(lbl_data);
		}
	}	
}		

CLabel::CLabel(int row, int col, int length) : CField(row, col, length)  {
		width(length);												//construcotr which stores empty string in data
		allocateAndCopy((char*)"");
}
CLabel::~CLabel() {													//deallocation of memory
	if(data()) {
		delete[] (char*)_data;
		_data = (void*)NULL;
	}
}
CLabel::CLabel(const CLabel& L) : CField(L) {						//copy constructor
	if(this != &L) {
		height(L.height());
		width(L.width());
		row(L.row());												// seting member variables
		col(L.col());
		if(L._data != NULL) { 
			if(_data) {	
				delete [] (char*)_data;
				data((void*)NULL);
			}
		allocateAndCopy((char*)L._data);
		}
		else {
			data((void*)NULL);
		}
	}
}
void CLabel::allocateAndCopy(const char* Str) {						//function which allocate memory
	if(strlen(Str) < width()) {
		_data = new char[width() + 1];								//width of field + 1 
		strcpy((char*)_data, Str);
		((char*)_data)[width()] = '\0';								//calling CField data setter
	}
	else {
		_data = new char[width() + 1];								//width of field + 1 
		strncpy((char*)_data, Str, width());
		((char*)_data)[width()] = '\0';								//calling CField data setter
	}
}
void CLabel::draw(int n) {											//draw function
	CFrame::draw(n);
	cio::display((char*)_data, absrow() + 1, abscol() + 1, width());	
}			
int CLabel::edit() {											   //edit which returns not editabe
	draw();
	return C_NOT_EDITABLE;
}
bool CLabel::editable() const {										//return false
	return false;
}
void CLabel::set(const void* str) {									//set function to allocate string length memory
	width(strlen((char*) str));
	if(_data) {
		delete [] (char*)_data;
		data((void*)NULL);
	}
	allocateAndCopy((char*)str);
}
}																	//end of cio 