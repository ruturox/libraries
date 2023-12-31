#ifndef ethernetserver_h
#define ethernetserver_h

#include "Server.h"

class EthernetClient;

class EthernetServer :
  public Server {
  private:
    uint16_t _port;
    struct tcp_struct _tcp_server;
    struct tcp_struct *_tcp_client[MAX_CLIENT];

    void accept(void);
  public:
    EthernetServer(uint16_t port = 80);
    EthernetClient available();
    virtual void begin();
    virtual void begin(uint16_t port);
    void end(void);
    virtual size_t write(uint8_t);
    virtual size_t write(const uint8_t *buf, size_t size);
    virtual operator bool();
    using Print::write;
};

#endif
