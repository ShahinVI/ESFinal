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
 * @file main.c
 * @brief Main entry point to the C1M2 Assessment
 *
 * This file contains the main code for the C1M2 assesment. Students
 * are not to change any of the code, they are instead supposed to compile
 * these files with their makefile.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include "platform.h"
#include "memory.h"
#include "course1.h"
#include "data.h"
#include "stats.h"


#define MAX_LENGTH (10)
char buffer[MAX_LENGTH];




/* A pretty boring main file */
int main(void) {
  unsigned int i;
  char value;

  /* Code below does some arbitrary memory Reads & writes */
  clear_all(buffer, MAX_LENGTH);
  set_all( ( buffer + 8 ), 43, 2); 
  set_value(buffer, 0, 0x61);
  value = get_value(buffer, 9);
  set_value(buffer, 9, (value + 0x27));
  set_value(buffer, 3, 0x37);
  set_value(buffer, 1, 88);
  set_value(buffer, 4, '2');
  value = get_value(buffer, 1);
  set_value(buffer, 2, 121);
  set_value(buffer, 7, (value - 12));
  set_value(buffer, 5, 0x5F);

  for ( i = 0; i < MAX_LENGTH; i++ ){
    PRINTF("%c", buffer[i]);
  }
  PRINTF("\n");
	#ifdef COURSE1
		course1();
	#endif
	#ifndef COURSE1
		unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  		/* variables initialization */
  		unsigned char maximum; /* used to store the largest value of the array */

  		unsigned char minimum; /* used to store the smallest value of the array */

  		unsigned char median;  /* used to store the median value of the array */

 		 unsigned int mean;    /* used to store the mean of the array's values */

  		/* finding, sorting and storing the statistics values in its corrosponding variables */
  		sort_array ( test, SIZE);
  		maximum = find_maximum ( test, SIZE);
  		minimum = find_minimum ( test, SIZE);
  		median  = find_median ( test, SIZE);
  		mean    = find_mean ( test, SIZE);
  
		#ifdef VERBOSE
			/* Statistics and Printing Functions Go Here */
			print_statistics ( maximum, minimum, median, mean);
			print_array ( test, SIZE);
		#endif
	#endif

  return 0;
}

