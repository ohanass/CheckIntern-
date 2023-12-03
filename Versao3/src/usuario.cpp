#include "usuario.hpp"

void Usuario::atualizar_curriculo(Curriculo* curriculo){
    this->_curriculo.atualizar_curriculo(curriculo);
}

void Usuario::alterar_email(std::string email){
    this->_email=email;
}

void Usuario::alterar_login(std::string login){
    this->_login=login;
}

void Usuario::alterar_senha(std::string senha){
    this->_senha=senha;
}

void Usuario::mostrar_curriculo(void){
    this->mostrar_aluno();
    this->_curriculo.mostrar_curriculo();
}

void Usuario::enviar_curriculo(Vaga* vaga){
    this->_vagasCandidatadas.push_back(vaga);
}

void Usuario::mostrar_vagasCadidatadas(void){
    for(unsigned long int i=0;i<this->_vagasCandidatadas.size();++i){
        std::cout<<i+1<<"."<<std::endl;
        this->_vagasCandidatadas.at(i)->mostrar_vaga_resumido();
    }
}

void Usuario::mostrar_vagaDetalhada(unsigned long int id){
    if(id-1<this->_vagasCandidatadas.size()){
        this->_vagasCandidatadas.at(id-1)->mostrar_vaga();
    }
    else{
        std::cout<<"VAGA NÃO EXISTENTE"<<std::endl;
    }
}

std::string Usuario::get_email(void){
    return this->_email;
}

std::string Usuario::get_login(void){
    return this->_login;
}

std::string Usuario::get_senha(void){
    return this->_senha;
}

Curriculo Usuario::get_curriculo(void){
    return this->_curriculo;
}