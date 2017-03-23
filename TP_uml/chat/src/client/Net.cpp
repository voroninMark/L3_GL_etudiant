#include "Net.hpp"

#include <iostream>
#include <sstream>

Net::Net(const std::string & host, int port, const std::string & username)
{
    // connect to server
    if (_socketToServer.connect(host, port) != sf::Socket::Done)
    {
        std::cout << "failed to connect to server" << std::endl;
        exit(-1);
    }
    std::cout << "connected to server" << std::endl;

    // send username to server
    sf::Packet packetToServer;
    packetToServer << username;
    if (_socketToServer.send(packetToServer) != sf::Socket::Done)
    {
        std::cout << "failed to register on server" << std::endl;
        exit(-1);
    }
    std::cout << "registered on server" << std::endl;
}

void Net::send(const std::string & message)
{
    sf::Packet packetToServer;
    packetToServer << message;
    if (_socketToServer.send(packetToServer) != sf::Socket::Done)
    {
        std::cout << "failed to send to server" << std::endl;
        exit(-1);
    }
}

std::string Net::receive()
{
    // wait and receive message from server
    sf::Packet packetFromServer;
    if (_socketToServer.receive(packetFromServer) != sf::Socket::Done)
        return std::string();

    // format message
    std::stringstream ss;
    std::string s;
    while (packetFromServer >> s)
        ss << " " << s;
    ss << std::endl;
    return ss.str();
}

