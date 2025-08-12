/*
 * filename: adder.c
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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
		n1 = atoi(arg1);
		n2 = atoi(arg2);
	}



	/* Make the response body */
	sprintf(content, "Welcome to adder.com: ");
	sprintf(content, "%sTHE Internet addition portal.\r\n<p>", content);
	sprintf(content, "%sThe answer is: %d + %d = %d\r\n<p>", content,
			n1, n2, n1 + n2);
	sprintf(content, "%sThnaks for visiting!\r\n", content);

	/* Generate the HTTP response */
	printf("Content-length: %d\r\n", (int)strlen(content));
	printf("Content-type: text/html\r\n\r\n");
	printf("%s", content);
	fflush(stdout);
	exit(0);
}
