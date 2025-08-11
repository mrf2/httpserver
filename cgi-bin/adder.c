/*
 * filename: adder.c
 */
#include <string.h>

#define	MAXLINE	 8192  /* Max text line length */

int main(void)
{
	char *buf, *ptr;
	char arg1[MAXLINE];
	char arg2[MAXLINE];
	char content[MAXLINE];
	int n1=0, n2=0;

	/* Extract the two arguments */
	if ((buf = getenv("QUERY_STRING")) != NULL) {
       /* char *strchr(const char *s, int c);
	  The strchr() function returns a pointer to the first occurrence of the character c in the string s. */
		ptr = strchr(buf, '&');	
		*ptr = '\0';
       /* char *strcpy(char *restrict dst, const char *restrict src); */
		strcpy(arg1, buf);
		strcpy(arg2, ptr+1);
		
