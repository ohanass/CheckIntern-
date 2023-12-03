#ifndef CURRICULO_HPP
#define CURRICULO_HPP

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

class Curriculo{
    private:
    float _salario;
    std::vector<std::string> _areasInteresse;
    std::vector<std::string> _aptidoes;
    std::vector<std::string> _beneficios;
    
    public:
    Curriculo() : _salario(0) {};
    Curriculo(float salario,std::vector<std::string> areasInteresse, std::vector<std::string> aptidoes, std::vector<std::string> beneficios) : 
    _salario(salario), _areasInteresse(areasInteresse), _aptidoes(aptidoes),  _beneficios(beneficios) {};
    float get_salario(void);
    std::vector<std::string> get_areasInteresse(void);
    std::vector<std::string> get_aptidoes(void);
    std::vector<std::string> get_beneficios(void);
    void atualizar_curriculo(float salario,std::vector<std::string> areasInteresse, std::vector<std::string> requisitos, std::vector<std::string> beneficios);
    void atualizar_curriculo(Curriculo* outro);   
    void mostrar_curriculo(void);
}; 
#endif