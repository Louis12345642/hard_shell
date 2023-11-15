#include "shell.h"

/**
 * _myexit - get out of the shell
 * @info: structure containing arguement
 *          constant function prototype.
 *  Return: exits with status code 
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int extchk;

	if (info->argv[1])  /* existing checking jsdh */
	{
		extchk = _erratoi(info->argv[1]);
		if (extchk == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - hfhd djfbjdjkdjk jd 
 * @info: structure os the cpde is here
 *          constant   func prototype.
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
	char *s, *dr, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dr = _getenv(info, "HOME=");
		if (!dr)
			chdir_ret = /* TODO: what should this be? */
				chdir((dr = _getenv(info, "PWD=")) ? dr : "/");
		else
			chdir_ret = chdir(dr);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dr = _getenv(info, "OLDPWD=")) ? dr : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the cu df rent direct jdfjory of the dfkl cess
 * @info: struct cotaining aurgements
 *          const func prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* tefdv mp att_ df unusdfvf ed workdf,dd */
	return (0);
}
