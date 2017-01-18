#include "Ui.hpp"

int main(int argc, char ** argv) 
{
    // check command line arguments
    if (argc != 4)
    {
        std::cout << "usage: " << argv[0] << " <host> <port> <username>\n";
        exit(-1);
    }
    const std::string host(argv[1]);
    const int port(std::stoi(argv[2]));
    const std::string username(argv[3]);

    // connection to server
    Net net(host, port, username);

    // user interface
    Gtk::Main kit(argc, argv);
    Ui ui(net);
    kit.run(ui);

    return 0;
}

