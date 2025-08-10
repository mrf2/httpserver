/*
 * filename: adder.c
 */

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
		/* The strchr() function returns a pointer to the first occurrence of the character c in the string s. */
		ptr = strchr(buf, '&');
		
