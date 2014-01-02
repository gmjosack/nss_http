#include "nss_http.h"


// Called to open the group file
enum nss_status
_nss_http_setgrent(int stayopen)
{
    return NSS_STATUS_SUCCESS;
}


// Called to close the group file
enum nss_status
_nss_http_endgrent(void)
{
    return NSS_STATUS_NOTFOUND;
}


// Called to look up next entry in group file
enum nss_status
_nss_http_getgrent_r(struct group *result, char *buffer, size_t buflen, int *errnop)
{
    return NSS_STATUS_NOTFOUND;
}


// Find a group by gid
enum nss_status
_nss_http_getgrgid_r(gid_t gid, struct group *result, char *buffer, size_t buflen, int *errnop)
{
    return NSS_STATUS_NOTFOUND;
}


// Find a group by name
enum nss_status
_nss_http_getgrnam_r(const char *name, struct group *result, char *buffer, size_t buflen, int *errnop)
{
    return NSS_STATUS_NOTFOUND;
}
