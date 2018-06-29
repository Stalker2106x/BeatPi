#include <fstream>
#include "Httpd.hh"

Httpd::Httpd()
{
    _daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL, &handleRequest, NULL, MHD_OPTION_END);
    if (_daemon == NULL)
    {
        throw ("Could not start http daemon");
    }
}

Httpd::~Httpd()
{
  MHD_stop_daemon(_daemon);
}

int Httpd::handleRequest(void *cls, struct MHD_Connection *connection,
                      const char *url, const char *method,
                      const char *version, const char *upload_data,
                      size_t *upload_data_size, void **con_cls)
{
    const char *page = readHtmlFile("index.htm");
    struct MHD_Response *response;
    int ret;

    response = MHD_create_response_from_buffer (strlen (page), (void *) page, MHD_RESPMEM_PERSISTENT);
    ret = MHD_queue_response (connection, MHD_HTTP_OK, response);
    MHD_destroy_response (response);
    return (ret);
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