#include "aluno.hpp"

void Aluno::mostrar_aluno(void){
    std::cout << "---------------------------" << std::endl;
    std::cout << "NOME: "<<this->_nome << std::endl;
    std::cout << "CPF: ";
    for(unsigned int i = 0;i<9;i += 3){
        std::cout << this->_cpf.substr(0+i,2+i);
        if(i<6){
            std::cout << ".";
        }
    }
    std::cout << "-" << this->_cpf.substr(9,10);
    std::cout << "IDADE: " << this->_idade << std::endl;
    std::cout << "ENDERECO: " << this->_endereco << std::endl;
    std::cout << "CURSO: " << this->_curso << std::endl;
    std::cout << "PERIODO: " << this->_periodo << std::endl;
    std::cout << "CONTATO: " << this->_numeroTelefone << std::endl;
    std::cout << "---------------------------" << std::endl;
}

std::string Aluno::get_nome(void){
    return this->_nome;
}

std::string Aluno::get_cpf(void){
    return this->_cpf;
}

unsigned short int Aluno::get_idade(void){
    return this->_idade;
}

std::string Aluno::get_endereco(void){
    return this->_endereco;
}

std::string Aluno::get_curso(void){
    return this->_curso;
}

unsigned short int Aluno::get_periodo(void){
    return this->_periodo;
}

std::string Aluno::get_numeroTelefone(void){
    return this->_numeroTelefone;
}