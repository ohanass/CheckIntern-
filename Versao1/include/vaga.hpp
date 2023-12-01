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

    /// @brief Construtor padrão da classe "Vaga"
    Vaga();
    
    /// @brief Contrutor da classe "Vaga" com parâmetros
    /// @param salario Salário atualizado da vaga
    /// @param requisitos Lista de requisitos atualizada da vaga
    /// @param beneficios Lista de benefícios atualizada da vaga
    Vaga(float salario, std::vector<std::string> requisitos, std::vector<std::string> beneficios)
    : _salario(salario), _requisitos(requisitos),  _beneficios(beneficios) {};
    
    /// @brief Obtem o salário de uma vaga específica
    /// @return Salário da vaga
    float get_salario();
    
    /// @brief Obtem a lista de requisitos referentes a uma vaga específica
    /// @return Lista de requisitos da vaga
    std::vector<std::string> get_requisitos();
    
    /// @brief Obtem a lista de benefícios fornecidos por uma vaga específica
    /// @return Lista de benefícios oferecidos pela vaga
    std::vector<std::string> get_beneficios();
    
    /// @brief Atualiza uma vaga através de paramêtros novos
    /// @param salario Salário atualizado da vaga
    /// @param requisitos Lista de requisitos atualizada da vaga
    /// @param beneficios Lista de benefícios atualizada da vaga
    void atualizar_vaga(float salario, std::vector<std::string> requisitos, std::vector<std::string> beneficios);
    
    /// @brief Atualiza uma vaga com os valores de outra vaga
    /// @param outro Ponteiro que aponta para a vaga que terá seus atributos
    ///              copiados para a vaga a qual qeuremos atualizar
    void atualizar_vaga(Vaga* outro);
    
    /// @brief Exibe informações de uma vaga
    void mostrar_vaga();
};
