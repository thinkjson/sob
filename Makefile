CFLAGS = -I. -I/usr/local/include -O3 -g

all: sob

sob: sob.c 
	$(CC) $(CFLAGS) -o sob sob.c $(LIBS)

install:
	/usr/bin/install sob /usr/local/bin/

clean:
	rm -f sob
