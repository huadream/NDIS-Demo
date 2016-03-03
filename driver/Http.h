#ifndef _HTTP_H
#define _HTTP_H
#include <ndis.h>
//#include <ntdef.h>

#define HTTP_PARSE_INVALID_METHOD 0x10
#define HTTP_PARSE_INVALID_REQUEST 0x11

#define HTTP_PARSE_INVALID_HEADER 0x13


#define CR 0x0d
#define LF 0x0a

typedef struct _HTTP_STR
{
	PCHAR Start;
	PCHAR End;
}HTTP_STR, *PHTTP_STR;

typedef struct _MIME_FILE
{
	PCHAR FileName;//�ͷ�
	PCHAR FileBuffer;//
	PCHAR FileBufferEnd;//NULL��ʾû���ļ���β
}MIME_FILE, *PMIME_FILE;



typedef struct _HTTP_REQUEST
{
	PCHAR buffer;
	INT length;
	INT status;
	INT step;// 0 ����������  1��������ͷ  2��������ͷ

	//
	HTTP_STR RequestLine;
	HTTP_STR HeaderLine;
	char Boundary[100];
	HTTP_STR Body;

	//
	HTTP_STR sMethod;
	int iMethod;
	HTTP_STR Uri;
	UCHAR http_minor;
	UCHAR http_major;

	HTTP_STR Host;
	INT FileType;//0 ��ʾ�����ļ��� 1��ʾstream 2��ʾform

	//
	HTTP_STR HeaderName;
	HTTP_STR HeaderValue;

	int MiMeState;
	MIME_FILE File[1024];
	int FileNumber;

	
}HTTP_REQUEST, *PHTTP_REQUEST;

int HttpAnalysis(PVOID pBuffer, INT length);

#endif