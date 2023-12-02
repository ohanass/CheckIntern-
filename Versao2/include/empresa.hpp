#ifndef EMPRESAS_HPP
#define EMPRESAS_HPP

#include "vaga.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <map>

class Empresa{
    private:
    std::string _nome;
    std::string _CNPJ;
    std::string _numeroContato;
    std::string _email;
    std::vector<Vaga*> _vagas;

    public:
    Empresa(std::string nome, std::string CNPJ, std::string numeroContato, std::string email) :
    _nome(nome), _CNPJ(CNPJ), _numeroContato(numeroContato), _email(email) {};
    void alterar_nome(std::string nome);
    void alterar_numeroContato(std::string numeroContato);
    void alterar_email(std::string email);
    void adicionar_vaga(Vaga* vagas);
    void remover_vaga(unsigned long int cod_vaga);
    void mostrar_vagas(void);
    std::vector<Vaga*> get_vagas();
    std::string get_nome(void);
    std::string get_CNPJ(void);
 };
#endif