#include "usuario.hpp"

void Usuario::alterar_email(std::string email){
    this->_email=email;
}

void Usuario::alterar_login(std::string login){
    this->_login=login;
}

void Usuario::alterar_senha(std::string senha){
    this->_senha=senha;
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