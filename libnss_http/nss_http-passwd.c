#include "nss_http.h"


// Called to open the passwd file
enum nss_status
_nss_http_setpwent(int stayopen)
{
    nss_http_request("Testing");
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
