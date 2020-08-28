#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 64

#define BIT0 00000001
#define BIT1 00000010
#define BIT2 00000100
#define BIT3 00001000
#define BIT4 00010000
#define BIT5 00100000
#define BIT6 01000000
#define BIT7 10000000



int echoStandardIn();
int simpleCat(const char *filename);
int formatCat(const char *filename, int mode);


int main(int argc, char* argv[]) {
	if (argc > 1 && strcmp(argv[1], "-") != 0) {
		simpleCat((const char*) argv[1]);	
	}
	else {
		echoStandardIn();
	}
	return 0;
}


int echoStandardIn() {
	char input[BUFFER_SIZE];
	while(1) {
		fgets(input, BUFFER_SIZE, stdin);
		printf("%s", input);
	}
	return 0;
}


int simpleCat(const char * filename) {
	FILE *input_fp;
	char line_buffer[BUFFER_SIZE];
	char *stat;
	const int chars_to_read = BUFFER_SIZE;
	input_fp = fopen(filename, "r");
	if (input_fp == NULL) {
		printf("Unable to open file: %s", filename);
		return -127;
	}

	while(1) {
		stat = fgets(line_buffer, chars_to_read, input_fp);
		if (stat == NULL) {
			if ( feof(input_fp) != 0) {
				break;
			} else {
				printf("Unable to read from file: %s", filename);
				return -126;
			}
		}
		fputs(line_buffer, stdout);
	}

	return 0;
}
/*
 * Modes are as follows:
 * -E, --show-ends: dsiplay $ at end of each line: 1
 * -T, --show-tabs: dipslay TAB as ^I: 2
 * -v, --show-nonprinting: use ^ and M- notation, except for LFD and TAB: 4
 * -t: eq -vT : 6
 * -e: eq -vE : 5
 * -vET, -A, --show-all: 7
 *  
 *  -n, --number: numbers all lines: 1
 *  -b, --number-nonblank: numbers only lines with output, overides -n: 2
 *
 *  -s, --squeeze-blank: suppresses repeated blanks: 1
 *
 *  so mode can be represented as 0 00 000, or as an 8 bit integer where: 
 *  	bits 0-2 are the printing mode,
 *  	bits 3-4 are the number mode, with value 11 being unused
 *  	and bit 5 is the status of the squeeze mode on or off. 
 * */

char * addEndMarks(const char * line) {
	char *np;
	return np;
}

int formatCat(const char * filename, int mode) {
	FILE *input_fp;
	char line_buffer[BUFFER_SIZE];
	char *editable_buffer;
	char *stat;
	const int chars_to_read = BUFFER_SIZE;
	int currentline = 1;
	input_fp = fopen(filename, "r");
	if (input_fp == NULL) {
		printf("Unable to open file: %s", filename);
		return -127;
	}

	while(1) {
		stat = fgets(line_buffer, chars_to_read, input_fp);
		if (stat == NULL) {
			if ( feof(input_fp) != 0) {
				break;
			} else {
				printf("Unable to read from file: %s", filename);
				return -126;
			}
		}
		if (((mode & BIT5) > 0) && (strcmp(line_buffer, "") == 0)) {
			continue;

		} else {
			editable_buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
			int index = 0;
			for(int i = 0; i < BUFFER_SIZE; i++) {

			}
					
		}
		fputs(line_buffer, stdout);
	}

	return 0;
}
