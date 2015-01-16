/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

/* Assignment 1											*/
/* Line editing facility								*/
/* consolelineedit.cpp									*/
/* This assignment basically focus on editing and displaying a string and manipulating it passed by another functions. */

#define _CRT_SECURE_NO_WARNINGS		//supress the errors/warnings caused because of strcpy_s for this program

#include <iostream>					
#include <cstring>
using namespace std;
#include "console.h"		//The Header file which contains Prototypes for display and edit function	
#include "consoleplus.h"	// Console Input Output Library Header File
#include "keys.h"			//Header file which contains #define key codes

namespace cio {
void display(const char *str, int row, int col, int fieldLen) {		//Body of the display function
	
	if(!str) {											//return back from function, if str is NULL
		return;
	}
	int t = 0;											//variable declaration parts
	int numCharsToPrint	= 0;
	int space = cio::console.getCols() - col;
	int strLen = std::strlen(str);

	if (!fieldLen) {									// if fieldlen is 0 or NULL, display str as it is without trailing spaces.
		numCharsToPrint = strLen;
	}
	else if(strLen < fieldLen) {						// if string length < fieldlength, display string with trailing space
		 numCharsToPrint = strLen;
		 t = fieldLen - strLen;
	}
	else {												//print string, if fieldlength =  string length
		numCharsToPrint = fieldLen;
	}
	if(space < strLen) {								//print no. of character, if max_col - cols is less than string
		numCharsToPrint = space;		
	}
	for (int i = 0; i < numCharsToPrint; i++) {			//For-loop which prints characters on the specified position
		cio::console.setPosition(row, col + i);
		cio::console.setCharacter(str[i]);
		cio::console.setPosition(row, col + i);
		cio::console.drawCharacter();
	} 
	if(t != 0) {										//For loop to print trailing spaces
		for(int i = strLen; i <= fieldLen - 1; i++) {
		cio::console.setPosition(row, col + i);
		cio::console.setCharacter(' ');
		cio::console.setPosition(row, col + i);
		cio::console.drawCharacter();
		}
	}
}														//End of display function


int edit(char *str, int row, int col, int fieldLength, int maxStrLength,
		 bool* insertMode, int* strOffset, int* curPosition) {
		
		bool done = false;										//while loop counter
		int key = 0;											//int which stores inputted key 
		int strLength = strlen(str);							//Backup of the original Values
		int tempOffset = *strOffset;						
		int tempCurPos = *curPosition;
		char* tempStr = new char[strLength + 1];
		strcpy(tempStr, str);									//copying string in temprory variable
			
		if(*strOffset > strLength) {							//setting offset to string length
			*strOffset =  strLength;
		}
		else if(*strOffset == (int)NULL) {						//setting offset to 0
			*strOffset =  0;
		}
		
		if(*curPosition > fieldLength) {						//setting curposition to fieldlength
			*curPosition = fieldLength - 1;
		}
		else if(*curPosition > strLength - (*strOffset)) {		//setting position to end of the string
			*curPosition = strLength - (*strOffset);
		}
		else if(*curPosition == (int)NULL) {					//setting curposition to 0
			 *curPosition = 0;
		}
		if(*insertMode == true) {								//play beep when user tries to insert more than maxlength
			if(strLength > maxStrLength) {						//and when insertmode is true
				cio::console << '\a';
			}
		}
		else if(*insertMode == false) {							//play beep when user tries to insert more than maxlength
			if(*curPosition + *strOffset + 1 > strLength) {		//and when insertmode is true
				cio::console << '\a';
			}
		}
		
		while(!done) {											//while loop starting
			display(str + *strOffset, row, col, fieldLength);	//Calls to Display Function
			cio::console.setPosition(row, col + *curPosition);	//setting starting position of cursor
			cio::console >> key;								//extracting pressed key by user
			switch(key) {										//start of switch case
				case ENTER:
				case TAB:
				case UP:
				case DOWN:
				case PGUP:
				case PGDN:
				case F(1):
				case F(2):
				case F(3):										//smooth scroll down of switch cases, which make done flag true, 
				case F(4):										//to exit from while loop
				case F(5):
				case F(6):
				case F(7):
				case F(8):
				case F(9):
				case F(10):
				case F(11):
				case F(12):
					done = true;
					break;
				case ESCAPE:									//Escape case, returns original strings and values
					*strOffset   = tempOffset;
					*curPosition = tempCurPos;
					strcpy(str, tempStr);
					done = true;
					break;
				case LEFT:										//LEFT case, Moves the cursor left one character, and change offset as well 
					if(*curPosition != 0) {
						(*curPosition)--;
					}
					else if(*strOffset != 0) {
						(*strOffset)--;
					}
					break;
				case RIGHT:										//RIGHT case, Moves the cursor left one character, and change offset as well
					if(*curPosition < fieldLength - 1) {		
						(*curPosition)++;
					}
					else if(*strOffset > 0){
						(*strOffset)++;
					}
					break;
				case HOME:										//HOME case, set cursor position and string offset to 0
					*curPosition = *strOffset = 0;				
					break;
				case END:										//END case, set cursor to the end of the string or at the edge of the screen, changes offset if necessory 
					for(int d = *strOffset + *curPosition; d < strLength; d++) {
						if(*curPosition < fieldLength - 1) {
							if(str[*curPosition] && d != fieldLength) {
								(*curPosition)++;
							}
						}	
						else {
							(*strOffset)++;
						}	
					} 
					break;
				case INSERT:									//INSERT case, turns insert mode on and off, for insert/ overstrike mode. 
					*insertMode = !*insertMode;
					break;
				case DEL:										//DEL case, discards the character at the current cursor position and moves all afterward characters
                    int d;					
					for(d = *strOffset + *curPosition; d < strLength + 1; d++) {
						str[d] = str[d + 1];
					} 
					break;
				case BACKSPACE:									//BACKSPACE case, discards the character to the left of the current cursor position, 
					if(*curPosition) {							//if possible, moves the characters at and to the right of the cursor position one position to the left,
						for(int i = *curPosition + *strOffset; i < strLength + 1; i++) {
								str[i - 1] = str[i];			// if possible, and positions the cursor one character to the left, if possible
						}
						if(*curPosition > 0) {
							(*curPosition)--;
						}
						else if(*strOffset > 0) {
							(*strOffset)--;
						}
					}
					break;
				default:			
					if(key >= ' ' && key <='~') {				//DEFAULT case, handles string writing in insert and overwrite mode.
						if(*insertMode) {						//Insert Mode, write character in string and move cursor
							if(strLength < maxStrLength) {
								for( int i = strLength; i >= (*curPosition + *strOffset); i--) {
										str[i + 1] = str[i];
								}
								str[*strOffset + *curPosition] = key;
								if (*curPosition < fieldLength - 1) {
										(*curPosition)++;
								}		 
								else {
									(*strOffset)++;
								}
							}
						} 
						else {									//Over-strike Mode, overwrites character in string
							if(strLength < maxStrLength) {
								str[*strOffset + *curPosition] = key;
							}
							if(*curPosition < fieldLength -1) {
								(*curPosition)++;
							} else {
								(*strOffset)++;
							}
					   }
					}
					break;
		}														//End of switch statement
	}															//End of while loop
	return key;													//return key pressed by user to exit function
}																//End of edit function
}																//end of cio