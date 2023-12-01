#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

class Vaga{
    private:

    float _salario;
    std::vector<std::string> _requisitos;
    std::vector<std::string> _beneficios;
    
    public:
    Vaga();
    Vaga(float salario, std::vector<std::string> requisitos, std::vector<std::string> beneficios) 
    : _salario(salario), _requisitos(requisitos),  _beneficios(beneficios) {};
    float get_salario();
    std::vector<std::string> get_requisitos(void);
    std::vector<std::string> get_beneficios(void);
    void atualizar_vaga(float salario, std::vector<std::string> requisitos, std::vector<std::string> beneficios);
    void atualizar_vaga(Vaga* outro);
    void mostrar_vaga();
};