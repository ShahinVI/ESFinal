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
 * @file stats.c 
 * @brief this code is written to train our coding skills this is assignment 1
 *	  of the embedded systems course.
 *
 * @author Aiman Shahin
 * @date   11/05/2020
 *
 * 	  In this code we recieve an array of numbers which we need to 
 *	  extract data from. these data are as follows:
 *	  	- Largest number in the array
 *	 	- Smallest number in the array
 *		- mean of the array
 *		- median of the array
 *		
 *	  then we will print all of these values in an organised way.
 *
 *	  the next step is to reorder the array from the largest number to
 *	  the smallest number and round them down to the nearest integer.
 *	  then print the array in an organised and neat way.
 *
 *****************************************************************************/

/**
 * @Functions:
 *	**********************************************************************
 *	* Name:		main()					 
 *	* Type:		void					 
 *	*							 
 *	* Description:  contains the main exceuting code	 
 *	*							 
 *	* input para:	none					 
 *	*							 
 *	* output para:  return;				 
 *	***********************************************************************
 *	* Name:		print_statistics()			 
 *	* Type:		void					 
 *	*							 
 *	* Description:	takes the varaibles optained from the 	 
 *	*		given array of; Largest number, smallest
 *	*		number, mean and median. and prints them 
 *	*							 
 *	* input para:	unsigned char max , the largest value in array	 
 *	*		unsigned char min , the smallest value in array 	 
 *	*		unsigned char med , the median of the array	 
 *	*		unsigned char mean, the mean of the array	 
 *	*							 
 *	* output para:	return;	  returns nothing		 
 *	***********************************************************************
 *	* Name:		print_array()				 
 *	* Type:		void					 
 *	*							 
 *	* Description:	prints the array in a neat and organised 
 *	*		way.					 
 *	*							 
 *	* input para:	unsigned char * x , pointer to the array		 
 *	*		int s    , size of the array		 
 *	*							 
 *	* output para:	return;	   returns nothing		 
 *	***********************************************************************
 *	* Name:		sort_array()				 
 *	* Type:		void					 
 *	*							 
 *	* Description:	sorts the array's value from the largest to the smallest
 *	*		and directly edit the original array through pointers.			 
 *	*							 
 *	* input para:	unsigned char * x , pointer to the array		 
 *	*		int s    , size of the array		 
 *      *
 *	* output para:	return;	   returns nothing		 
 *	***********************************************************************
 *	* Name:		find_median()				 
 *	* Type:		unsigned char					 
 *	*							 
 *	* Description:	finds the median of the array and	 
 *	*		returns its value.			 
 *	*							 
 *	* input para:	unsigned char * x , pointer to the array		 
 *	*		int s    , size of the array		 
 *	*							 
 *	* output para:	unsigned char median, returns the median of the array			 
 *	***********************************************************************
 *	* Name:		find_mean()				 
 *	* Type:		unsigned int					 
 *	*							 
 *	* Description:	finds the mean of the array and returns  
 *	*		its value.				 
 *	*							 
 *	* input para:	unsigned char * x , pointer to the array		 
 *	*		int s    , size of the array		 
 *	*							 
 *	* output para:	unsigned char mean, returns the mean of the array 
 *	***********************************************************************
 *	* Name:		find_maximum()				 
 *	* Type:		unsigned char					 
 *	*							 
 *	* Description:	finds the largest number in the array 	 
 *	*		and returns it.				 
 *	*							 
 *	* input para:	unsigned char * x , pointer to the array		 
 *	*		int s    , size of the array		 
 *	*							 
 *	* output para:	unsigned char max, returns maximum value in array 
 *	***********************************************************************
 *	* Name:		find_minimum()				 
 *	* Type:		unsigned char					 
 *	*							 
 *	* Description:	finds the smallest number in the array	
 *	*		and returns it.				 
 *	*							 
 *	* input para:	unsigned char * x , pointer to the array		 
 *	*		int s    , size of the array		 
 *	*							 
 *	* output para:	unsigned char min, returns minimum value in array 
 *	***********************************************************************
 */



#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include "course1.h"
#include "platform.h"
#include "data.h"
#include "stats.h"
#include "memory.h"

/* Size of the Data Set */
#define SIZE (40)

/* Add other Implementation File Code Here */

void print_statistics ( unsigned char max , unsigned  char min , unsigned char med , unsigned  int m ) {
	#ifdef VERBOSE  
		PRINTF("\n\n the following are the data of the array:");
  		PRINTF("\n\n Maximum: %d\n Minimum: %d\n Median:  %d\n Mean:    %d\n\n",max,min,med,m);
	#endif
  return;
}

/*****************************************************************************************************/
void print_array ( unsigned char * x, int s ) {
  	#ifdef VERBOSE
  		printf("\n ");
  		for ( int i = 0; i < s; i++ ) {
  		   if( i%5 == 0 ) {
  		     PRINTF("\n %d",*x);
  		   }
  		   else {
  		     PRINTF(" %d",*x);
  		   }
  		   x++;     
  		}
  		PRINTF("\n\n");
	#endif  	
	return;
}

/*****************************************************************************************************/
void sort_array ( unsigned char * x, int s ) {

  unsigned char temparr[s]; /* creating array to store the temporary new array */
  unsigned char temp1; /* a temporary variable that helps in sorting array */

  temparr[0]= *x; /*asign first value of the original array to the first space in the temporary array */

  /* loop for all values of the original array, start at the second value of original array to compare */
  for ( int i = 1;  i < s; i++ ){

     x++;                /* increment the x to have a value of the next address in the array */
     temp1 = *x;         /* store the new value in the temp to compare with the values of the temp array */
     temparr[i] = *x;    /* set the last reached position of the temp array with the new value */ 
     
     /* loop to compare the values of all currently stored values in the temporary array and sort from
	the largest to the smallest */
     for ( int j = 0; j < i; j++ ){
        if( temp1 > temparr[j] ){
          temparr[i] = temparr[j]; /* switch the values of the temp array last position with the smaller value */
          temparr[j] = temp1;      /* replace the small number in the temporary array with the larger number from
				      the original array*/
          temp1 = temparr[i];      /* store the current smallest number in the temp variable and repeat the loop
				      until the code reach the end of the current array */
        }
     }
  }

  x = x-s+1; /* reset the value of the pointer to the initial address of the original array first position*/
  
  /* replace the values of the original array with the new sorted array*/
  for ( int i = 0 ; i < s; i++ ){
	*x = temparr[i];
        x++;
  }

  return;
}

/*******************************************************************************************************/
unsigned char find_median ( unsigned char * x, int s ) {
  unsigned char median;
  if( s%2 == 0 ) {
    median = (*(x+(s/2))+*(x+(s/2)-1))/2;
  }
  else{
    median = *(x+(s/2));
  }
  return median;
}

/*****************************************************************************************************/
unsigned int find_mean ( unsigned char * x, int s ) {
  unsigned int mean = *x;
  for( int i = 1 ; i < s ; i++) {
     x++;
     mean = mean + *x;
  }
  mean = mean/s;
  return mean;
}

/*****************************************************************************************************/
unsigned char find_maximum ( unsigned char * x, int s ) {
  unsigned char maximum = *x;
  for( int i = 1 ; i < s ; i++) {
     x++;
     if( *x > maximum ) {
        maximum = *x;
     }
  }
  return maximum;
}

/*****************************************************************************************************/
unsigned char find_minimum ( unsigned char * x, int s ) {
  unsigned char minimum = *x;
  for( int i = 1 ; i < s ; i++) {
     x++;
     if( *x < minimum ) {
        minimum = *x;
     }
  }
  return minimum;
}

