/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

//CLine.cpp
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "cline.h"
#include "consoleplus.h"
#include "console.h"

namespace cio {
CLine::CLine(const char* str, int row, int col, int length, int maxChars, bool* insertMode, bool bordered,				
		const char* border) : CField(row, col, length, (bordered) ? 3 : 1, (void*) str, bordered, border) {
	_curpos = 0;
	_offset = 0;									//constructor which set temporary variables and initiaze string
	_tmp_insertMode = insertMode;
	_maxchars = maxChars; 
	allocateAndCopy(str);
}
CLine::CLine(int row, int col, int length, int maxChars, bool* insertMode, bool bordered,
		const char* border) : CField(row, col, length, (bordered) ? 3 : 1, (void*)NULL, bordered, border) {
	_curpos = 0;								   //constructor which set temporary variables and initiaze empty string
	_offset = 0;
	_maxchars = maxChars;  
	_tmp_insertMode = insertMode;
	allocateAndCopy("");
}
CLine::~CLine() { 
		delete [] _data;						  //delete fields data
		_data = (void*)NULL;
}
void CLine::allocateAndCopy(const char* Str) {	  //allocate maxchars length memory to string		
		_data = new char[_maxchars + 1];
		strcpy((char*)_data, Str);
		for(int i = strlen(Str); i < _maxchars; i++) {
			((char*)_data)[i] = (char)NULL;
		}
		((char*)_data)[_maxchars] = '\0';
}
void CLine::draw(int n) {						 //draw function which draws frame and data
	CFrame::draw();
	cio::display((char*)data() + _offset, absrow() + 1, abscol() + 1, bordered() ? width() - 2 : width());	
}	
int CLine::edit() {								//retuen pressed key and handles editing of string
	return cio::edit((char*)data(), absrow() + 1, abscol() + 1,bordered() ? width() - 2 : width(), _maxchars,
	_tmp_insertMode, &_offset, &_curpos);
}
bool CLine::editable() const {					//return true
	return true;
}		
void CLine::set(const void* temp) {				//set function which discard and initialize new string
	if(data() != (void*)NULL) {
		delete [] (char*)_data;
		_data = (void*)NULL;
	}
	allocateAndCopy((char*)temp);
}
}												//end of cio
