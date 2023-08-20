#ifndef _LIFO_H_
#define _LIFO_H_
#include "stdint.h"

typedef struct
{
	uint32_t length;
	uint32_t *base;
	uint32_t *head;
	uint32_t counter;
} sLIFO_INFO_t;

typedef enum
{
	LIFO_no_error,
	LIFO_empty,
	LIFO_Null,
	LIFO_full
} eLIFO_STATUS_t;

eLIFO_STATUS_t INIT_LIFO_FUN(sLIFO_INFO_t *lifo_info, uint32_t *buffer, uint32_t length);
eLIFO_STATUS_t POP_LIFO_FUN(sLIFO_INFO_t *lifo_info, uint32_t *item);
eLIFO_STATUS_t PUSH_LIFO_FUN(sLIFO_INFO_t *lifo_info, uint32_t item);
#endif