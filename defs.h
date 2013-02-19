
#pragma once

#include<stdio.h>


///constants

// bit obt
//
#define MASK  	0x40	// bit mask...to extract counting bytes


// navigation and metrics
//
#define LINE_CHARS	27		// chars per optical line
#define ACC_OLINES	4		// char lines per optical account
#define ACC_DIGITS	9		// number of digits/chars per account


// bit mapped numerical values
//
#define NUM_0	123
#define NUM_1	72
#define NUM_2	61
#define NUM_3	109
#define NUM_4	78
#define NUM_5	103
#define NUM_6	119
#define NUM_7	73
#define NUM_8	127
#define NUM_9	111


// account structure
//
struct Account
{
	unsigned char dSrc[ACC_DIGITS+1];
};
