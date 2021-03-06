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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
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
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
	uint8_t * mptr = (uint8_t *) malloc (length*sizeof(uint8_t));
	for(int i = 0; i<length; i++){
		*mptr=*src;
		mptr++;
		src++;
	}
	mptr=mptr-length;
	for(int j = 0; j<length; j++){
		*dst=*mptr;
		mptr++;
		dst++;
	}
	dst=dst-length;
	return dst;
}

/*
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
	if(src>dst){
		for(int i = 0; i<length; i++){
			*dst=*src;
			dst++;
			src++;
		}
		dst=dst-length-1;
	}	
	else if(dst>src){
		dst=dst+length-1;
		src=src+length-1;
		for(int j = 0;j<length;j++){
			*dst=*src;
			dst--;
			src--;
		}
		dst=dst+1;
	}
	return dst;
}
*/
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
	for(int i = 0; i<length; i++){
		*dst=*src;
		src++;
		dst++;
	}
	dst=dst-length-1;
	return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
	for(int i = 0; i<length; i++){
		*src = value;
		src++;
	}
	src=src-length-1;
	return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
	for(int i = 0; i<length; i++){
		*src = 0;
		src++;
	}
	src=src-length-1;
	return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length){
	uint8_t * ptr1 = src;
	uint8_t * ptr2 = src+length-1;
	uint8_t temp;
	while(ptr1<ptr2){
		temp=*ptr1;
		*ptr1=*ptr2;
		*ptr2=temp;
		ptr1++;
		ptr2--;
	}
	return src;
}

uint32_t * reserve_words(size_t length){
	uint32_t * rptr = (uint32_t *) malloc (length*sizeof(uint32_t));
/*	uint32_t * rptr = = (uint32_t *) malloc (length);	*/
	return rptr;
}

void free_words(uint32_t * src){
	free(src);
	return;
}







