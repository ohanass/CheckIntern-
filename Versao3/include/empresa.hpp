#ifndef EMPRESAS_HPP
#define EMPRESAS_HPP

#include "vaga.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <map>

class Empresa {
private:
    std::string _nome;
    std::string _CNPJ;
    std::string _numeroContato;
    std::string _email;
    std::vector<Vaga*> _vagas;

public:
    // @brief Construtor da classe Empresa
    // @param nome Nome da empresa
    // @param CNPJ CNPJ da empresa
    // @param numeroContato N�mero de contato da empresa
    // @param email Email da empresa
    Empresa(std::string nome, std::string CNPJ, std::string numeroContato, std::string email) :
        _nome(nome), _CNPJ(CNPJ), _numeroContato(numeroContato), _email(email) {};

    // @brief Altera o nome da empresa
    // @param nome Novo nome da empresa.
    void alterar_nome(std::string nome);

    // @brief Altera o n�mero de contato da empresa
    // @param numeroContato Novo n�mero de contato da empresa
    void alterar_numeroContato(std::string numeroContato);

    // @brief Altera o email da empresa
    // @param email Novo email da empresa
    void alterar_email(std::string email);

    // @brief Adiciona uma vaga ao conjunto de vagas oferecidas pela empresa
    //@param vagas Ponteiro para a vaga a ser adicionada
    void adicionar_vaga(Vaga* vagas);

    // @brief Remove uma vaga do conjunto de vagas oferecidas pela empresa com base no c�digo da vaga
    // @param cod_vaga C�digo da vaga a ser removida
    void remover_vaga(unsigned long int cod_vaga);

    // @brief Mostra as vagas oferecidas pela empresa
    void mostrar_vagas(void);

    // @brief Obt�m o vetor de ponteiros para as vagas oferecidas pela empresa
    // @return Vetor de ponteiros para as vagas
    std::vector<Vaga*> get_vagas();

    // @brief Obt�m o nome da empresa
    // @return Nome da empresa
    std::string get_nome(void);

    // @brief Obt�m o CNPJ da empresa
    // @return CNPJ da empresa
    std::string get_CNPJ(void);
};
#endif