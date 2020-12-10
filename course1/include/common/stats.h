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
 * @file stats.h 
 * @brief this code is written to train our coding skills this is assignment 1
 *	  of the embedded systems course.
 *
 * @author Aiman Shahin
 * @date   11/05/2020
 *
 * 	  this file contains the functions which will be used in this code
 *	  the functions are:
 *	  	print_statistics
 *	 	print_array
 *		sort_array
 *		find_median
 *		find_mean
 *	        find_maximum
 *              find_minimum
 *	  
 *	  
 *	  
 *
 *****************************************************************************/

#ifndef __STATS_H__
#define __STATS_H__


/*this function prints the largest, smallest, median and mean values of the array */
void print_statistics( unsigned char max , unsigned char min , unsigned char med , unsigned int mean );

/*if Verbose enabled print functions works */
#ifdef VERBOSE
/* this function prints the array */
void print_array( unsigned char * x, int s );
#endif

/* this function sorts the array from the largest value to the smallest value */
void sort_array( unsigned char * x, int s );

/* this function finds the median of the array and returns it */
unsigned char find_median( unsigned char * x, int s );

/* this function finds the mean value and returns it */
unsigned int find_mean( unsigned char * x, int s );

/* this function finds the largest value in the array and returns it */
unsigned char find_maximum( unsigned char * x, int s );

/*this function finds the smallest value in the array and returns it */
unsigned char find_minimum( unsigned char * x, int s );


/**
 * @Functions:
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


#endif /* __STATS_H__ */
