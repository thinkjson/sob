#include <stdio.h>
#include <string.h>
#include <time.h>

int main (int argc, char *argv[]) {
	char *identifier;
	if (argc > 1) {
		identifier =  argv[1];
	}
	
	int batch_count = 0, batch_size = 0, 
		batch_start = clock(), batch_end, 
		line_length;
	double total_count = 0, total_size = 0, interval;
	char buf[BUFSIZ];

	// Pipe stdin to stdout
	while ( fgets( buf, sizeof(buf), stdin ) != NULL ) {
		printf("%s", buf);

		// Increment counters
		batch_count++;
		total_count++;
		line_length = strlen(buf);
		batch_size += line_length;
		total_size += line_length;

		// Show progress throughout process
		if (batch_count % 100000 == 0) {
			batch_end = clock();
			interval = ((float) (batch_end - batch_start)) / CLOCKS_PER_SEC;
			fprintf(stderr, "%s\t%dK\t%dK lines/s\t%dM/s\t%fM\n",
				identifier,
				(int) (total_count / 1000),
				(int) (batch_count / 1000 / interval),
				(int) (batch_size / 1024 / 1024 / interval),
				(float) batch_size / 1024 / 1024);

			batch_start = clock();
			batch_count = 0;
			batch_size = 0;
		}
	}

	// Show totals
	interval = ((float) clock()) / CLOCKS_PER_SEC;
	fprintf(stderr, "%s\tAVG\t%dK lines/s\t%dM/s\t%fM\n", 
		identifier,
		(int) (total_count / 1000 / interval),
		(int) (total_size / 1024 / 1024 / interval),
		(float) total_size / 1024 / 1024);
}