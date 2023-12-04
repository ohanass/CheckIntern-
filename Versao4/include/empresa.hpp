#ifndef EMPRESAS_HPP
#define EMPRESAS_HPP

#include "vaga.hpp"
#include "aluno.hpp"
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
    std::map<unsigned long int, Vaga*> _vagas; 
    std::multimap<unsigned long int, Aluno*> _curriculos; 
    static unsigned long int _cod_vaga;
    public:
    //@brief Construtor da classe Empresa
    //@param nome Nome da empresa
    //@param cnpj CNPJ da empresa
    //@param numeroContato N�mero de contato da empresa
    //@param email Email da empresa
    Empresa(std::string nome, std::string CNPJ, std::string numeroContato, std::string email) :
    _nome(nome), _CNPJ(CNPJ), _numeroContato(numeroContato), _email(email) {};

    //@brief Altera o nome da empresa
    //@param nome Novo nome da empresa
    void alterar_nome(std::string nome);

    //@brief Altera o numero de contato da empresa
    //@param email Novo email da empresa
    void alterar_numeroContato(std::string numeroContato);

    //@brief Altera o email da empresa
    //@param email Novo email da empresa
    void alterar_email(std::string email);

    //@brief Adiciona uma nova vaga � empresa
    //@param vagas Ponteiro para a vaga a ser adicionada
    void adicionar_vaga(Vaga* vagas);

    //@brief Remove uma vaga da empresa
    //@param cod_vaga C�digo da vaga a ser removida
    void remover_vaga(unsigned long int cod_vaga);

    //@brief Mostra todas as vagas disponiveis na empresa
    void mostrar_vagas(void);

    //@brief Recebe o curr�culo de um aluno para uma vaga espec�fica
    //@param cod_vaga C�digo da vaga � qual o curr�culo est� sendo enviado
    //@param curriculo Ponteiro para o curr�culo do aluno
    void receber_curriculo(unsigned long int, Aluno* curriculo);

    //@brief Verifica se uma vaga espec�fica existe na empresa
    //@param cod_vaga C�digo da vaga a ser verificada
    //@return Retorna verdadeiro se a vaga existir, falso caso contr�rio
    bool verifica_existenciaVaga(unsigned long int cod_vaga);

    //@brief Mostra todos os curr�culos recebidos pela empresa
    void mostrar_curriculos(void);

    //@brief Obt�m uma vaga espec�fica da empresa
    //@param cod_vaga C�digo da vaga desejada
    //@return Retorna um ponteiro para a vaga desejada, se encontrada, ou nullptr caso contr�rio
    Vaga* get_vaga(unsigned long int cod_vaga);

    //@brief Obtem todas as vagas da empresa
    //@return Retorna um mapa contendo todas as vagas da empresa
    std::map<unsigned long int, Vaga*> get_vagas(void);

    //@brief Obt�m o nome da empresa
    // @return Retorna o nome da empresa
    std::string get_nome(void);

    //@brief Obt�m o CNPJ da empresa
    //@return Retorna o CNPJ da empresa
    std::string get_CNPJ(void);
 };
#endif