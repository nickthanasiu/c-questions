#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	const int MAX_ANSWER_LENGTH = 50;
	const int MAX_ANSWERS = 10;
	
	char questions[MAX_ANSWERS][MAX_ANSWER_LENGTH];
	int num_questions = 0;
	char answers[MAX_ANSWERS][MAX_ANSWER_LENGTH];
	char answer[MAX_ANSWER_LENGTH];
	
	// @TODO: Handle Too many questions
	// @TODO: Handle answers too long
	// @TODO: Handle no args

	if (strcmp(argv[1], "-f") == 0) {
		if (argv[2] == NULL) {
			perror("Missing file name parameter");
			return 1;
		}
		
		char file_name[255];
		FILE *file = fopen(strcpy(file_name, argv[2]), "r");
		if (file == NULL) {
			perror("Error opening file");
			return 1;
		}

		char buffer[100];
		for (int i = 0; fgets(buffer, sizeof(buffer), file) != NULL; i++) {
			strcpy(questions[i], buffer);
			num_questions++;
		}

		
		fclose(file);
	} else {
		// Get questions from command line arguments
		for (int i = 0; i < (argc-1); i++) {
			strcpy(questions[i], argv[i+1]);
			num_questions++;
		}
	}
	
	// Ask questions and collect answers
	for (int i = 0; i < num_questions; i++) {
		puts(questions[i]);
		scanf("%s", answer);
		strcpy(answers[i], answer);
	}

	puts("\n");
	for (int i = 0; i < num_questions; i++) {
		printf("Q: %s\n", questions[i]);
		printf("A: %s\n", answers[i]);
		puts("-----");
	}

	return 0;
}
