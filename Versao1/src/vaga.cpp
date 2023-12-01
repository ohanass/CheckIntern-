#include "vaga.hpp"

Vaga::Vaga(){
    this->_salario = 0;
}

float Vaga::get_salario(void){
    return this->_salario;
}

std::vector<std::string> Vaga::get_requisitos(void){
    return this->_requisitos;
}

std::vector<std::string> Vaga::get_beneficios(void){
    return this->_beneficios;
}


void Vaga::atualizar_vaga(float salario, std::vector<std::string> requisitos, std::vector<std::string> beneficios){
    this->_salario = salario;
    this->_requisitos = requisitos;
    this->_beneficios = beneficios;
}

void Vaga::atualizar_vaga(Vaga* outro){
    this->_salario = outro->get_salario();
    this->_requisitos = outro->get_requisitos();
    this->_beneficios = outro->get_beneficios();
}

void Vaga::mostrar_vaga(void){
    std::cout << "SALARIO: R$"<<std::fixed << std::setprecision(2) << _salario << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "APTIDOES: " << std::endl;
    for(long unsigned int i = 0; i < this->_requisitos.size(); i++){
        std::cout << "-" << this->_requisitos[i] << std::endl;
    }
    std::cout << "---------------------------" << std::endl;
    std::cout<< "BENEFICIOS: " << std::endl;
    for(long unsigned int i = 0; i < this->_beneficios.size(); i++){
        std::cout << "-" << this->_beneficios[i] << std::endl;
    }
    std::cout << "---------------------------" << std::endl;
}

