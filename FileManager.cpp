
#include "defs.h"
#include "FileManager.h"


CFileManager::CFileManager(void)
{  
	m_hFile = -1;
}


CFileManager::~CFileManager(void)
{
	if(m_hFile > 0)
	{
		_close(m_hFile);
	}
}


int CFileManager::OpenSrc(char* FileName)
{
	int ret = 0;

	m_hFile = _open(FileName, _O_RDONLY | _O_BINARY);

	if(m_hFile == -1)
	{
		ret = -1;
	}

	return ret;
}



int CFileManager::LineTermCount()
{
	int count = 0;
	
	_lseek( m_hFile, LINE_CHARS, SEEK_SET);	// make sure we are at the beginning of the file

	char term[3];

	_read(m_hFile, term, 2);

	if(term[0] == 10 || term[0] == 13)
	{
		count++;
	}

	if(term[1] == 10 || term[1] == 13)
	{
		count++;
	}

	_lseek( m_hFile, 0, SEEK_SET);	// restore beginning of file position

	return count;

}


int CFileManager::GetSize()
{
	
	m_iFileSize =_lseek( m_hFile, 0, SEEK_END );

	return m_iFileSize;
}


int CFileManager::LoadScanData(unsigned char* Buffer, int BytesToLoad)
{
	_lseek( m_hFile, 0, SEEK_SET);	// make sure we are at the beginning of the file

	int count = -1;
	
	count = _read(m_hFile, Buffer, m_iFileSize);
	
	return count;	
}
