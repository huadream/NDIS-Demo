#ifndef _PACKET_MANAGER_H
#define _PACKET_MANAGER_H

#include <ndis.h>

#define PM_TAG 'PmmP'


//��������
#define PM_PACKET_NDIS 0x721
#define PM_PACKET_IP 0x722
#define PM_PACKET_TCP 0x723
#define PM_PACKET_APP 0x724


#define PM_ERROR_OK 0
#define PM_ERROR_NO_RELATION 0x900

typedef struct _NDIS_PACKET_DATA
{
	PUCHAR VirtualAddress;
	UINT len;
}NDIS_PACKET_DATA, *PNDIS_PACKET_DATA;

typedef struct _NDIS_PACKET_IP
{
	LIST_ENTRY IpList;
	int IPLen;//��ʵ��IPЭ�鳤��
	int SonNum;//���ӽڵ���Ŀ
	PNDIS_PACKET data;
	NDIS_PACKET_DATA BufferPointer[32];//����NDIS PACKET��bufferָ��
}NDIS_PACKET_IP, *PNDIS_PACKET_IP;

typedef struct _NDIS_PACKET_TCP
{
	LIST_ENTRY TcpDataList;
	int SonNum;//���ӽڵ���Ŀ
	LIST_ENTRY data;

	unsigned int seq_no;
	unsigned int ack_no;

	unsigned long srcaddr;
	unsigned long dstaddr;
	unsigned short TotLen;//�ܳ���������ͷ������
	unsigned short tcplen;//���ݳ�

}NDIS_PACKET_TCP, *PNDIS_PACKET_TCP;

typedef struct _NDIS_PACKET_APP
{
	LIST_ENTRY appList;
	int AppLen;//��ʵ�����ݳ���
	int SonNum;//���ӽڵ���Ŀ

	INT srcIp;
	INT srcPort;
	INT desIp;
	INT desPort;

	PNDIS_PACKET_TCP data;
}NDIS_PACKET_APP, *PNDIS_PACKET_APP;

PVOID PMAllocatePacket(int Type);
PNDIS_PACKET PMRemoveNdisPacket(PNDIS_PACKET_APP root);

//���ڲ�����ndis packet��
VOID PMDeleteAppPacket(PNDIS_PACKET_APP* root);

VOID PMFreeMemery(PVOID pBuffer, UINT length);

#endif //_PACKET_MANAGER_H