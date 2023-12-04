#pragma once

#include <string> 
#include <iostream>
#include <vector>
#include "usuario.hpp"
#include "curriculo.hpp"
#include "vaga.hpp"

class Aluno : public  Usuario{
    private:

    std::string _nome;
    std::string _cpf; 
    unsigned short int _idade; 
    std::string _endereco; 
    std::string _curso; 
    unsigned short int _periodo;
    std::string _numeroTelefone; 
    Curriculo _curriculo;
    std::vector<Vaga*> _vagasCandidatadas;

    public:

    /// @brief Construtor padrão de "Aluno"
    /// @param nome Nome completo do aluno
    /// @param cpf CPF do aluno
    /// @param idade Idade do aluno
    /// @param endereco Endereço de residência do aluno
    /// @param curso Curso que o aluno está cursando
    /// @param periodo Período atual que o aluno está
    /// @param numeroTelefone Número de contato do aluno
    /// @param email Email do aluno
    /// @param login login da conta do aluno
    /// @param senha senha da conta do aluno
    Aluno(std::string nome, std::string cpf, unsigned short int idade, std::string endereco, std::string curso, 
    unsigned short int periodo,std::string numeroTelefone, std::string email, std::string login, std::string senha) :
    _nome(nome), _cpf(cpf), _idade(idade), _endereco(endereco), _curso(curso), _periodo(periodo), _numeroTelefone(numeroTelefone), 
    Usuario(email, login, senha){};

    /// @brief Atualiza um currículo com os valores de outro currículo
    /// @param outro Ponteiro que aponta para o currículo que terá seus atributos
    ///              copiados para o currículo a qual queremos atualizar
    void atualizar_curriculo(Curriculo* curriculo);

    // @brief Mostra as informações do currículo.
    void mostrar_curriculo();

    /// @brief Exibe informações resumidas de todas as vagas candidatadas pelo aluno
    void mostrar_vagasCandidatadas();

    /// @brief Exibe os detalhes de uma vaga candidatada pelo aluno
    /// @param id Identificador da vaga candidatada
    void mostrar_vagaDetalhada(unsigned long int id);

    /// @brief Exibe o currículo do aluno
    /// @return Currículo desejado
    Curriculo get_curriculo();

    /// @brief Exibe todas as informações de um aluno
    /// @return Nome completo, CPF, idade, endereço, curso, período atual e número de telefone do usuário
    void mostrar_aluno();

    /// @brief Exibe o nome completo do aluno
    /// @return Nome completo do aluno
    std::string get_nome();

    /// @brief Exibe o CPF do aluno
    /// @return CPF do aluno
    std::string get_cpf();

    /// @brief Exibe a idade do aluno
    /// @return Idade do aluno
    unsigned short int get_idade();

    /// @brief Exibe o endereço do aluno
    /// @return Endereço do aluno
    std::string get_endereco();


    /// @brief Exibe o curso do aluno
    /// @return Curso do aluno
    std::string get_curso();

    /// @brief Exibe o período que o aluno se encontra
    /// @return Período atual do aluno
    unsigned short int get_periodo();

    /// @brief Exibe o número de telefone do aluno
    /// @return Número de telefone do aluno
    std::string get_numeroTelefone();
};