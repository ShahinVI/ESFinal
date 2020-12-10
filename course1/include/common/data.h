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
 * @file data.h
 * @brief converts integer to ascii and vice versa
 *
 * able to convert from base 2 to 16
 *
 * @author Aiman Shahin
 * 
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief convert integer to ASCII
 *
 *  the number converts to string according to the base
 *  base range from 2 to 16.
 *  I will use modulus % and switch
 *
 * @param data integer to be converted
 * @param ptr  pointer to the address which will hold the string
 * @param base shows which base we wil convert the integer to.
 *
 * @return uint8_t the size of the string.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief convert ASCII to integer
 *
 *  depending on the base of the string provided
 *  base range from 2 to 16. we will change this string back to integer base 10
 *
 * @param digits length of the string including -ve and \0
 * @param ptr  pointer to the address which will hold the string
 * @param base shows which base of string we wil convert to integer.
 *
 * @return uint32_t the integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /*__DATA_H__*/
