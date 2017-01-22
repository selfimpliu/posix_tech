target : common.o server.o client.o
	cc -o server common.o server.o
	cc -o client common.o client.o


common.o : common.c common.h
	cc -c common.c

server.o : server.c common.h
	cc -c server.c 

client.o : client.c common.h
	cc -c client.c

clean : 
	rm *.o
