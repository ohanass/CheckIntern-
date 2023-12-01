#include "estagiario.hpp"

Estagiario::Estagiario(std::string nome, std::string senha){
    this->_nome=nome;
    this->_senha=senha;
}

void Estagiario::atualizar_curriculo(Vaga* curriculo){
    this->_curriculo.atualizar_vaga(curriculo);
}

void Estagiario::mostrar_curriculo(){
    std::cout<<"---------------------------"<<std::endl;
    std::cout<<"NOME: "<<_nome<<std::endl;
    std::cout<<"PRETENSÃO ";
    _curriculo.mostrar_vaga();
}

void Estagiario::alterar_senha(std::string senha){
    this->_senha=senha;
}

Vaga Estagiario::get_curriculo(){
    return this->_curriculo;
}

std::string Estagiario::get_nome(){
    return this->_nome;
}

std::string Estagiario::get_senha(){
    return this->_senha;
}