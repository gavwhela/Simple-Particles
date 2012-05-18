# Gavin Whelan
# 5/16/12

CC = g++

##LD_LIBS =  -lglut -lGLU -lGL -lXi -lXmu -lXext -lX11 -lm

LOCAL_LIBS =
LD_LIBS = -lglut -lGLU -lGL
CFLAGS = -g

main: simpleParticle.o main.o particle.o
	$(CC) $(LD_LIBS) simpleParticle.o main.o particle.o -o main 

simpleParticle.o: simpleParticle.cpp simpleParticle.h
	$(CC) -c $(CFLAGS) simpleParticle.cpp -o simpleParticle.o

particle.o: particle.cpp particle.h
	$(CC) -c $(CFLAGS) particle.cpp -o particle.o

main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp -o main.o

clean:
	rm *.o main 
