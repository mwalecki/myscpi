#define RXBUFSZ 20

/*
#define _PRINT_RESPONSE(...)													\
	{																			\
		sprintf((char*)txBuf, __VA_ARGS__);										\
		*txCnt = strlen((const char*)txBuf);									\
	}
*/

#define _PRINT_RESPONSE _PRINT_INT_RESPONSE

#define _PRINT_INT_RESPONSE(v)													\
	{																			\
		*txCnt = my_itoa(v, (char*)txBuf, 10);						\
		txBuf[(*txCnt)++] = '\r';												\
		txBuf[(*txCnt)++] = '\n';												\
	}

#define _PRINT_STR_RESPONSE(v)													\
	{																			\
		strcpy((char*)txBuf, v);												\
		*txCnt = strlen(v);												\
		txBuf[(*txCnt)++] = '\r';												\
		txBuf[(*txCnt)++] = '\n';												\
	}

#define _GROUP(grName)															\
	if(strncmp((const char*)rxBuf, grName, strlen(grName))==0){				\
		grNameLen = strlen(grName);
		

#define _ENDGROUP																\
		grNameLen = 0;															\
	}

#define _GET_SET_MEMBER(varName, memName)										\
	if(strncmp((const char*)(rxBuf+grNameLen), memName, strlen(memName))==0){	\
		memNameLen = strlen(memName);											\
		if(rxBuf[(grNameLen+memNameLen)]=='?')									\
			_PRINT_INT_RESPONSE(varName)									\
		else{																	\
			varName=atoi((const char*)rxBuf+(grNameLen+memNameLen+1));			\
		}																		\
	}

#define _GET_SETANDDO_MEMBER(varName, memName)									\
	if(strncmp((const char*)(rxBuf+grNameLen), memName, strlen(memName))==0){	\
		memNameLen = strlen(memName);											\
		if(rxBuf[(grNameLen+memNameLen)]=='?')									\
			_PRINT_INT_RESPONSE(varName)									\
		else{																	\
			varName=atoi((const char*)rxBuf+(grNameLen+memNameLen+1));			

#define _END_GET_SETANDDO_MEMBER												\
		}																		\
	}

#define _IF_MEMBER_THEN(memName)												\
	if(strncmp((const char*)(rxBuf+grNameLen), memName, strlen(memName))==0)

