#include <CppUTest/CommandLineTestRunner.h>

// fichiers de tests unitaires des différents modules
#include "Chemin_test.hpp"
#include "Route_test.hpp"

int main(int argc, char ** argv) {
   return CommandLineTestRunner::RunAllTests(argc, argv);
}

