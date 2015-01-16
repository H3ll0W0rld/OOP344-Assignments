/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

#ifndef cfg_h
#define cfg_h
#include <cstdlib>

#define C_MAX_NO_FIELDS                 100
#define C_BUTTON_HIT                      1
#define C_NOT_EDITABLE                    0
#define C_BORDER_CHARS			"/-\\|/-\\|"
#define C_FULL_FRAME					 -1
#define C_NO_FRAME						  0
#define C_NOT_EDITABLE					  0
#define C_BUTTON_HIT					  1
#ifndef NULL
#define NULL                       (void*)0
#endif
namespace cio {
    enum CDirection {C_STATIONARY, C_MOVED_LEFT, C_MOVED_RIGHT, C_MOVED_UP, C_MOVED_DOWN};
}
#endif

