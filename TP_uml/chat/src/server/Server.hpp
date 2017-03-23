#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <SFML/Network.hpp>
#include <map>
#include <memory>

using uptrSocket_t = std::unique_ptr<sf::TcpSocket>;

struct ClientData
{
    uptrSocket_t _socket;
    bool _isOk;
};

class Server 
{
    private:
        sf::TcpListener _listener;
        sf::SocketSelector _selector;
        std::map<std::string, ClientData> _clients;

    public:
        Server(int port); 
        void run();

    private:
        void handleNewClient();
        void handleNewMessage();
        void broadcast(sf::Packet packetToClients);
};

#endif

