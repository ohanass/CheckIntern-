#ifndef COLEGIADO_HPP
#define COLEGIADO_HPP

#include "usuario.hpp"
#include "empresa.hpp"
#include <string>
#include <map>
#include <utility>

class Colegiado {
private:
    std::map<std::string, Empresa*> _lista_empresas;
    std::map<std::string, Usuario*> _lista_usuarios;
public:
    // @brief Cadastra uma nova empresa no colegiado
    // @param nova_empresa Ponteiro para a nova empresa a ser cadastrada
    void cadastrar_empresa(Empresa* nova_empresa);

    // @brief  Adiciona uma vaga � empresa com base no CNPJ
    // @param cnpj CNPJ da empresa
    // @param vagas Ponteiro para a vaga a ser adicionada
    void adicionar_vaga(std::string cnpj, Vaga* vagas);

    // @brief Remove uma vaga de uma empresa com base no CNPJ e no c�digo da vaga
    // @@param cnpj CNPJ da empresa
    //@param cod_vaga C�digo da vaga a ser removida
    void remover_vaga(std::string cnpj, unsigned long int cod_vaga);

    // @brief Cadastra um novo usu�rio no colegiado
    // @param novo_usuario Ponteiro para o novo usu�rio a ser cadastrado
    void cadastrar_usuario(Usuario* novo_usuario);

    // @brief Permite o acesso � conta do usu�rio com login e senha
    // @param login Login do usu�rio
    // @param senha Senha do usu�rio
    // @return Verdadeiro se o acesso foi bem-sucedido, falso caso contr�rio
    bool entrar_conta_usuario(std::string login, std::string senha);

    // @brief Atualiza o curr�culo de um usu�rio
    // @param login Login do usu�rio
    // @param curriculo Ponteiro para o novo curr�culo a ser atualizado
    void atualizar_curriculo(std::string login, Curriculo* curriculo);

    // @brief Mostra as vagas compat�veis com o curr�culo de um usu�rio
    // @param login Login do usu�rio
    void mostrar_vagas_compativeis(std::string login);

    // @brief Envia o curr�culo de um usu�rio por e-mail
    // @param email Endere�o de e-mail para envio do curr�culo
    void enviar_curriculo(std::string email);

    // @brief Mostra todas as vagas dispon�veis no colegiado
    void mostrar_todas_vagas(void);
};

// @brief Testa a compatibilidade entre um curr�culo e um conjunto de vagas
// @param curriculo Curr�culo do usu�rio
// @param vagas Vetor de ponteiros para vagas a serem testadas
void teste_compatibilidade(Curriculo curriculo, std::vector<Vaga*> vagas);

#endif