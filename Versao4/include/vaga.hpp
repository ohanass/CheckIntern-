#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

class Vaga{
    private:

    std::string _cargo;
    float _salario;
    std::string _endereco;
    unsigned short int _cargaHoraria;
    std::vector<std::string> _requisitos;
    std::vector<std::string> _beneficios;
    bool _ativa;
    
    public:

    /// @brief Construtor padrão da classe "Vaga"
    Vaga(): _salario(0), _cargaHoraria(0) {};

    /// @brief Contrutor da classe "Vaga" com parâmetros
    /// @param cargo Cargo ofertado pela vaga
    /// @param salario Salário atualizado da vaga
    /// @param endereco Endereço atualizado do trabalho
    /// @param cargaHoraria Carga horária atualizada da vaga
    /// @param requisitos Lista de requisitos atualizada da vaga
    /// @param beneficios Lista de benefícios atualizada da vaga
    Vaga(std::string cargo, float salario, std::string endereco, unsigned short int cargaHoraria, std::vector<std::string> requisitos, std::vector<std::string> beneficios) : 
    _cargo(cargo), _salario(salario), _endereco(endereco), _cargaHoraria(cargaHoraria), _requisitos(requisitos),  _beneficios(beneficios) {};

    /// @brief Obtem o cargo de uma ofertad e emprego específica
    /// @return Cargo ofertado
    std::string get_cargo();

    /// @brief Obtem o salário de uma vaga específica
    /// @return Salário da vaga
    float get_salario();

    /// @brief Obtem o endereço de uma vaga específica
    /// @return Endereço do trabalho
    std::string get_endereco();

    /// @brief Obtem a carga horária de uma vaga específica
    /// @return Carga horária de uma vaga
    unsigned short int get_cargaHoraria();

    /// @brief Obtem a lista de requisitos referentes a uma vaga específica
    /// @return Lista de requisitos da vaga
    std::vector<std::string> get_requisitos();

    /// @brief Obtem a lista de benefícios fornecidos por uma vaga específica
    /// @return Lista de benefícios oferecidos pela vaga
    std::vector<std::string> get_beneficios();

    /// @brief Atualiza uma vaga com os valores de outra vaga
    /// @param outro Ponteiro que aponta para a vaga que terá seus atributos
    ///              copiados para a vaga a qual queremos atualizar
    void atualizar_vaga(Vaga* outro);

    /// @brief Atualiza uma vaga através de paramêtros novos
    /// @param cargo Cargo ofertado pela vaga
    /// @param salario Salário atualizado da vaga
    /// @param endereco Endereço atualizado do trabalho
    /// @param cargaHoraria Carga horária atualizada da vaga
    /// @param requisitos Lista de requisitos atualizada da vaga
    /// @param beneficios Lista de benefícios atualizada da vaga
    void atualizar_vaga(std::string cargo, float salario, std::string endereco, unsigned short int cargaHoraria, std::vector<std::string> requisitos, std::vector<std::string> beneficios);

    /// @brief Exibe as informações de cargo, salario, endereço e carga horária de uma vaga
    void mostrar_vaga_resumido();

    /// @brief Exibe todas as informações de uma vaga
    void mostrar_vaga();

    /// @brief Inativa uma vaga caso esta já esteja definida para alguém
    void inativar_vaga();

    /// @brief Visualiza se uma vaga está ativa ou inativa
    bool get_ativa();
};