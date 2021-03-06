//
// Created by vitalya on 27.05.19.
//

#ifndef OS_NET_SOCKET_WRAPPER_H
#define OS_NET_SOCKET_WRAPPER_H

#include <netinet/in.h>
#include <sys/socket.h>
#include <string>
#include <zconf.h>

class socket_wrapper {
public:
    socket_wrapper();
    socket_wrapper(const socket_wrapper& other) = delete;
    socket_wrapper(socket_wrapper&& other) noexcept;
    ~socket_wrapper();

    socket_wrapper& operator=(const socket_wrapper& other) = delete;
    socket_wrapper& operator=(socket_wrapper&& other) noexcept;

    void bind(sockaddr_in& address);
    void listen();
    void unblock();
    void connect(sockaddr_in& address);
    socket_wrapper accept();
    std::string readMessage();
    void writeMessage(const std::string& message);

    int get_fd();

private:
    explicit socket_wrapper(int fd_);

private:
    int fd;
    int flags = 0;
};


#endif //OS_NET_SOCKET_WRAPPER_H
