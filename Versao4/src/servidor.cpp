#include "servidor.hpp"

void Servidor::mostrar_servidor(void){
    std::cout<<"---------------------------"<<std::endl;
    std::cout<<"NOME: "<<this->_nome<<std::endl;
    std::cout<<"CPF: ";
    for(unsigned int i=0;i<9;i+=3){
        std::cout<<this->_cpf.substr(0+i,3);
        if(i<6){
            std::cout<<".";
        }
    }
    std::cout<<"-"<<this->_cpf.substr(9,10)<<std::endl;
    std::cout<<"ENDERECO: "<<this->_endereco<<std::endl;
    std::cout<<"CONTATO: "<<this->_numeroTelefone.substr(0,2)<<" "<<_numeroTelefone.substr(2,5)<<"-"<<_numeroTelefone.substr(7,4)<<std::endl;
    std::cout<<"CADASTRO NA INSTITUICAO: "<<this->_cadastroInstituicao<<std::endl;
    std::cout<<"---------------------------"<<std::endl;
}

std::string Servidor::get_nome(void){
    return this->_nome;
}

std::string Servidor::get_cpf(void){
    return this->_cpf;
}

std::string Servidor::get_endereco(void){
    return this->_endereco;
}

std::string Servidor::get_numeroTelefone(void){
    return this->_numeroTelefone;
}

std::string Servidor::get_cadastroInstituicao(void){
    return this->_cadastroInstituicao;
}
