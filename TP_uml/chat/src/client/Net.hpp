#ifndef NET_HPP_
#define NET_HPP_

#include <SFML/Network.hpp>
#include <string>

class Net 
{
    private:
        sf::TcpSocket _socketToServer;

    public:
        Net(const std::string & host, int port, const std::string & username);
        void send(const std::string & message);
        std::string receive();
};

#endif

