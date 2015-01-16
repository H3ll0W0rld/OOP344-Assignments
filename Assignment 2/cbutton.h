/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

//cbutton.h

#ifndef cbutton_H
#define cbutton_H
#include "cfg.h"
#include "cfield.h"
#include "cframe.h"
#include "console.h"
#include "keys.h"

namespace cio {
	class CButton : public CField {
		void allocateAndCopy(const char* str);
	  public:
		CButton(const char* Str, int Row, int Col, bool Bordered = true, const char* Border = C_BORDER_CHARS);
		virtual ~CButton();
		void draw(int n = C_NO_FRAME);
		int edit();
		bool editable()const;
		void set(const void*);
	};
}
#endif