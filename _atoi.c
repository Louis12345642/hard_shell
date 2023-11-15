#include "shell.h"

/**
 * interactive - returns true for interative mode of the shell
 * @info: it is structure adress
 *
 * Return: one  if interactive and 0 if not
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - delimitor checking
 * @c: char checks
 * @delim: string delimitor
 * Return: 1 if yes and 0 no
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - alphabet char checking
 *@c:  char  input
 *Return: 1 for yes and 0 for no
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - changes  a string to integer
 *@s: the string to change
 *Return: 0 for no and 1 for yes
 */

int _atoi(char *s)
{
	int k, si = 1, fg = 0, output;
	unsigned int result = 0;

	for (k = 0;  s[k] != '\0' && fg != 2; k++)
	{
		if (s[k] == '-')
			si *= -1;

		if (s[k] >= '0' && s[k] <= '9')
		{
			fg = 1;
			result *= 10;
			result += (s[k] - '0');
		}
		else if (fg == 1)
			fg = 2;
	}

	if (si == -1)
		output = -result;
	else
		output = result;

	return (output);
}
