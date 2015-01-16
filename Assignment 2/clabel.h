/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

//CLabel.h

#ifndef _CLabel_H_
#define _CLabel_H_
#include "cfield.h"

namespace cio {
	class CLabel : public CField {
		private:
			void allocateAndCopy(const char* Str);
		public:
			CLabel(const char* lbl_data, int row, int col, int length = -1);
			CLabel(int row,int col, int length);
			~CLabel();
			CLabel(const CLabel& L);
			void draw(int n = C_NO_FRAME);
			int edit();
			bool editable() const;
			void set(const void*);
	};

}
#endif