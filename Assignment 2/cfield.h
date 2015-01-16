/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

//CField.h

#ifndef CField_H
#define CField_H
#include "cframe.h"

namespace cio {

class CField : public CFrame {
	protected:
		void* _data;
	public:
		CField(int row = 0, int col = 0, int width = 0, int height = 0, void* data = NULL, bool visible = false , const char* border=C_BORDER_CHARS);
		virtual ~CField();
		void* data() const;		//setters and getters
		void data(void*);
		virtual void draw(int n = C_NO_FRAME) = 0;
		virtual int edit() = 0;	
		virtual bool editable() const = 0;
		virtual void set(const void*) = 0;
	};		//end of class
}		//End of cio 

#endif