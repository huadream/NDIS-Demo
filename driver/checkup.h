#ifndef _CHECK_UP_H
#define _CHECK_UP_H
#include "precomp.h"

//�����ݰ�����У��

//������̫����ҪУ�������
ULONG EthCheckup(PUCHAR buffer, ULONG length);

//����ҪУ���Tcp����
//USHORT TcpCheckup(PUCHAR buffer, UINT length);

unsigned short chksum_tcp(unsigned short *h, unsigned short *d, int dlen);

USHORT checksum(USHORT* buffer, int size);

unsigned short myChecksum(PUCHAR buffer, UINT size);

unsigned short myChecksum2(PUCHAR h, UINT hsize,PUCHAR t, UINT tsize);

#endif