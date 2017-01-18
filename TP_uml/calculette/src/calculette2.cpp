#include <iostream>

std::string saisirOperation()
{
    std::cout << "\nEntrez l'opération à réaliser (+, -, *, /, quitter) : ";
    std::string operation;
    std::getline(std::cin, operation);
    return operation;
}

void saisir2Entiers(int & a, int & b)
{
    try
    {
        std::string s;

        std::cout << "Entrez le premier nombre : ";
        std::getline(std::cin, s);
        a = std::stoi(s);

        std::cout << "Entrez le second nombre : ";
        std::getline(std::cin, s);
        b = std::stoi(s);
    }
    catch (...) 
    {
        throw std::string("nombre invalide");
    }
}

int calculerOperation(int a, int b, const std::string & op)
{
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "/") return a / b;
    if (op == "*") return a * b;
    throw std::string("operation inconnue");
}

void afficherResultat(int a, int b, const std::string & op, int res)
{
    std::cout << a << " " << op << " " << b << " = " << res << std::endl;
}

int main()
{
    // menu en boucle
    while (true)
    {
        std::string operation = saisirOperation();

        if (operation == "quitter")
        {
            std::cout << "Au revoir" << std::endl;
            break;
        }
        else  
        {
            try 
            {
                int x, y;
                saisir2Entiers(x, y);
                int r = calculerOperation(x, y, operation);
                afficherResultat(x, y, operation, r);
            }
            catch (const std::string & e) 
            {
                std::cout << "Erreur: " << e << std::endl;
            }
        }
    }

    return 0;
}

