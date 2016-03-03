#ifndef _APP_H
#define _APP_H
#include <ndis.h>
#include "passthru.h"
#include "PacketManager.h"

#define APP_HTTP 0x1100
#define APP_FTP 0x1101


//����������ݽṹ
typedef struct _APP_FICTION_PROCESS
{
	LIST_ENTRY proList;//������
	LIST_ENTRY receiveList;//Ҫ����Ľ������ݰ�
	LIST_ENTRY sendList;//Ҫ����ķ������ݰ�
	INT realPid;//��ʵ����id
	INT FicPid;//�������id

	INT srcIp;
	INT srcPort;
	INT desIp;
	INT desPort;

	
}APP_FICTION_PROCESS, *PAPP_FICTION_PROCESS;

int app_receive(PADAPT pAdapt, NDIS_HANDLE MiniportHandle, PNDIS_PACKET_APP pPacket, INT Type, PVOID pBuffer, UINT length);
void app_init();

#endif//_APP_H