#pragma once

#include "defs.h"
// file operations
#include <io.h>
#include <fcntl.h>

class CFileManager
{

public:
  
	/// construction

	// default constructor
	//
	CFileManager(void);


	// default distructor
	//
	~CFileManager(void);

	
	/// operations

	// open source file for reading
	//
	int OpenSrc(char* FileName);	
	

	// simple inspection of source file format: identify line termination char count
	//
	int LineTermCount();


	// identify file size
	//
	int GetSize();


	// read data from file, load it into passed buffer parameter, returns actual size of loaded data, or  -1 on error
	//
	int LoadScanData(unsigned char* Buffer, int BytesToLoad);

private:

	/// member variable:

	// file size in bytes
	//
	int	m_iFileSize;

	// processed file handle
	//
	int	m_hFile;

};
