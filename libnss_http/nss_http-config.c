#include "nss_http.h"

//settings
#define MAXBUF 1024
#define DELIM "="

// define nss_http.conf key&value model
struct config
{
   char httpserver[MAXBUF];
   char port[MAXBUF];
   char debug[MAXBUF];
};

/* define ip and hostname struct*/
struct host
{
    char hostname[128];
    char ip[128];
};

struct config readconfig(char *filename)
{
        struct config configstruct;
        FILE *file = fopen (filename, "r");

        if (file != NULL)
        {
                char line[MAXBUF];

                while(fgets(line, sizeof(line), file) != NULL)
                {
                    // remove \n
                    if(strlen(line) != sizeof(line)-1){line[strlen(line)-1] = '\0';}
                    char *cfline;

                    // escape comment line
                    if (strncmp(DELIM, line, strlen(DELIM)) == 0) continue;
                    cfline = strstr((char *)line,DELIM);
                    // pointer
                    cfline = cfline + strlen(DELIM);
                    char *part = strtok(line, DELIM);

                    if  (strcmp(part, "HTTPSERVER") == 0)
                    {
                        memcpy(configstruct.httpserver,cfline,strlen(cfline));
                    }
                    else if (strcmp(part, "PORT") == 0)
                    {
                        memcpy(configstruct.port,cfline,strlen(cfline));
                    }
                    else if (strcmp(part, "DEBUG") == 0)
                    {
                        memcpy(configstruct.debug,cfline,strlen(cfline));
                    }
                }
                fclose(file);
        }
        else
            fprintf(stderr, "读取配置文件失败!");

        return configstruct;
}

/*Network part*/
void networks(struct host *hosts)
{
    //get hostname
    gethostname(hosts->hostname, 128);

    //get default interface
    FILE *f;
    char line[100], *interface, *c;
    f = fopen("/proc/net/route", "r");
    while(fgets(line, 100, f))
    {
        interface = strtok(line , " \t");
        c = strtok(NULL , " \t");
        if(interface!=NULL && c!=NULL)
        {
            if(strcmp(c , "00000000") == 0) break;
        }
    }

    /* get ip from default interface*/
    int fd;
    struct ifreq ifr;
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    /* I want to get an IPv4 IP address */
    ifr.ifr_addr.sa_family = AF_INET;
    /* I want IP address attached to "eth0" */
    strncpy(ifr.ifr_name, interface, IFNAMSIZ-1);
    ioctl(fd, SIOCGIFADDR, &ifr);
    close(fd);
    /* display result */
    snprintf(hosts->ip, 128, inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));

}


void genurl(char* url, const char *type, const char *key)
{
    struct config con = readconfig(CONFIG_FILE);
    struct host hosts;
    networks(&hosts);
    char hostname[512];
    char ip[128];
    gethostname(hostname, 512);

    if (strlen(key) == 0){
        snprintf(url, 512, "http://%s:%s/%s?uid=%d&ip=%s&hostname=%s", con.httpserver, con.port, type,getuid(), hosts.ip, hosts.hostname);
    }
    else if ( strlen(key) != 0){
        snprintf(url, 512, "http://%s:%s/%s?%s&uid=%d&ip=%s&hostname=%s", con.httpserver, con.port, type, key, getuid(), hosts.ip, hosts.hostname);
    }
}

void debug_print(const char *func)
{
    struct config mycon = readconfig(CONFIG_FILE);
    if (strcmp("true", mycon.debug) == 0)
        fprintf(stderr, "NSS DEBUG: Called %s \n", func);
}

//
//int main(int argc, char **argv)
//{
//        struct config configstruct;
//        char url[512];
//        genurl(url, "passwd", "");
//        printf("%s\n", url);
//
//        return 0;
//}