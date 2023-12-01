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
    // @brief Construtor da Classe Empresa

    // @param nome da empresa
    // @param Contas, mapa de contas da empresa a serem adicionadas
    Empresa(std::string nome, std::map<std::string,std::pair<std::string, std::string>> contas);

    // @brief Adiciona varias contas ao mapa de contas da empresa
    // @param contas Mapa de contas a serem adicionadas
    void adicionar_contas(std::map<std::string,std::pair<std::string, std::string>> contas);

    // @brief Remove uma conta do sistema com base no email fornecido
    // @param email Email da conta a ser removida
    void remover_conta(std::string email);

    // @brief Altera a senha associada a um email especifico
    // @param email Email da conta cuja senha será alterada
    // @param senha Nova senha a ser definida
    void alterar_senha(std::string email, std::string senha);

    // @brief Adiciona uma vaga ao vetor de vagas da empresa
    // @param vagas Ponteiro para a vaga a ser adicionada
    void adicionar_vaga(Vaga* vagas);

    // @brief Remove uma vaga com base no código da vaga
    // @param cod_vaga Código da vaga a ser removida
    void remover_vaga(unsigned long int cod_vaga);

    // @brief Exibe as vagas disponíveis
    void mostrar_vagas(void);

    // @brief @brief Remove um currículo com base no código da vaga e no nome do estagiário
    // @param @param cod_vaga Código da vaga associada ao currículo
    // @param nome Nome do estagiário cujo currículo será removido
    void remover_curriculo(unsigned long int cod_vaga, std::string nome);

    // @brief Remove um currículo apenas com base no nome do estagiário
    // @param nome Nome do estagiário cujo currículo será removido
    void remover_curriculo(std::string nome);

    // @brief Adiciona um currículo associado a uma vaga específica
    // @param cod_vaga Código da vaga à qual o currículo será associado
    // @param estagiario Ponteiro para o estagiário cujo currículo será adicionado
    void adicionar_curriculo(unsigned long int cod_vaga, Estagiario* estagiario);

    //@brief Exibe os currículos recebidos
    void mostrar_curriculos(void);

    // @brief Verifica se um determinado email está associado a uma conta existente na empresa
    // @param email Email a ser verificado
    // @return true se o email estiver associado a uma conta existente, false caso contrário
    bool encontrar_email(std::string email);

    // @brief Retorna o vetor de ponteiros para as vagas
    // @return vetor ponteiro
    std::vector<Vaga*> get_vagas();

    // @brief Retorna o nome da empresa
    // @return Nome
    std::string get_nome(void);

    // @brief Retorna a senha associada a um determinado email
    // @param email Email associado à senha desejada
    // @return senha de email
    std::string get_senha(std::string email);

    // @brief Retorna o nome associado a um email
    // @param email Email associado ao nome desejado
    // @return Nome ligado ao email
    std::string get_nome_conta(std::string email);
 };
#endif
