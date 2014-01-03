#include "nss_http.h"

static pthread_mutex_t NSS_HTTP_MUTEX = PTHREAD_MUTEX_INITIALIZER;
#define NSS_HTTP_LOCK()    do { pthread_mutex_lock(&NSS_HTTP_MUTEX); } while (0)
#define NSS_HTTP_UNLOCK()  do { pthread_mutex_unlock(&NSS_HTTP_MUTEX); } while (0)


// Called to open the passwd file
enum nss_status
_nss_http_setpwent(int stayopen)
{
    NSS_HTTP_LOCK();
    nss_http_request("Testing");
    NSS_HTTP_UNLOCK();
    return NSS_STATUS_SUCCESS;
}

// Called to close the passwd file
enum nss_status
_nss_http_endpwent(void)
{
    return NSS_STATUS_NOTFOUND;
}

// Called to look up next entry in passwd file
enum nss_status
_nss_http_getpwent_r(struct passwd *result, char *buffer, size_t buflen, int *errnop)
{
    return NSS_STATUS_NOTFOUND;
}

// Find a user account by uid
enum nss_status
_nss_http_getpwuid_r(uid_t uid, struct passwd *result, char *buffer, size_t buflen, int *errnop)
{
    return NSS_STATUS_NOTFOUND;
}

// Find a user account by name
enum nss_status
_nss_http_getpwnam_r(const char *name, struct passwd *result, char *buffer, size_t buflen, int *errnop)
{
    return NSS_STATUS_NOTFOUND;
}
