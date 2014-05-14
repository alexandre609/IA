EXEC = MAIN
CC = gcc
#WFLAGS = -Werror -W -Wall -Wextra -Wmissing-declarations -Wcast-qual -Wmissing-prototypes -Wredundant-decls -Wshadow -Wbad-function-cast
TESTWFLAGS = -W -Wall -Wextra -Wmissing-declarations -Wcast-qual -Wmissing-prototypes -Wredundant-decls -Wshadow -Wbad-function-cast
CFLAGS = -g -pedantic -std=gnu99
IFLAGS = -Iinclude -lm
OPATH = obj/
CPATH = src/
IPATH = include/
HAVE_DOC = $(wildcard Doxyfile)

vpath %.h include
vpath %.c src
vpath %.o obj
vpath MAIN bin

$(EXEC) : main.o portes.o
	@ echo
	@ echo "##### TEST MODE #####" 
	@ echo
	$(CC) $(CFLAGS) -o $(EXEC) $(OPATH)*.o $(IFLAGS)
	mv $@ bin/

main.o:main.c table.h portes.h
portes.o:portes.c portes.h

%.o : %.c
	@ echo "$(CC) -c $< -o $@ --WFLAGS $(CFLAGS) " 
	@ $(CC) -c $< -o $@ $(CFLAGS) $(TESTWFLAGS) $(IFLAGS) 
	@ mv $@ $(OPATH)

clean : 
	rm obj/* bin/*

ifeq ($(strip $(HAVE_DOC)),)
    doc:
	doxygen -g
else
    doc:Doxyfile
	doxygen -u Doxyfile ; doxygen Doxyfile
endif

