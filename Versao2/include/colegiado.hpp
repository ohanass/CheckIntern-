#ifndef COLEGIADO_HPP
#define COLEGIADO_HPP

#include "usuario.hpp"
#include "empresa.hpp"
#include <string>
#include <map>
#include <utility>

class Colegiado{
    private:
    std::map<std::string, Empresa*> _lista_empresas;
    std::map<std::string, Usuario*> _lista_usuarios;
    public:
    // @brief Cadastra uma nova empresa no colegiado
    // @param nova_empresa Ponteiro para a nova empresa a ser cadastrada
    void cadastrar_empresa(Empresa* nova_empresa);

    // @brief  Adiciona uma vaga à empresa com base no CNPJ
    // @param cnpj CNPJ da empresa
    // @param vagas Ponteiro para a vaga a ser adicionada
    void adicionar_vaga(std::string cnpj, Vaga* vagas);
    
    // @brief Remove uma vaga de uma empresa com base no CNPJ e no código da vaga
    // @@param cnpj CNPJ da empresa
    //@param cod_vaga Código da vaga a ser removida
    void remover_vaga(std::string cnpj, unsigned long int cod_vaga); 

    // @brief Cadastra um novo usuário no colegiado
    // @param novo_usuario Ponteiro para o novo usuário a ser cadastrado
    void cadastrar_usuario(Usuario* novo_usuario);

    // @brief Permite o acesso à conta do usuário com login e senha
    // @param login Login do usuário
    // @param senha Senha do usuário
    // @return Verdadeiro se o acesso foi bem-sucedido, falso caso contrário
    bool entrar_conta_usuario(std::string login, std::string senha);

    // @brief Atualiza o currículo de um usuário
    // @param login Login do usuário
    // @param curriculo Ponteiro para o novo currículo a ser atualizado
    void atualizar_curriculo(std::string login, Curriculo* curriculo);

    // @brief Mostra as vagas compatíveis com o currículo de um usuário
    // @param login Login do usuário
    void mostrar_vagas_compativeis(std::string login);

    // @brief Envia o currículo de um usuário por e-mail
    // @param email Endereço de e-mail para envio do currículo
    void enviar_curriculo(std::string email);

    // @brief Mostra todas as vagas disponíveis no colegiado
    void mostrar_todas_vagas(void);
};

// @brief Testa a compatibilidade entre um currículo e um conjunto de vagas
// @param curriculo Currículo do usuário
// @param vagas Vetor de ponteiros para vagas a serem testadas
void teste_compatibilidade(Curriculo curriculo, std::vector<Vaga*> vagas);

#endif
