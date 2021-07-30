# makfile configuration
COMMON_OBJECTS =
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c


all:run.elf


#additional rules for files
run.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o main.o switches.o buzzer.o stateMachines.o wdt_handler.o led.o  ../lib/libTimer.a

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

load: run.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf *# *~

switches.o: switches.h stateMachines.h
led.o: led.c led.h
stateMachines.o: led.h stateMachines.h
buzzer.o: buzzer.h
