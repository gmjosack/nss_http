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
#include <unistd.h>
#include <syslog.h>

#define NSS_HTTP_SERVER "127.0.0.1"
#define NSS_HTTP_PORT "9669"
#define NSS_HTTP_INITIAL_BUFFER_SIZE (256 * 1024)  /* 256 KB */
#define NSS_HTTP_MAX_BUFFER_SIZE (10 * 1024 * 1024)  /* 10 MB */

extern char *nss_http_request(const char *);
extern size_t j_strlen(json_t *);

#endif /* NSS_HTTP_H */
