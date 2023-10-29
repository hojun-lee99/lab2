a.out : main.o add.o sub.o dvid.o mult.o
	gcc -o a.out main.o add.o sub.o dvid.o mult.o

main.o : add.h sub.h mult.h dvid.h main.c
	gcc -c main.c

add.o : add.h add.c
	gcc -c add.c

sub.o : sub.h sub.c
	gcc -c sub.c

mult.o : mult.h mult.c
	gcc -c mult.c
	
dvid.o : dvid.h dvid.c
	gcc -c dvid.c