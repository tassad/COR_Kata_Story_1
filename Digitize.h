#pragma once

#include "defs.h"


class CDigitize
{
public:
  CDigitize(void);
	~CDigitize(void);

	//transforms optical source data to numeric bit presentation
	//
	void Transform(unsigned char* src, Account *dst, int oLineLen,	int oLineCount, int oLineTerm);
	
	// translates bit presentaion accounts into actual account values
	void Translate(Account *src, Account *dst, int NumberOfAcc);
	

private:

	// processors of each of the 3 source lines forming single account, following:
	// 1- extract counting bits (bitwise: & 0x40)
	// 2- shift bits to designated order
		
	//
	void Line1(unsigned char* src, unsigned char* dst);
	void Line2(unsigned char* src, unsigned char* dst);
	void Line3(unsigned char* src, unsigned char* dst);

	/// member variables

	// optical line length in chars including line termination
	//
	int m_oLineLen;

	// count of line terminiation chars
	//
	int m_oLineTermStep;

	// count of optical lines/accounts
	//
	int m_oLineCount;
};

