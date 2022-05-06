SOURCE_DIR 	:= ../externals/FreeRTOS/FreeRTOS/Source
PORT_DIR	:= $(SOURCE_DIR)/portable/ThirdParty/GCC/Posix
INCLUDE_DIR	:= -I$(SOURCE_DIR)/include 
INCLUDE_DIR	+= -I$(PORT_DIR)
INCLUDE_DIR	+= -I$(PORT_DIR)/utils
INCLUDE_DIR	+= -I.


 
C_INCLUDE_PATH	:= $(INCLUDE_DIR)

SOURCES		:= src.c \
$(SOURCE_DIR)/tasks.c \
$(SOURCE_DIR)/timers.c \
$(SOURCE_DIR)/queue.c \
$(SOURCE_DIR)/list.c \
$(SOURCE_DIR)/croutine.c \
$(SOURCE_DIR)/portable/MemMang/heap_1.c \
$(PORT_DIR)/port.c \
$(PORT_DIR)/utils/wait_for_event.c



OBJECTS		:= $(SOURCES:.c=.o)
EXECUTABLE	:= app

CC		:= gcc
CFLAGS		:= -c -Wall $(INCLUDE_DIR)
LDFLAGS		:= -lpthread



all:  $(SOURCES) $(EXECUTABLE)
	echo $(OBJECTS)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm $(OBJECTS) $(EXECUTABLE)