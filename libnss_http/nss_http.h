#ifndef NSS_HTTP_H
#define NSS_HTTP_H

#include <curl/curl.h>
#include <errno.h>
#include <grp.h>
#include <jansson.h>
#include <nss.h>
#include <pthread.h>
#include <pwd.h>
#include <shadow.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//networks
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

//config file location
#define CONFIG_FILE "/etc/nss_http.conf"
//debug mode
#define DEBUG_LOG debug_print(__FUNCTION__)

//buffer size
#define NSS_HTTP_INITIAL_BUFFER_SIZE (256 * 1024)  /* 256 KB */
#define NSS_HTTP_MAX_BUFFER_SIZE (10 * 1024 * 1024)  /* 10 MB */

//funcitons
extern char *nss_http_request(const char *);
extern size_t j_strlen(json_t *);
extern struct config get_config(char *filename);
extern void debug_print(const char *func);


#endif /* NSS_HTTP_H */
