/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

#ifndef consoleplus_h
#define consoleplus_h
#include "cfg.h"

namespace cio {

void* capture(int r, int c, int h, int w); 
void restore(int r, int c, int h, int w, CDirection d, void* b); 
void release(void**);
}
#endif