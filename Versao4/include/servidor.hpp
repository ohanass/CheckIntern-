#ifndef SERVIDOR_HPP
#define SERVIDOR_HPP

#include <string>
#include <iostream>
#include "usuario.hpp"

class Servidor : public  Usuario{
    private:
    std::string _nome;
    std::string _cpf;   
    std::string _endereco; 
    std::string _numeroTelefone; 
    std::string _cadastroInstituicao;
    public:

    // @param nome Nome do servidor.
    // @param cpf CPF (Cadastro de Pessoa Física) do servidor.
    // @param endereco Endereço do servidor.
    // @param numeroTelefone Número de telefone do servidor.
    // @param cadastroInstituicao Informações de cadastro do servidor.
    // @param email Email do servidor.
    // @param login Informações de login do servidor.
    // @param senha Senha do servidor.
    Servidor(std::string nome, std::string cpf, std::string endereco,std::string numeroTelefone, 
    std::string cadastroInstituicao, std::string email, std::string login, std::string senha) :
    Usuario(email, login, senha), _nome(nome), _cpf(cpf), _endereco(endereco), _numeroTelefone(numeroTelefone), 
    _cadastroInstituicao(cadastroInstituicao) {};
    
    // @brief Exibe informações do servidor
    void mostrar_servidor(void);
    
    // @brief Obtém o nome do servidor.
    // @return Nome do servidor.
    std::string get_nome(void);
    
    // @brief Obtém o CPF do servidor.
    // @return CPF do servidor.
    std::string get_cpf(void);
    
    // @brief Obtém o endereço do servidor.
    // @return Endereço do servidor.
    std::string get_endereco(void);

    // @brief Obtém o número de telefone do servidor.
    // @return Número de telefone do servidor.
    std::string get_numeroTelefone(void);

    // @brief Obtém as informações de cadastro do servidor.
    // @return Informações de cadastro do servidor.    
    std::string get_cadastroInstituicao(void);
};
#endif
