#include <fstream>
#include <iostream>
#include "Httpd.hh"

Httpd::Httpd()
{
  _daemon.set_base_dir("./http");
}

Httpd::~Httpd()
{
}

void Httpd::runDaemon()
{
  Httpd server;

  std::cout << "HTTP Server started.\n";
  server.start();
  std::cout << "END\n";
}

void Httpd::start()
{
  _daemon.listen("localhost", PORT, 0);
}

void Httpd::handleRequest(const httplib::Request &req, httplib::Response &res)
{
    const char *page = readHtmlFile("index.htm");

    res.set_content(page, "text/html");
}

char *Httpd::readHtmlFile(std::string filename)
{
    std::ifstream ifs(HTTP_PATH+filename, std::ifstream::in);
    char *buffer;
    int length;

    ifs.seekg(0, std::ios::end);    // go to the end
    length = ifs.tellg();           // report location (this is the length)
    ifs.seekg(0, std::ios::beg);    // go back to the beginning
    buffer = new char[length];      // allocate memory for a buffer of appropriate dimension
    ifs.read(buffer, length);       // read the whole file into the buffer
    ifs.close();
    return (buffer);
}
