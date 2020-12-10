/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief Abstraction of memory read and write operations
 *
 * functions that convert between ascii and integer
 *
 * @author Aiman Shahin
 *
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include "course1.h"
#include "platform.h"
#include "data.h"
#include "stats.h"
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	uint8_t temsize = 0;
	uint8_t nflag = 0;
	uint8_t * ptr2 = ptr;
	if(data<0){
		data=data*(-1);
		*ptr='-';
		ptr++;
		nflag = 1;
		ptr2++;
	}
	if(data==0){
		*ptr='0';
		ptr++;
		temsize++;
	}
	while(data>0){
		switch (data%base){
			case 0:
				*ptr = '0';
				break;
			case 1:
				*ptr = '1';
				break;
			case 2:
				*ptr = '2';
				break;
			case 3:
				*ptr = '3';
				break;
			case 4:
				*ptr = '4';
				break;
			case 5:
				*ptr = '5';
				break;
			case 6:
				*ptr = '6';
				break;
			case 7:
				*ptr = '7';
				break;
			case 8:
				*ptr = '8';
				break;
			case 9:
				*ptr = '9';
				break;
			case 10:
				*ptr = 'A';
				break;
			case 11:
				*ptr = 'B';
				break;
			case 12:
				*ptr = 'C';
				break;
			case 13:
				*ptr = 'D';
				break;
			case 14:
				*ptr = 'E';
				break;
			case 15:
				*ptr = 'F';
				break;
			default:
				break;
		}
		data=data/base;
		ptr++;	
		temsize++;
		//PRINTF("\n%i\n",temsize);
		//print_array(ptr2, 10);
	}
	ptr2=my_reverse(ptr2,temsize);
	*ptr='\0';
	temsize++;
	//print_array(ptr2, 10);
	//print_array(ptr-temsize+1, 10);
	//PRINTF("\n%i\n",temsize);
	return (temsize+nflag);
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	//PRINTF("\n%i\n",digits);
	uint32_t base2=1;
	int nflag = 0;
	int32_t rvalue=0;
	if(*ptr=='-'){
		nflag=1;
		ptr++;
		digits--;
	}
	for(int i = 2 ; i < digits;i++){
		base2=base2*base;
	}
	while(digits>1){
		switch (*ptr){
			case '0':
				rvalue=rvalue+(0*(base2));
				break;
			case '1':
				rvalue=rvalue+(1*(base2));
				break;
			case '2':
				rvalue=rvalue+(2*(base2));
				break;
			case '3':
				rvalue=rvalue+(3*(base2));
				break;
			case '4':
				rvalue=rvalue+(4*(base2));
				break;
			case '5':
				rvalue=rvalue+(5*(base2));
				break;
			case '6':
				rvalue=rvalue+(6*(base2));
				break;
			case '7':
				rvalue=rvalue+(7*(base2));
				break;
			case '8':
				rvalue=rvalue+(8*(base2));
				break;
			case '9':
				rvalue=rvalue+(9*(base2));
				break;
			case 'A':
				rvalue=rvalue+(10*(base2));
				break;
			case 'B':
				rvalue=rvalue+(11*(base2));
				break;
			case 'C':
				rvalue=rvalue+(12*(base2));
				break;
			case 'D':
				rvalue=rvalue+(13*(base2));
				break;
			case 'E':
				rvalue=rvalue+(14*(base2));
				break;
			case 'F':
				rvalue=rvalue+(15*(base2));
				break;
			default:
				break;
		}
		digits--;
		base2=base2/base;
		//PRINTF("\n%i ",rvalue);
		//PRINTF(" %i\n",digits);
		ptr++;
	}
	if(nflag == 1){
		rvalue=rvalue*(-1);
	}
	//PRINTF("\n%i\n",rvalue);
	return rvalue;
}
