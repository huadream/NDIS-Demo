#ifndef _PRE_COMP_H
#define _PRE_COMP_H


#pragma warning(disable:4214)   // bit field types other than int
#pragma warning(disable:4047 4024 4996 4200 4100 4189)
#pragma warning(disable:4201)   // nameless struct/union
#pragma warning(disable:4115)   // named type definition in parentheses
#pragma warning(disable:4127)   // conditional expression is constant
#pragma warning(disable:4054)   // cast of function pointer to PVOID
#pragma warning(disable:4244)   // conversion from 'int' to 'BOOLEAN', possible loss of data

#include <ndis.h>
#include <inaddr.h>
#include "passthru.h"


#ifndef MAC_ADDR_LEN
#define MAC_ADDR_LEN 6
#endif

#define MAX_NDIS_DEVICE_NAME_LEN        256


#pragma pack(1)


// i386 is little_endian.
#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN   (1)   //BYTE ORDER
#else
#error Redefine LITTLE_ORDER
#endif

//Macͷ�����ܳ���14�ֽ�
typedef struct _ETH_HEADER
	{
	UCHAR DstAddr[MAC_ADDR_LEN];
	UCHAR SrcAddr[MAC_ADDR_LEN];
	USHORT      EthType;
	}ETH_HEADER, *PETH_HEADER;


//IPͷ�����ܳ���20�ֽ�
typedef struct _IP_HDR
{
	//#if LITTLE_ENDIAN
	//	UCHAR ihl;   //�ײ�����
	//	UCHAR version; //�汾 
	//#else
	UCHAR versionAndihl; //�汾��ǰ��λ�����ײ����ȣ�����λ��
	//#endif

	UCHAR tos;   //��������
	unsigned short tot_len; //�ܳ���
	unsigned short id;    //��־
	unsigned short frag_off; //��Ƭƫ��
	UCHAR ttl;   //����ʱ��
	UCHAR protocol; //Э��
	unsigned short chk_sum; //�����
	//UCHAR srcaddr[4]; //ԴIP��ַ
	//UCHAR dstaddr[4]; //Ŀ��IP��ַ
	unsigned long srcaddr;
	unsigned long dstaddr;
}IP_HDR, *PIP_HDR;

typedef struct _PSD_HEADER

{

	unsigned long saddr; //Դ��ַ
	//UCHAR saddr[4];

	unsigned long daddr; //Ŀ�ĵ�ַ
	//UCHAR daddr[4];

	char mbz;//�ÿ�

	char ptcl; //Э������

	unsigned short tcpl; //TCP����

}PSD_HEADER,*PPSD_HEADER
;


//TCPͷ�����ܳ���20�ֽ�
typedef struct _TCP_HDR
	{
	unsigned short src_port;   //Դ�˿ں�
	unsigned short dst_port;   //Ŀ�Ķ˿ں�
	unsigned int seq_no;    //���к�
	unsigned int ack_no;    //ȷ�Ϻ�

	//unsigned short nHLenAndFlag ;  // ǰ4λ��TCPͷ���ȣ���6λ����������6λ����־λ16bit
	unsigned char nHLen;
	unsigned char Flag;//��6λ

	unsigned short wnd_size;   //16λ���ڴ�С
	unsigned short chk_sum;   //16λTCP�����
	unsigned short urgt_p;    //16Ϊ����ָ��
	}TCP_HDR, *PTCP_HDR;


//UDPͷ�����ܳ���8�ֽ�
typedef struct _UDP_HDR
	{
	unsigned short src_port; //Դ�˿ں�
	unsigned short dst_port; //Ŀ�Ķ˿ں�
	unsigned short uhl;   //udpͷ������
	unsigned short chk_sum; //16λudp�����
	}UDP_HDR, *PUDP_HDR;


//ICMPͷ�����ܳ���4�ֽ�
typedef struct _ICMP_HDR
	{
	UCHAR icmp_type;   //����
	UCHAR code;    //����
	unsigned short chk_sum;   //16λ�����
	}ICMP_HDR, *PICMP_HDR;

#pragma pack()





#endif//_PRE_COMP_H
