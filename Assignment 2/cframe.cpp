/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

//CFrame.cpp
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "console.h"
#include "consoleplus.h"
#include "cframe.h"
#include "consolebackup.h"
using namespace std;

namespace cio { // continuation of cio namespace
CFrame::CFrame(int row, int col, int width, int height, bool visible, const char* border, CFrame* frame) {
	if(height < 0) {
		_fullscreen = true;  //when height or width is less than 0 , screen is full screen
		_row = row;
		_col = col;
		_width = console.getCols();
		_height = console.getRows();
		_border[0] = '\0';
		_visible = false;
		_cframe = frame;
		_covered = NULL;
	}
	else {
		_row = row;
		_col = col;
		_width = width;
		_height = height;
		_visible = visible; 
		if(border == NULL || strlen(border) < 8) {
			strcpy(_border, (char*)C_BORDER_CHARS);
		}
		else {
			strcpy(_border, border);
		}
		_border[8] = '\0';			
		_cframe = frame;
		_covered = NULL;
		_fullscreen = false;
	}
}
void CFrame:: goMiddle() {											 //set the ponter to the middle of the string
	if(_visible) {
		  console.setPosition(absrow() + 1, abscol() + _width / 2);  //set curpostion if border is visible
	}
	else {
		  console.setPosition(absrow(), abscol() - 1 + _width / 2);	 //set curpostion if border is not visible
	}	
}
void CFrame::bordered(bool b) {										 // set border visibility				
	_visible = b;
}
bool CFrame::bordered() const {										//return border visibility
	return _visible;
}
CFrame::~CFrame(){												   //destructor					
	if (_cframe) {
		delete[] (char*)_covered;
		_covered = NULL;
	}
}		
void CFrame::frame(CFrame* cf) {									//set parent frame
	_cframe = cf;
}
CFrame* CFrame::frame() const {										//return parent frame
	return _cframe;
}
void CFrame::setLine(char* str, char left, char fill, char right) const {
	int i;
	str[0] = left;
	for(i = 1; i < _width - 1; i++) {								//width -1 to fill right char at the end
		str[i] = fill;
	}
	str[i] = right;
	str[i + 1] = '\0';
}		
int CFrame::absrow() const {										//absrow function
	if(frame() == NULL || _fullscreen) {
		return _row; 
	}
	else {
		int r;	
		r = _row;
		CFrame* temp = frame();
		while(temp) {
			r += temp -> absrow();									//travelling to top most row
			temp = temp -> frame();									//find parent of parent till true
		}
	if(frame() -> bordered()) r++;
	free(temp);
	return r;
	}
}
int CFrame::abscol() const {										//abscol function
	if(frame() == NULL || _fullscreen) {
		return _row; 
	}
	else {
		int c;	
		c = _col;
		CFrame* temp = frame();
		while(temp) {	
			c += temp -> abscol();
			temp = temp -> frame();								//travelling  to left most col
		}
	if(frame() -> bordered()) c++;
	free(temp);
	return c;
	}	
}
		
void CFrame::capture() {										//capture memory area in pointer
	if(!_covered) {  
		_covered = cio::capture(absrow(), abscol(), _height, _width);
	}
} 
void CFrame::row(int r) {										//set row
	_row = r;
}

int CFrame::row() const {										//return row
	if(_fullscreen) {
		return 0;
	}
	return _row;
}	
void CFrame::col(int c) {										//set column
	_col = c;
}
int CFrame::col() const {										//return column
	if(_fullscreen) {
		return 0;
	}
	return _row;
}
void CFrame::height(int h) {									//set height
	_height = h;
}		
int CFrame::height() const {
	if(_fullscreen) {
		return cio::console.getRows();							//returns height of the screen, if fullscreen
	}
	return _height;
}
void CFrame::width(int w) {
	_width = w;
}
int CFrame::width() const {
	if(_fullscreen) {
		return cio::console.getCols();							//returns width of the screen, if fullscreen
	}
	return _width;
}	
void CFrame::draw(int fn) {										//when you want to figure out your position , use abscol(), absrow(). 
	int i;
	char* str;
	str = new char[width() + 1];
	for (i = 0; i <= width(); i++){
		str[i] = ' ';
	}
	capture();
	if (_visible && fn != C_NO_FRAME) {
		console.setPosition(absrow(), abscol());				//draw first line of frame
		setLine(str, _border[0], _border[1], _border[2]);		//it will fill str with border_chars
		console << str;				
		for (i = 0; i < (height() - 2); i++) {					//draw middle part of frame
				console.setPosition((absrow() + 1 + i), abscol());
				setLine(str, _border[7], ' ', _border[3]);	
				console << str;
		}
		console.setPosition((absrow() + 1 + i), abscol());		//draw last line of frame	
		setLine(str, _border[6], _border[5], _border[4]);
		console << str;
		}
	delete [] str;
}
void CFrame::hide(CDirection dir) {
	cio::restore(absrow(), abscol(), _height, _width, dir, _covered);
	cio::release((void**)&_covered);	
}		
void CFrame::move(CDirection dir) {
	if (dir == C_MOVED_DOWN) {
    			if(absrow() + _height < (_cframe -> absrow() + _cframe -> height() - 1)) {	
                	hide(dir);									//stop overlaping of parent and child border
                	_row = _row + 1;
                	draw();
            	} 
        	}   
	else if(dir == C_MOVED_UP) {
				if((absrow() > _cframe -> absrow() + 1) && absrow() > 0) {
                	hide(dir);
                	_row = _row - 1;
                	draw();
            	}
    }
    else if(dir == C_MOVED_LEFT) {
   				if((abscol() > _cframe -> abscol() + 1) && abscol() > 0) {
            		hide(dir);
    				_col=_col - 1;
            		draw();
   				}
   }
    else if(dir == C_MOVED_RIGHT) {
   				if((abscol() + _width) < (_cframe -> abscol() + _cframe -> width() - 1)) {
   					hide(dir);
   					_col=_col + 1;
					draw();
   				}
   			}
   else if(dir == C_STATIONARY){
        draw();
   }
 }

void move(cio::iFrame& im) {									//helper function
	int kp;														//store pressed key
	console.setPosition(0, 0);
	console << "Moving! use arrow keys, or ESC to exit";
	console >> kp;
	while(kp != ESCAPE) {										//move frame until ESCAPE
		if(kp == UP){
			im.move(C_MOVED_UP);
		}
		else if(kp == RIGHT){
			im.move(C_MOVED_RIGHT);
		}
		else if(kp == LEFT){
			im.move(C_MOVED_LEFT);
		}
		else if(kp == DOWN){
			im.move(C_MOVED_DOWN);
		}
	console >> kp;    
	}
	im.draw();
}
} //end of namespace