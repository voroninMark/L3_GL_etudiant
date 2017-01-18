#include "Server.hpp"

#include <iostream>

int main(int argc, char ** argv) 
{
    // check command line arguments
    if (argc != 2)
    {
        std::cout << "usage: " << argv[0] << " <port>" << std::endl;
        exit(-1);
    }
    const int port = std::stoi(argv[1]);

    Server server(port);
    server.run();

    return 0;
}

