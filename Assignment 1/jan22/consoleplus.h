/* Kashyap Babubhai Patel								*/
/* Computer Programmer (CPD)							*/
/* Semester - 4											*/
/* Seneca College of Applied Arts and Technology		*/
/* School of Information & Communication Technology		*/
/* E-mail: kbpatel13@myseneca.ca						*/

/* Assignment 1											*/
/* Line editing facility								*/
/* consolelplus.h										*/

/*	This function displays the C-style, null-terminated string pointed to
	by str, starting at row row and column col of the console screen in a
	field of fieldLen characters.  

	Row value 0 refers to the top row, and column value 0 refers to the
	left-most column.  If the string is longer than fieldLen, your function
	displays the first fieldLen characters.  If the string is shorter than
	fieldLen, your function displays the portion of the entire string that
	fits on the screen, followed by enough trailing spaces to fill out the
	field completely.

	If fieldLen is 0 or less, your function displays the portion of the
	entire string that fits on the screen with no trailing spaces.  

	Your function positions the cursor after the last character displayed,
	but excluding any added trailing spaces, if the last character is not
	in the last column of the screen; otherwise, your function positions
	the cursor under the last character on the screen.

	Your function does not flush the output buffer. The results are
	undefined if the starting position of the string is not within the
	dimensions of the screen. 
*/
void display(const char *str, int row, int col, int fieldLen);

/*	This function edits the C-style, null-terminated string pointed to by str.  
	The parameter row holds the row(0 is the top row) of the string on the console screen.  
	The parameter col holds the starting column (0 is the left-most column) on the screen.  
	The parameter fieldLength holds the length of the editable field. 

	The string may be larger than the field itself, in which case part of the string is hidden from view. 
	The parameter maxStrLength holds the maximum length of the string, excluding the null byte. 
	The parameter insertMode points to a bool variable that holds the current insert mode of the string.  
	The parameter insertMode receives the address of a variable that stores the current editing mode - insert or overwrite.

	The parameter strOffset points to an int variable that holds the initial offset of the string within the field;
	that is, the index of the character in the string that initially occupies the first character position in the field.
	The parameter curPosition points to an int variable that holds the initial cursor position within the field; that is, 
	the index of the character in the field at which the cursor is initially placed. 
*/
int edit(char *str, int row, int col, int fieldLength, int maxStrLength,
		 bool* insertMode, int* strOffset, int* curPosition);
