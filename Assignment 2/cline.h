/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

//CLine.h

#ifndef _CLINE_H_
#define _CLINE_H_
#include "cfield.h"

namespace cio {
	class CLine : public CField {
		void allocateAndCopy(const char*);
		int _curpos;
		int _offset;
		int _tmp_Row;
		int _tmp_Col;
		int _tmp_length;
		bool* _tmp_insertMode;
		int _maxchars;			//store temorary maxchars for string allocation
	public:
		CLine(const char* str, int row, int col, int length, int maxChars, bool* insertMode, bool bordered = false, 
			const char* border = C_BORDER_CHARS);
		
		CLine(int row, int col, int length, int maxChars, bool* insertMode, bool bordered = false,
			const char* = C_BORDER_CHARS);
		~CLine();
		void draw(int n = C_NO_FRAME);
		int edit();
		bool editable() const;
		void set(const void*);
	};
}
#endif