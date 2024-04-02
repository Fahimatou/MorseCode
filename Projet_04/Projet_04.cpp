#include <iostream>
using namespace std;
#include <windows.h>
using std::string;
#include <string>
#include "fonctionMorse.h"
#include <algorithm>



int main()
{
    std::string phrase;

    std::cout << "Entrez votre phrase" << std::endl;
    std::getline(cin, phrase);

    // Convertir la phrase entrée en minuscules en utlisant un algorithme
    transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);

    strMorse(phrase.c_str(), true);

 
    
    return 0;

    








}

