# CGI - Common Gateway Interface

## CGI Environment Variables
|Environment Variable|Description|
|---|---|
|QUERY_STRING|Program arguments|
|SERVER_PORT|Port that the parent is listening on|
|REQUEST_METHOD|GET or POST|
|REMOTE_HOST|Domain name of client|
|REMOTE_ADDR|Dotted-decimal IP address of client|
|CONTENT_TYPE|POST only: MIME type of the request body|
|CONTENT_LENGTH|POST only: Size in bytes of the request body|

## Server Passing Arguments to Child
Server receives a request as follows:
```bash
GET /cgi-bin/adder?123&32 HTTP/1.1
```
 * It will calls `fork` to create a child process and calls `execve` to run the `/cgi-bin/adder` program in the context of the child.
 * Before the call to `execve`, the child process sets the CGI environment varaible **QUERY_STRING** to `123&32`, which the adder program can reference at runtime using the `getenv` function.
 * *Many CGI programs are written in Perl Scripts, thats why CGI programs are often called `CGI scripts`*.

## Child Send Its output to Client
 * A CGI program sends its dynamic content to the standard output.
 * Before the child process loads and runs the CGI program, it uses the `dup2()` function to redirect standard output to the connected descriptor that is associated with the client. Thus, anything that the CGI program writes to standard output goes directly to the client.
 * Since the parent does not know the type or size of the content that the child generates, the child is reponsible for generating the **`Content-type`** and **`Content-length`** response headers, as well as the empty line that terminates the headers.
