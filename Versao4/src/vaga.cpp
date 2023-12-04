#include "vaga.hpp"

std::string Vaga::get_cargo(void){
    return this->_cargo;
}

float Vaga::get_salario(void){
    return this->_salario;
}

std::string Vaga::get_endereco(void){
    return this->_endereco;
}

unsigned short int Vaga::get_cargaHoraria(void){
    return this->_cargaHoraria;
}

std::vector<std::string> Vaga::get_requisitos(void){
    return this->_requisitos;
}

std::vector<std::string> Vaga::get_beneficios(void){
    return this->_beneficios;
}

void Vaga::atualizar_vaga(Vaga* outro){
    this->_cargo = outro->get_cargo();
    this->_salario = outro->get_salario();
    this->_endereco = outro->get_endereco();
    this->_cargaHoraria = outro->get_cargaHoraria();
    this->_requisitos = outro->get_requisitos();
    this->_beneficios = outro->get_beneficios();
}


void Vaga::atualizar_vaga(std::string cargo, float salario, std::string endereco, unsigned short int cargaHoraria, std::vector<std::string> requisitos, std::vector<std::string> beneficios){
    this->_cargo = cargo;
    this->_salario = salario;
    this->_endereco = endereco;
    this->_cargaHoraria = cargaHoraria;
    this->_requisitos = requisitos;
    this->_beneficios = beneficios;
}

void Vaga::mostrar_vaga_resumido(void){
    std::cout << "CARGO: " << this->_cargo << std::endl;
    std::cout << "SALARIO: R$" << std::fixed << std::setprecision(2) << this->_salario << std::endl;
    std::cout << "ENDERECO: " << this->_endereco << std::endl;
    std::cout << "CARGA HORARIA: " << this->_cargaHoraria << "H" << std::endl;
    std::cout << "---------------------------" << std::endl;
}


void Vaga::mostrar_vaga(void){
    std::cout << "CARGO: " << this->_cargo << std::endl;
    std::cout << "SALARIO: R$" << std::fixed << std::setprecision(2) << this->_salario << std::endl;
    std::cout << "ENDERECO: " << this->_endereco << std::endl;
    std::cout << "CARGA HORARIA: " << this->_cargaHoraria << "H" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "REQUISITOS: " << std::endl;
    for(long unsigned int i = 0; i < this->_requisitos.size(); i++){
        std::cout << "-" << this->_requisitos[i] << std::endl;
    }
    std::cout << "---------------------------" << std::endl;
    std::cout << "BENEFICIOS: " << std::endl;
    for(long unsigned int i = 0; i < this->_beneficios.size(); i++){
        std::cout<<"-" << this->_beneficios[i] << std::endl;
    }
    std::cout << "---------------------------" << std::endl;
}

void Vaga::inativar_vaga(void){
    this->_ativa = false;
}

bool Vaga::get_ativa(void){
    return this->_ativa;
}
