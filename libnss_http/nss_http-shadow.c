#include "nss_http.h"

static pthread_mutex_t NSS_HTTP_MUTEX = PTHREAD_MUTEX_INITIALIZER;
#define NSS_HTTP_LOCK()    do { pthread_mutex_lock(&NSS_HTTP_MUTEX); } while (0)
#define NSS_HTTP_UNLOCK()  do { pthread_mutex_unlock(&NSS_HTTP_MUTEX); } while (0)


// Called to open the shadow file
enum nss_status
_nss_http_setspent(int stayopen)
{
    NSS_HTTP_LOCK();
    NSS_HTTP_UNLOCK();
    return NSS_STATUS_SUCCESS;
}


// Called to close the shadow file
enum nss_status
_nss_http_endspent(void)
{
    return NSS_STATUS_NOTFOUND;
}


// Called to look up next entry in the shadow file
enum nss_status
_nss_http_getspent_r(struct spwd *result, char *buffer, size_t buflen, int *errnop)
{
    return NSS_STATUS_NOTFOUND;
}


// Find a shadow entry by name
enum nss_status
_nss_http_getspnam_r(const char *name, struct spwd *result, char *buffer, size_t buflen, int *errnop)
{
    return NSS_STATUS_NOTFOUND;
}
