#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <map>

void separar_Str(std::vector<std::string>* be){
    std::string aux;
    char input;
    do {
        input = getchar(); // Lê um caractere do console
        if ((input == ','&&!(aux.empty()))||(input == '\n'&&!(aux.empty()))) {
            be->push_back(aux);
            aux.clear();
        } else if (input != '\n'&&!(input==' '&&aux.empty())&&input != ',') {
            aux+=input;
        }
    } while (input != '\n');
}

int main(){
   
}
