#include "Server.hpp"

#include <iostream>
#include <sstream>

Server::Server(int port) 
{
    // init listener
    if (_listener.listen(port) != sf::Socket::Done)
    {
        std::cout << "failed to listen to port " << port << std::endl;
        exit(-1);
    }
    _selector.add(_listener);
}

void Server::run()
{
    // main server loop
    while (true)
    {
        try 
        {
            // wait for data
            if (_selector.wait())
            {
                // data from the listener (new client)
                if (_selector.isReady(_listener))
                    handleNewClient();
                // data from a client (new message)
                else
                    handleNewMessage();
            }        
        }
        catch (const std::string & e)
        {
            std::cout << "error: " << e << std::endl;
        }
    }
}

void Server::handleNewClient()
{
    // accept a new client
    uptrSocket_t uptrSocket = std::make_unique<sf::TcpSocket>();
    sf::TcpSocket & clientSocket = *(uptrSocket);
    if (_listener.accept(clientSocket) != sf::Socket::Done)
        throw std::string("failed to accept socket");

    // receive name from client
    sf::Packet packetFromClient;
    if (clientSocket.receive(packetFromClient) != sf::Socket::Done)
        throw std::string("failed to receive data");

    // register new client
    std::string clientName;
    packetFromClient >> clientName;
    // client name already registered
    if (_clients.find(clientName) != _clients.end() 
            and _clients[clientName]._isOk)
    {
        std::cout << clientName << " rejected" << std::endl;
        sf::Packet packetToClient;
        packetToClient << clientName 
            << " already exists; try another username";
        uptrSocket->send(packetToClient);
        uptrSocket->disconnect();
    }
    // client name ok
    else
    {
        _selector.add(clientSocket);
        _clients[clientName] = {std::move(uptrSocket), true};
        std::cout << clientName << " accepted" << std::endl;

        // send info to all clients
        sf::Packet packetToClients;
        packetToClients << clientName << " has joined the room";
        broadcast(packetToClients);
    }
}

void Server::handleNewMessage()
{
    // search a registered client
    for (auto & client : _clients)
    {
        const std::string & clientName = client.first;
        sf::TcpSocket & clientSocket = *(client.second._socket);
        bool & clientOk = client.second._isOk;

        // client found
        if (clientOk and _selector.isReady(clientSocket))
        {
            // receive data from client
            sf::Packet packetFromClient;
            sf::Socket::Status status = 
                clientSocket.receive(packetFromClient);

            // check whether client is disconnected
            if (status == sf::Socket::Disconnected)
            {
                // unregistered client
                _selector.remove(clientSocket);
                clientSocket.disconnect();
                clientOk = false;
                std::cout << clientName << " disconnected" 
                    << std::endl;

                // send info to all clients
                sf::Packet packetToClients;
                packetToClients << clientName 
                    << " has left the room";
                broadcast(packetToClients);

                // stop the for-loop since clients have changed 
                break;
            }

            // send message to all clients
            if (status == sf::Socket::Done)
            {
                sf::Packet packetToClients;
                packetToClients << clientName << ":";
                std::string s;
                while (packetFromClient >> s)
                    packetToClients << " " << s;
                broadcast(packetToClients);
            }
        }
    }
}

void Server::broadcast(sf::Packet packetToClients)
{
    for (auto & client : _clients)
        if (client.second._isOk)
            client.second._socket->send(packetToClients);
}


