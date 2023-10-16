#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
	if (argc < 2) {
		fprintf(stderr, "Requires at least one file to read");
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		if (access(argv[i], F_OK) != 0) {
			fprintf(stderr, "Unable to find file: %s\n", argv[i]);
			return 1;
		}

		if (access(argv[i], R_OK) != 0) {
			fprintf(stderr, "Unable to read file: %s\n", argv[i]);
			return 1;
		}


	 	FILE *fptr = fopen(argv[i], "r");
		char string[500];
	
		while (fgets(string, 500, fptr)) {
			printf("%s", string);
		}
		
		puts("\n");
	}

	return 0;
}
