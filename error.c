#include "include/j-shell.h"
#include <errno.h>		
#include <stdarg.h>		
static void	err_doit(int, int, const char *, va_list);

void
err_ret(const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
}

void
err_sys(const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	exit(1);
}

static void
err_doit(int errnoflag, int error, const char *fmt, va_list ap)
{
	char	buf[MAXSIZE];

	vsnprintf(buf, MAXSIZE-1, fmt, ap);
	if (errnoflag)
		snprintf(buf+strlen(buf), MAXSIZE-strlen(buf)-1, ": %s",
		  strerror(error));
	strcat(buf, "\n");
	fflush(stdout);		
	fputs(buf, stderr);
	fflush(NULL);		
}
