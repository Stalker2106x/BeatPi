#ifndef HTTPD_HH_
#define HTTPD_HH_

#include <thread>
#include <memory>
#include "httplib/httplib.h"

#define PORT 3000
#define HTTP_PATH "./http/"

class Httpd
{
public:
    Httpd();
    ~Httpd();

    void start();
  
    static void runDaemon();
    static void handleRequest(const httplib::Request &req, httplib::Response &res);
    static char *readHtmlFile(std::string filename);

private:
  std::thread _thread;
  httplib::Server _daemon;
};

#endif /* !HTTPD_HH_ */
