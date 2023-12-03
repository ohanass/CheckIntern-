#include "curriculo.hpp"


float Curriculo::get_salario(void){
    return this->_salario;
}

std::vector<std::string> Curriculo::get_areasInteresse(void){
    return this->_areasInteresse;
}

std::vector<std::string> Curriculo::get_aptidoes(void){
    return this->_aptidoes;
}

std::vector<std::string> Curriculo::get_beneficios(void){
    return this->_beneficios;
}

void Curriculo::atualizar_curriculo(float salario,std::vector<std::string> areasInteresse, std::vector<std::string> aptidoes, std::vector<std::string> beneficios){
    this->_salario=salario;
    this->_areasInteresse=areasInteresse;
    this->_aptidoes=aptidoes;
    this->_beneficios=beneficios;
}

void Curriculo::atualizar_curriculo(Curriculo* outro){
    this->_salario=outro->get_salario();
    this->_areasInteresse=outro->get_areasInteresse();
    this->_aptidoes=outro->get_aptidoes();
    this->_beneficios=outro->get_beneficios();
}


void Curriculo::mostrar_curriculo(void){
    std::cout<<"PRETENSAO SALARIAL: R$"<<std::fixed<<std::setprecision(2)<<this->_salario<<std::endl;
    std::cout<<"---------------------------"<<std::endl;
    std::cout<<"AREAS DE INTERESSE: "<<std::endl;
    for(long unsigned int i=0; i<this->_areasInteresse.size(); i++){
        std::cout<<"-"<<this->_areasInteresse[i]<<std::endl;
    }
    std::cout<<"---------------------------"<<std::endl;
    std::cout<<"APTIDOES: "<<std::endl;
    for(long unsigned int i=0; i<this->_aptidoes.size(); i++){
        std::cout<<"-"<<this->_aptidoes[i]<<std::endl;
    }
    std::cout<<"---------------------------"<<std::endl;
    std::cout<<"BENEFICIOS: "<<std::endl;
    for(long unsigned int i=0; i<this->_beneficios.size(); i++){
        std::cout<<"-"<<this->_beneficios[i]<<std::endl;
    }
    std::cout<<"---------------------------"<<std::endl;
}