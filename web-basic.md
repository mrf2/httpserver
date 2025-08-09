# Web Basics
 * A Web client also known as a Web Browser opens an Internet connection to a server and requests for some *content*.
 * The server responds with the requested content and then closes the connection.
 * The Browsers reads the content and displays it on the screen.
#### Why HTTP is special than FTP?
Although the FTP is also used to retrive file from Server, the main difference is that Web content can be written in a language known as HTML *(Hypertext Markup Language)*. An HTML program (page) contains instructions (tags) that tell the browser how to display various text and graphical objects in the page.

## Web Contents
Web servers provide content to clients in two different ways:
 * Fetch a disk file and return its conents to the client. The disk file is known as *static content* and the process of returning the file to the client is know as *serving static content*.
 * Run an executable file and return its output to the client. The output produced by the executable at run time is known as *dynamic content*, and the process of running the program and returning its output to the client is known as *serving dynamic content*.
 * Every piece of content returned by a Web server is associated with some file that it manages. Each of these files has a unique name known as a URL *(Universal Resource Locator)*.
 * URLs for executable files can include program arguments after the file name. A **'?** character separates the file name from the arguments, and each argument is separated by an **'&'** character. For example, the URL <br> `http://example.com/app/adder?12&23` <br> identifies an executable called `/app/adder` that will be called with two argument strings: *12* and *23*

## Passing Program Arguments to Server
 * Arguments for **GET** request are passed in the **URI**.
 * A `?` character separates the file name from the arguments, and each argument is separated by and `&` character.
 * Spaces are not allowed in arguments and must be represented with `%20` string. Here `%20` is the ASCII value for space in hexadecimal `0x20`. Similar encodings exist for other special characters.
 * **Arguments for HTTP POST request are passed in the request body rather than in the URI.**

