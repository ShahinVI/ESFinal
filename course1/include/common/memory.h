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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief move array of values from one address to another
 *
 * given the size of array, we also should avoid overlapping I will use malloc free
 * to copy data in an empty address then assign it to the new address
 *
 * @param src Pointer to original data array
 * @param dst pointer to the start of the new array
 * @param size_t lenght of array
 *
 * @return pointer to new array address.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief copy array of values from one address to another
 *
 * given the size of array. overlapping might occur and data wil be 
 * corrupted.
 *
 * @param src Pointer to original data array
 * @param dst pointer to the start of the new array
 * @param size_t lenght of array
 *
 * @return pointer to new array address.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief set all the values of an array to a certain value
 *
 * given the size of array. a pointer will pass by each address
 * of the array and assign it with a certain value
 *
 * @param src Pointer to original data array
 * @param size_t lenght of array
 * @param value Value to be assigned
 *
 * @return pointer to start of array address.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief set all the values of an array to zero
 *
 * given the size of array. a pointer will pass by each address
 * of the array and assign it with zero
 *
 * @param src Pointer to original data array
 * @param size_t lenght of array
 *
 * @return pointer to start of array address.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief reverse the order of the array
 *
 * given the size of array. two pointer will pass by each address
 * one at the start and one at the end and they will exchange values
 * a temporary variable will be used
 *
 * @param src Pointer to original data array
 * @param size_t lenght of array
 *
 * @return pointer to start of array address.
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief create a new dynamic memory
 *
 * length of array should be passed and the
 * function should reserve a new memory for the data that will be passed
 *
 * @param size_t lenght of array
 *
 * @return pointer to start of array address.
 */
uint32_t * reserve_words(size_t length);

/**
 * @brief free the dynamic memory
 *
 * takes an address and frees it from dynamic memory
 *
 * @param src pointer
 *
 * @return nothing.
 */
void free_words(uint32_t * src);









#endif /* __MEMORY_H__ */
