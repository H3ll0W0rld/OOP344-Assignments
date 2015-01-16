/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

//CField.cpp
#include "cfield.h"
namespace cio {	
CField::CField(int row, int col, int width, int height, void* data , bool visible, const char* border) : CFrame(row, col, width, height, visible, border) {
	_data = data;
}
CField::~CField() {}					//Empty constructor only that does nothing
void* CField::data() const { 			//data getters 	
		return _data;
}
void CField::data(void* temp_data) {	//data setters
	_data = temp_data;
}  	
}										//end of cio for now