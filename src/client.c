#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "lib.h"

#define BUFSIZE 4096 // max number of bytes we can get at once

/**
 * Struct to hold all three pieces of a URL
 */
typedef struct urlinfo_t {
  char *hostname;
  char *port;
  char *path;
} urlinfo_t;

/**
 * Tokenize the given URL into hostname, path, and port.
 *
 * url: The input URL to parse.
 *
 * Store hostname, path, and port in a urlinfo_t struct and return the struct.
*/
urlinfo_t *parse_url(char *url)
{
  // localhost:3490/d20
  // copy the input URL so as not to mutate the original
  char *hostname = strdup(url); // localhost
  char *port; // 3490
  char *path; // d20

  urlinfo_t *urlinfo = malloc(sizeof(urlinfo_t));

    ///////////////////
    // IMPLEMENT ME! //
    ///////////////////
  
    // We can parse the input URL by doing the following:

    // 1. Use strchr to find the first slash in the URL (this is assuming there is no http:// or https:// in the URL).
    char *slash;
    slash = '/';

    // 2. Set the path pointer to 1 character after the spot returned by strchr.
    path = strchr(hostname, *slash + 1);
    printf("Path, or everything that comes after the /: %s", path);

    // 3. Overwrite the slash with a '\0' so that we are no longer considering anything after the slash.
    char *p;
    p = strstr(hostname, slash); // Finds the slash in url
    if (p) {
      strcpy(p, '\0'); // localhost:3490 \0 d20
      printf("%s", hostname);
    }

    // 4. Use strchr to find the first colon in the URL.
    char *colon;
    colon = ':';

    // 5. Set the port pointer to 1 character after the spot returned by strchr.
    port = strchr(hostname, *colon + 1);
    printf("Port, or everything that comes after the colon: %s", port);

    // 6. Overwrite the colon with a '\0' so that we are just left with the hostname.
    char *q;
    q = strstr(hostname, colon);
    if (q) {
      strcpy(q, '\0'); // localhost
      printf("%s", hostname);
    }

  return urlinfo;
}

/**
 * Constructs and sends an HTTP request
 *
 * fd:       The file descriptor of the connection.
 * hostname: The hostname string.
 * port:     The port string.
 * path:     The path string.
 *
 * Return the value from the send() function.
*/
int send_request(int fd, char *hostname, char *port, char *path)
{
  const int max_request_size = 16384;
  char request[max_request_size];
  int rv;

  ///////////////////
  // IMPLEMENT ME! //
  ///////////////////

  return 0;
}

int main(int argc, char *argv[])
{  
  int sockfd, numbytes;  
  char buf[BUFSIZE];

  if (argc != 2) {
    fprintf(stderr,"usage: client HOSTNAME:PORT/PATH\n");
    exit(1);
  }

  /*
    1. Parse the input URL
    2. Initialize a socket by calling the `get_socket` function from lib.c
    3. Call `send_request` to construct the request and send it
    4. Call `recv` in a loop until there is no more data to receive from the server. Print the received response to stdout.
    5. Clean up any allocated memory and open file descriptors.
  */

  ///////////////////
  // IMPLEMENT ME! //
  ///////////////////

  return 0;
}
