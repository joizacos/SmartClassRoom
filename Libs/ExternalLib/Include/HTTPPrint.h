/**************************************************************
 * HTTPPrint.h
 * Provides callback headers and resolution for user's custom
 * HTTP Application.
 * 
 * This file is automatically generated by the MPFS Utility
 * ALL MODIFICATIONS WILL BE OVERWRITTEN BY THE MPFS GENERATOR
 **************************************************************/

#ifndef __HTTPPRINT_H
#define __HTTPPRINT_H

#include "TCPIP Stack/TCPIP.h"

#if defined(STACK_USE_HTTP2_SERVER)

extern HTTP_CONN curHTTP;
extern HTTP_STUB httpStubs[MAX_HTTP_CONNECTIONS];
extern BYTE curHTTPID;

void HTTPPrint(DWORD callbackID);
/*void HTTPPrint_sensorModel(WORD);
void HTTPPrint_type(WORD);
void HTTPPrint_element(WORD);
void HTTPPrint_sensorUnit(WORD);
void HTTPPrint_minRange(WORD);
void HTTPPrint_maxRange(WORD);
void HTTPPrint_sensorStatus(WORD);
*/
void HTTPPrint_temp(WORD);
//void HTTPPrint_counter(WORD);

void HTTPPrint(DWORD callbackID)
{
	switch(callbackID)
	{
        case 0x0000004d:
			//HTTPPrint_sensorModel(0);
			break;
        case 0x0000004e:
			//HTTPPrint_type(0);
			break;
        case 0x0000004f:
			//HTTPPrint_element(0);
			break;
        case 0x00000050:
			//HTTPPrint_sensorUnit(0);
			break;
        case 0x00000051:
			//HTTPPrint_minRange(0);
			break;
        case 0x00000052:
			//HTTPPrint_maxRange(0);
			break;
        case 0x00000053:
			//HTTPPrint_sensorStatus(0);
			break;
        case 0x00000054:
			HTTPPrint_temp(0);
			break;
        case 0x00000056:
			//HTTPPrint_counter(0);
			break;
		default:
			// Output notification for undefined values
			TCPPutROMArray(sktHTTP, (ROM BYTE*)"!DEF", 4);
	}

	return;
}

void HTTPPrint_(void)
{
	TCPPut(sktHTTP, '~');
	return;
}

#endif

#endif
