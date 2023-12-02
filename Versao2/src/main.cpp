#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <map>

//separa a string em um vetor
void separar_Str(std::vector<std::string>* be){
    std::string aux;        //variável que armazena a string temporária 
    char input;             //armazena o caractere lido 
    do {
        input = getchar(); 
        // leitura do caractere 
        if ((input == ','&&!(aux.empty()))||(input == '\n'&&!(aux.empty()))) {

            //verifica se encontrou vírgula E que a string não está vazia
            //OU se foi encontrada uma quebra de linha e a string não está vazia
            
            be->push_back(aux);        //adiciona a string ao vetor 
            aux.clear();
        } else if (input != '\n'&&!(input==' '&&aux.empty())&&input != ',') {
            aux+=input;
        }
    } while (input != '\n');
}

int main(){
   
}
