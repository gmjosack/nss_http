#ifndef NSS_HTTP_H
#define NSS_HTTP_H

#include <curl/curl.h>
#include <grp.h>
#include <nss.h>
#include <pwd.h>
#include <shadow.h>
#include <stdio.h>
#include <jansson.h>


#define NSS_HTTP_server "localhost"
#define NSS_HTTP_PORT 9669

extern char *nss_http_request(const char *);

#endif /* NSS_HTTP_H */
