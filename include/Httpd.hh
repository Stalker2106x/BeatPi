#ifndef HTTPD_HH_
#define HTTPD_HH_

#include "microhttpd.h"

#define PORT 3000
#define HTTP_PATH "./http/"

class Httpd
{
public:
    Httpd();
    ~Httpd();

    static int handleRequest(void *cls, struct MHD_Connection *connection,
                      const char *url, const char *method,
                      const char *version, const char *upload_data,
                      size_t *upload_data_size, void **con_cls);

    static char *readHtmlFile(std::string filename);

private:
    MHD_Daemon *_daemon;
};

#endif /* !HTTPD_HH_ */