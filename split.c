#include "holberton.h"

/**
 * litString - splits string into an array of strings
 * separated by spaces
 * @build: input build
 * Return: true if able to split, false if not
 */
_Bool litString(config *build)
{
	register unsigned int i = 0;
	char *tok, *cpy;

	if (countWords(build->buffer) == 0)
	{
		build->args = NULL;
		free(build->buffer);
		return (false);
	}
	build->args = malloc((countWords(build->buffer) + 1) * sizeof(char *));
	cpy = _strdup(build->buffer);
	tok = _strtok(cpy, " ");
	while (tok)
	{
		build->args[i] = _strdup(tok);
		tok = _strtok(NULL, " ");
		i++;
	}
	build->args[i] = NULL;
	free(cpy);
	return (true);
}

/**
 * wordCounts - counts number of words in a string
 * @str: input string
 * Return: number of words
 */
unsigned int wordCounts(char *str)
{
	register int words = 0;
	_Bool wordOn = false;

	while (*str)
	{
		if (isSpace(*str) && wordOn)
			wordOn = false;
		else if (!isSpace(*str) && !wordOn)
		{
			wordOn = true;
			words++;
		}
		str++;
	}
	return (words);
}

/**
 * charSpace - determines if char is a space
 * @c: input char
 * Return: true or false
 */
_Bool charSpace(char c)
{
	return (c == ' ');
}
