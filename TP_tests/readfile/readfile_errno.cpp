#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char ** argv) {

    if (argc != 2) {
        cerr << "usage: " << argv[0] << " <filename>\n";
        exit(-1);
    }

    cout << "Open file\n";
    ifstream file(argv[1]);
    if (not file.good()) {
        cerr << "ifstream failed\n";
        exit(-1);
    }

    cout << "Read N\n";
    uint64_t N;
    file >> N;
    // TODO

    cout << "Allocate V\n";
    int * V =  (int*)malloc(N*sizeof(int));
    // TODO

    cout << "Read V\n";
    for (unsigned i=0; i<N; i++)
        file >> V[i];
    // TODO

    cout << "Print V\n";
    for (unsigned i=0; i<N; i++)
        cout << V[i] << " ";
    cout << endl;

    free(V);

    return 0;
}

