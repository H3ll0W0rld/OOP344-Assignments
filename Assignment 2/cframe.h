/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

#ifndef CFrame_H
#define CFrame_H
#include "iframe.h"
#include "keys.h"

namespace cio {

class CFrame : public iFrame {
	protected:
		int _row;
		int _col;
		int _width;
		int _height;
		bool _visible;
		const char* _str;
		CFrame* _cframe;
		char _border[9];
		bool _fullscreen;
		void* _covered;
		void setLine(char* str, char left, char fill, char right) const;
		void capture();
		int absrow() const;
		int abscol() const;

	public:
		CFrame(int Row = -1, int Col = -1, int Width = -1, int Height = -1, bool Visible = false, const char* Border=C_BORDER_CHARS, CFrame* Frame = 0);
		void goMiddle();
		void bordered(bool);
		bool bordered() const;
		~CFrame();
		void frame(CFrame*);
		CFrame* frame() const;
		
		void row(int);
		int row() const;
		void col(int);
		int col() const;
		void height(int);
		int height() const;

		void width(int);
		int width() const;
		//pure virtual function from interface
		void draw(int fn = C_FULL_FRAME);
		void hide(CDirection dir = C_STATIONARY);
		void move(CDirection dir);
	};
		void move(cio::iFrame&);

}
#endif