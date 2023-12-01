#ifndef EMPRESAS_HPP
#define EMPRESAS_HPP

#include "vaga.hpp"
#include "estagiario.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <map>

class Empresa{
    private:
    std::string _nome;
    std::map<std::string,std::pair<std::string, std::string>> _contas;
    std::vector<Vaga*> _vagas;
    std::multimap<unsigned long int,Estagiario*> _curriculos_recebidos;

    public:
    Empresa(std::string nome, std::map<std::string,std::pair<std::string, std::string>> contas);
    void adicionar_contas(std::map<std::string,std::pair<std::string, std::string>> contas);
    void remover_conta(std::string email);
    void alterar_senha(std::string email, std::string senha);
    void adicionar_vaga(Vaga* vagas);
    void remover_vaga(unsigned long int cod_vaga);
    void mostrar_vagas(void);
    void remover_curriculo(unsigned long int cod_vaga, std::string nome);
    void remover_curriculo(std::string nome);
    void adicionar_curriculo(unsigned long int cod_vaga, Estagiario* estagiario);
    void mostrar_curriculos(void);
    bool encontrar_email(std::string email);
    std::vector<Vaga*> get_vagas();
    std::string get_nome(void);
    std::string get_senha(std::string email);
    std::string get_nome_conta(std::string email);
 };
#endif