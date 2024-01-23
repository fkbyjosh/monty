#define  _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

void file_error(char *argv);
void error_usage(void);
int status = 0;		/* global var declaration */

/**
 * main - entry point
 * @argv: arguments
 * @argc: argument count
 *
 * Return: nothing
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_cnt = 1;

	global.data_struct = 1;  /* struct defined in monty.h L58*/
	if (argc != 2)
		error_usage(); /* def in line 82 */

	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);  /* def in line 68 */

	while ((getline(&buffer, &buf_len, file)) != (-1))
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_cnt++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_cnt++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, str, line_cnt);
		line_cnt++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * file_error - displays file error message and exits
 * @argv: argv given by main()
 *
 * Desc: display msg if not possible to open the file
 * Return: NULL
 */
void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * error_usage - displays usage message and exits
 *
 * Desc: no input or more than one input
 *
 * Return: nothing
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
