#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	const int MAX_ANSWER_LENGTH = 50;
	const int MAX_ANSWERS = 10;
	char answers[MAX_ANSWERS][MAX_ANSWER_LENGTH];
	char questions[MAX_ANSWERS][MAX_ANSWER_LENGTH];
	char answer[MAX_ANSWER_LENGTH];

	/*
	if (strcmp(argv[1], "-f") == 0) {
		printf("Supposed to read from a file!!!");
		return 1;
	}
	*/
	
	for (int i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
		strcpy(questions[i-1], argv[i]);
		scanf("%s", answer);
		strcpy(answers[i-1], answer);
	}

	puts("\n");
	for (int i = 0; i < argc-1; i++) {
		printf("Q: %s\n", questions[i]);
		printf("A: %s\n", answers[i]);
		puts("-----");
	}

	return 0;
}
