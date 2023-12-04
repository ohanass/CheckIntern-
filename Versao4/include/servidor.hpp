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
    Servidor(std::string nome, std::string cpf, std::string endereco,std::string numeroTelefone, 
    std::string cadastroInstituicao, std::string email, std::string login, std::string senha) :
    Usuario(email, login, senha), _nome(nome), _cpf(cpf), _endereco(endereco), _numeroTelefone(numeroTelefone), 
    _cadastroInstituicao(cadastroInstituicao) {};
    void mostrar_servidor(void);
    std::string get_nome(void);
    std::string get_cpf(void);
    std::string get_endereco(void);
    std::string get_numeroTelefone(void);
    std::string get_cadastroInstituicao(void);
};
#endif
