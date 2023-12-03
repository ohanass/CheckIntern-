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
    // @brief Construtor padrão da classe Curriculo
    Curriculo() : _salario(0) {};

    // @brief Construtor da classe Curriculo que permite inicializar todos os atributos.
    // @param salario Salário associado ao currículo.
    // @param areasInteresse Vetor de áreas de interesse do estagiário.
    // @param aptidoes Vetor de aptidões do estagiário.
    // @param beneficios Vetor de benefícios.
    Curriculo(float salario,std::vector<std::string> areasInteresse, std::vector<std::string> aptidoes, std::vector<std::string> beneficios) : 
    _salario(salario), _areasInteresse(areasInteresse), _aptidoes(aptidoes),  _beneficios(beneficios) {};

    // @brief Método para obter o salário associado ao currículo.
    // @return Salário associado ao currículo.
    float get_salario(void);
    
    // @brief Obter as áreas de interesse do estagiário.
    // @return Vetor de áreas de interesse.
    std::vector<std::string> get_areasInteresse(void);

    // @brief Obter as aptidões do estagiário.
    // @return Vetor de aptidões.
    std::vector<std::string> get_aptidoes(void);

    // @brief Obter os benefícios oferecidos pelo estagiário.
    // @return Vetor de benefícios.
    std::vector<std::string> get_beneficios(void);

    // @brief Atualizar os atributos do currículo.
    // @param salario Novo salário associado ao currículo.
    // @param areasInteresse Novo vetor de áreas de interesse.
    // @param requisitos Novo vetor de requisitos (aptidões).
    // @param beneficios Novo vetor de benefícios.
    void atualizar_curriculo(float salario,std::vector<std::string> areasInteresse, std::vector<std::string> requisitos, std::vector<std::string> beneficios);

    // @brief Atualizar o currículo com base em outro currículo.
    // @param outro Ponteiro para outro currículo a ser usado como base para a atualização.
    void atualizar_curriculo(Curriculo* outro);   

    // @brief Mostra as informações do currículo.
    void mostrar_curriculo(void);
}; 
#endif
