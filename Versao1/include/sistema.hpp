#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "estagiario.hpp"
#include "empresa.hpp"
#include <string>
#include <map>
#include <utility>

class Sistema{
    private:
    std::map<std::string, Empresa*> _lista_empresas;
    std::map<std::string, Estagiario*> _lista_estagiarios;

    public:
    // @brief Cadastrar uma nova empresa no sistema.
    // @param cnpj CNPJ da empresa a ser cadastrada.
    // @param nova_empresa Ponteiro para a nova empresa a ser registrada no sistema.
    void cadastrar_empresa(std::string cnpj, Empresa* nova_empresa);
    
    // @brief  Adiciona contas a uma empresa já registrada no sistema.
    // @param cnpj CNPJ da empresa à qual as contas serão adicionadas.
    // @param contas Mapa de contas a serem adicionadas.
    void adicionar_conta_empresa(std::string cnpj, std::map<std::string,std::pair<std::string, std::string>> contas);
    
    // @brief Login de uma empresa no sistema.
    // @param cnpj CNPJ da empresa que deseja fazer login.
    // @param email Email associado à conta da empresa.
    // @param senha Senha associada à conta da empresa.
    // @return True se o login for bem-sucedido, false caso contrário.
    bool entrar_conta_empresa(std::string cnpj, std::string email, std::string senha);

    // @brief Adiciona uma vaga a uma empresa específica.
    // @param cnpj CNPJ da empresa à qual a vaga será adicionada.
    // @param vagas Ponteiro para a vaga a ser adicionada.
    void adicionar_vaga(std::string cnpj, Vaga* vagas);

    // @brief Remover uma vaga de uma empresa específica.
    // @param cnpj CNPJ da empresa da qual a vaga será removida.
    // @param cod_vaga Código da vaga a ser removida.
    void remover_vaga(std::string cnpj, unsigned long int cod_vaga); 

    // @brief Avalia currículos recebidos para uma determinada vaga de uma empresa.
    // @param cnpj CNPJ da empresa que deseja avaliar os currículos.
    // @param cod_vaga Código da vaga para a qual os currículos serão avaliados.
    void avaliar_curriculos(std::string cnpj, unsigned long int cod_vaga);

    // @brief Cadastra um novo estagiário no sistema.
    // @param email Email do estagiário a ser cadastrado.
    // @param nome Nome do estagiário a ser cadastrado.
    // @param senha Senha do estagiário a ser cadastrado.
    void cadastrar_estagiario(std::string email, std::string nome, std::string senha);

    // @brief Realiza o login de um estagiário no sistema.
    // @param email Email associado à conta do estagiário.
    // @param senha Senha associada à conta do estagiário.
    // @return True se o login for bem-sucedido, false caso contrário.
    bool entrar_conta_estagiario(std::string email, std::string senha);

    // @brief Atualiza o currículo de um estagiário.
    // @param email  Email do estagiário cujo currículo será atualizado.
    // @param curriculo Ponteiro para a vaga que representa o currículo atualizado.
    void atualizar_curriculo(std::string email, Vaga* curriculo);

    // @brief Mostra as vagas compatíveis com o currículo de um estagiário.
    // @param email Email do estagiário.
    void mostrar_vagas_compativeis(std::string email);

    // @brief Enviar o currículo de um estagiário para empresas com vagas compatíveis.
    // @param email Email do estagiário.
    void enviar_curriculo(std::string email);
    
    // @brief Mostra todas as vagas disponíveis no sistema.
    void mostrar_todas_vagas(void);
};

// @brief Função para testar a compatibilidade entre um currículo e um vetor de vagas.
// @param_curriculo Representa o currículo do estagiário.
// @param_vagas Vetor de ponteiros para vagas a serem comparadas com o currículo.
void teste_compatibilidade(Vaga curriculo, std::vector<Vaga*> vagas);

#endif
