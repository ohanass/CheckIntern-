#ifndef COLEGIADO_HPP
#define COLEGIADO_HPP

#include "aluno.hpp"
#include "servidor.hpp"
#include "empresa.hpp"
#include <string>
#include <map>
#include <utility>

class Colegiado{
    private:
    std::map<std::string, Empresa*> _lista_empresas;
    std::map<std::string, Aluno*> _lista_alunos;
    std::map<std::string, Servidor*> _lista_servidores;
    public:
    //@brief Cadastra um novo servidor
    //@param novo_usuario O novo servidor a ser cadastrado
    void cadastrar_servidor(Servidor* novo_usuario);

    //@brief Tenta fazer login de um servidor
    //@param login O login do servidor
    //@param senha A senha do servidor
    //@return Retorna true se o login for bem-sucedido, false caso contr�rio
    bool entrar_servidor(std::string login, std::string senha);

    //@brief Altera o email de um servidor registrado no colegiado
    //@param login Login do servidor
    //@param email Novo email a ser atribu�do ao servidor
    //@return Retorna verdadeiro se a altera��o for bem-sucedida, falso caso contr�rio
    bool alterar_email_servidor(std::string login, std::string email);

    //@brief Altera o login de um servidor registrado no colegiado
    //@param login Login do servidor a ser alterado
    //@param novo_login Novo login a ser atribu�do ao servidor
    //@return Retorna verdadeiro se a altera��o for bem-sucedida, falso caso contr�rio
    bool alterar_login_servidor(std::string login, std::string novo_login);

    //@brief Altera a senha de um servidor registrado no colegiado
    //@param login Login do servidor a ter a senha alterada
    //@param senha_atual Senha atual do servidor
    //@param senha_nova Nova senha a ser atribu�da ao servidor
    //@return Retorna verdadeiro se a altera��o for bem-sucedida, falso caso contr�rio
    bool alterar_senha_servidor(std::string login, std::string senha_atual, std::string senha_nova);
    

    //@brief Cadastra uma nova empresa no colegiado
    //@param nova_empresa Ponteiro para a nova empresa a ser cadastrada
    void cadastrar_empresa(Empresa* nova_empresa);

    //@brief Adiciona uma nova vaga de emprego para uma empresa registrada no colegiado
    //@param cnpj CNPJ da empresa
    //@param vagas Ponteiro para a vaga a ser adicionada
    void adicionar_vaga(std::string cnpj, Vaga* vagas);

    //@brief Remove uma vaga de emprego de uma empresa registrada no colegiado
    //@param cnpj CNPJ da empresa
    //@param cod_vaga C�digo da vaga a ser removida
    void remover_vaga(std::string cnpj, unsigned long int cod_vaga);

    //@brief Mostra todas as vagas de emprego cadastradas no colegiado
    void mostrar_todas_vagas(void);

    //@brief Mostra os curr�culos enviados por candidatos para uma vaga espec�fica de uma empresa
    //@param cnpj CNPJ da empresa
    void mostrar_curriculos_enviados(std::string cnpj);

    //@brief Cadastra um novo aluno no colegiado
    //param novo_aluno Ponteiro para o novo aluno a ser cadastrado
    void cadastrar_aluno(Aluno* novo_aluno);

    //@brief Realiza a autentica��o de um aluno no colegiado
    //@param login Login do aluno
    //@param senha Senha do aluno
    //@return Retorna verdadeiro se a autentica��o for bem-sucedida, falso caso contr�rio
    bool entrar_aluno(std::string login, std::string senha);

    //@brief Altera o email de um aluno registrado no colegiado
    //@param login Login do aluno
    //@param email Novo email a ser atribu�do ao aluno
    //@return Retorna verdadeiro se a altera��o for bem-sucedida, falso caso contr�rio
    bool alterar_email_aluno(std::string login, std::string email);

    //@brief Altera o login de um aluno registrado no colegiado
    //@param login Login do aluno a ser alterado
    //@param novo_login Novo login a ser atribu�do ao aluno
    //@return Retorna verdadeiro se a altera��o for bem-sucedida, falso caso contr�rio
    bool alterar_login_aluno(std::string login, std::string novo_login);

    //@brief Altera a senha de um aluno registrado no colegiado
    //@param login Login do aluno a ter a senha alterada
    //@param senha_atual Senha atual do aluno
    //@param senha_nova Nova senha a ser atribu�da ao aluno
    //@return Retorna verdadeiro se a altera��o for bem-sucedida, falso caso contr�rio
    bool alterar_senha_aluno(std::string login, std::string senha_atual, std::string senha_nova);

    //@brief Atualiza o curr�culo de um aluno no colegiado
    //@param login Login do aluno
    //@param curriculo Ponteiro para o novo curr�culo do aluno
    void atualizar_curriculo(std::string login, Curriculo* curriculo);

    //@brief Mostra as vagas de emprego compat�veis com o perfil do aluno
    //@param login Login do aluno
    void mostrar_vagas_compativeis(std::string login);

    //@brief Mostra as vagas de emprego para as quais o aluno se candidatou
    //@param login Login do aluno
    void mostrar_vagas_candidatadas(std::string login);

    //@brief Mostra os detalhes de uma vaga de emprego espec�fica para a qual o aluno se candidatou
    //@param login Login do aluno
    //@param cod_vaga C�digo da vaga de emprego
    void mostrar_vaga_candidatada_detalhada(std::string login, unsigned long int cod_vaga);

    //@brief Envia o curr�culo de um aluno para uma vaga espec�fica de uma empresa
    //@param login Login do aluno
    //@param cnpj CNPJ da empresa
    //@param cod_vaga C�digo da vaga a qual o curr�culo ser� enviado
    void enviar_curriculo(std::string login,std::string cnpj, unsigned long int cod_vaga);
};
//@brief Fun��o que testa a compatibilidade entre o curr�culo de um candidato e uma lista de vagas
//@param curriculo Curr�culo do candidato
//@param vagas Vetor de ponteiros para vagas de emprego
void teste_compatibilidade(Curriculo curriculo, std::vector<Vaga*> vagas);

//@brief Fun��o que valida um CPF
//@param cpf Refer�ncia para a string contendo o CPF a ser validado
void validar_CPF(std::string &cpf);

//@brief Fun��o que valida um CNPJ
//@param cnpj Refer�ncia para a string contendo o CNPJ a ser validado
void validar_CNPJ(std::string &cnpj);

//@brief Fun��o que separa uma string em substrings usando como delimitador o caractere espa�o
//@param str Ponteiro para um vetor de strings que armazenar� as substrings resultantes
void separar_Str(std::vector<std::string>* str);
#endif