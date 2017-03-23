#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char ** argv) {

    if (argc != 2) {
        cerr << "usage: " << argv[0] << " <filename>\n";
        exit(-1);
    }

    int * V = nullptr;
    try {
        cout << "Open file\n";
        ifstream file(argv[1]);
        file.exceptions(ifstream::failbit);

        cout << "Read N\n";
        uint64_t N;
        file >> N;

        cout << "Allocate V\n";
        V = new int [N];

        cout << "Read V\n";
        for (unsigned i=0; i<N; i++)
            file >> V[i];

        cout << "Print V\n";
        for (unsigned i=0; i<N; i++)
            cout << V[i] << " ";
        cout << endl;

    } 
    catch (exception & e) {
        cout << "caught exception: " << e.what() << endl;
        if (V) delete [] V;
        exit(-1);
    }

    return 0;
}

