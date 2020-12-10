#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#	File.i
#	File.asm
#	File.o
#	File.d
#	c1m1.map	
#	c1m1.out
# Platform Overrides:
#      <Put a description of the supported Overrides here
#	HOST  	gcc -DHOST -g
#	MSP432  arm-none-eabi-gcc cortex-m4 thumb nosys.specs -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM=
# Verbose Overrides
VERBO=
# deliverable Overrides
COURSE=
OR1=
OR2=
ifeq	($(VERBO),VERBOSE))
	OR1=-DVERBOSE
endif
ifeq	($(COURSE),COURSE1))
	OR2=-DCOURSE1
endif

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs 

# Compiler Flags and Defines
#CC
#LD  
#LDFLAGS 
#CFLAGS 
#CPPFLAGS

BASENAME = c1m4

CPPFLAGS = -MD -MP

ifeq	($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	CFLAGS = -g $(OR1) $(OR2) -DMSP432 -std=c99 $(INCLUDES) -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS) -Wall -Werror
	LDFLAGS = -Wl,-Map=$(BASENAME).map -O0 -T $(LINKER_FILE)
endif

ifeq	($(PLATFORM),HOST)
	CC = gcc
	LD = gcc
	CFLAGS = -DHOST $(OR1) $(OR2) $(INCLUDES) -g -std=c99 -Wall -Werror
	LDFLAGS = -Wl,-Map=$(BASENAME).map -O0
endif

%.i : %.c
	$(CC) -E -c $^  $(CFLAGS) -o $@

%.asm : %.c
	$(CC) -S -c $^ $(CFLAGS) -o $@

%.o : %.c
	$(CC) -c $^ $(CFLAGS) -o $@

%.d : %.c
	$(CC) -M  -c $^ $(CFLAGS) $(CPPFLAGS) -o $@

OBJS = $(SOURCES:.c=.o)
SRCS = $(SOURCES:.c=.out)


.PHONY: compile-all
compile-all: $(SRCS)

$(SRCS) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $@

.PHONY: build
build: $(BASENAME).out

$(BASENAME).out : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@


.PHONY: clean
clean:
	rm -f  $(BASENAME).out $(BASENAME).map $(SOURCES:.c=.out) $(SOURCES:.c=.o) $(SOURCES:.c=.asm) $(SOURCES:.c=.i) $(SOURCES:.c=.d)

