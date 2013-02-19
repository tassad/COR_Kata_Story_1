
#include "Digitize.h"


CDigitize::CDigitize(void)
{
}


CDigitize::~CDigitize(void)
{
}


void CDigitize::Line1(unsigned char* src, unsigned char* dst)
{
  
	src++;	// skip non-count char

	for(int d = 0, cur = 0; cur < m_oLineLen ; cur+=3, src+=3, d++)
	{

		dst[d] = 0;		
		dst[d] |= ((*src) & MASK) >> 6;
	}
}

void CDigitize::Line2(unsigned char* src, unsigned char* dst)
{

	for(int d = 0, cur = 0; cur < m_oLineLen; cur++, src++, d++)
	{

		dst[d] |= ((*src) & MASK) >> 5;
		src++;	// next
		cur++;
				
		dst[d] |= ((*src) & MASK) >> 4;
		src++;	// next
		cur++;
				
		dst[d] |= ((*src) & MASK) >> 3;
	}

}


void CDigitize::Line3(unsigned char* src, unsigned char* dst)
{

	for(int d = 0, cur = 0; cur < m_oLineLen; cur++, src++, d++)
	{

		dst[d] |= ((*src) & MASK) >> 2;
		src++;	// next
		cur++;
				
		dst[d] |= ((*src) & MASK) >> 1;
		src++;	// next
		cur++;
				
		dst[d] |= ((*src) & MASK);	
	}

}


void CDigitize::Transform(unsigned char* src, Account *dst, int oLineLen,	int oLineCount, int oLineTerm)
{

	m_oLineTermStep = oLineTerm - 1;
	m_oLineLen = oLineLen;
	m_oLineCount = oLineCount;

	for(int oLine = 0; oLine < m_oLineCount;  oLine++,  src += m_oLineLen) // skipping the separator empty line
	{	

		Line1(src, dst[oLine].dSrc);
		src += m_oLineLen;

		Line2(src, dst[oLine].dSrc);
		src += m_oLineLen;

		Line3(src, dst[oLine].dSrc);
		src += m_oLineLen;	
	}

}

void CDigitize::Translate(Account *src, Account *dst, int NumberOfAcc)
{

	for(int i = 0; i < NumberOfAcc; i++)
	{

		// translate bit presented acount digits into actual values
		//
		for(int n = 0; n < ACC_DIGITS; n++)
		{
			switch(src[i].dSrc[n])
			{
			case NUM_0:
				{
					dst[i].dSrc[n] = 0;
					break;
				}

			case NUM_1:
				{
					dst[i].dSrc[n] = 1;
					break;
				}

			case NUM_2:
				{
					dst[i].dSrc[n] = 2;
					break;
				}

			case NUM_3:
				{
					dst[i].dSrc[n] = 3;
					break;
				}

			case NUM_4:
				{
					dst[i].dSrc[n] = 4;
					break;
				}

			case NUM_5:
				{
					dst[i].dSrc[n] = 5;
					break;
				}

			case NUM_6:
				{
					dst[i].dSrc[n] = 6;
					break;
				}

			case NUM_7:
				{
					dst[i].dSrc[n] = 7;
					break;
				}

			case NUM_8:
				{
					dst[i].dSrc[n] = 8;
					break;
				}

			case NUM_9:
				{
					dst[i].dSrc[n] = 9;
					break;
				}

			default:	// unrecognized
				{
					dst[i].dSrc[n] = 15;
					
					break;
				}

			}//switch

			dst[i].dSrc[n]  += 48;	// ascii code

		}//for n

	}//for i

}
