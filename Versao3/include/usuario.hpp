#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "aluno.hpp"
#include "curriculo.hpp"
#include "vaga.hpp"
#include <string>
#include <iostream>

class Usuario : public Aluno{
    private:
    std::string _email;
    std::string _login;
    std::string _senha;
    Curriculo _curriculo;
    std::vector<Vaga*> _vagasCandidatadas;
    public:
    // @brief Construtor da classe Usuario.
    // @param nome Nome do usuário.
    // @param cpf CPF do usuário.
    // @param idade Idade do usuário.
    // @param endereco Endereço do usuário.
    // @param curso Curso do usuário.
    // @param periodo Período do curso do usuário.
    // @param numeroTelefone Número de telefone do usuário.
    // @param email Endereço de e-mail do usuário.
    // @param login Nome de login do usuário.
    // @param senha Senha do usuário.
    Usuario(std::string nome, std::string cpf, unsigned short int idade, std::string endereco, std::string curso, unsigned short int periodo,
    std::string numeroTelefone, std::string email, std::string login, std::string senha) :
    Aluno(nome, cpf, idade, endereco, curso, periodo, numeroTelefone), _email(email), _login(login), _senha(senha) {};
    void atualizar_curriculo(Curriculo* curriculo);

    // @brief Altera o email do usuário.
    // @param email Novo email.
    void alterar_email(std::string email);

    // @brief Altera o nome de login do usuário.
    // @param login Novo nome de login.
    void alterar_login(std::string login);

    // @brief Altera a senha do usuário.
    // @param senha Nova senha.
    void alterar_senha(std::string senha);

    // @brief Mostra as informações do currículo do usuário.
    void mostrar_curriculo(void);

    // @brief Envia o currículo do usuário para uma vaga específica.
    // @param vaga Ponteiro para a vaga à qual o currículo será enviado.
    void enviar_curriculo(Vaga* vaga);

    // @brief Exibe as vagas às quais o usuário se candidatou.
    void mostrar_vagasCadidatadas(void);

    // @brief Exibe os detalhes de uma vaga específica.
    // @param id Identificador único da vaga.
    void mostrar_vagaDetalhada(unsigned long int id);
    
    // @brief Obter o email do usuário.
    // @return Email do usuário.
    std::string get_email(void);
    
    // @brief Obter o nome de login do usuário.
    // @return Nome de login do usuário.
    std::string get_login(void);

    // @brief Obter a senha do usuário.
    // @return Senha do usuário.
    std::string get_senha(void);

    // @brief Obter o currículo do usuário.
    // @return Objeto Curriculo associado ao usuário.
    Curriculo get_curriculo(void);
};
#endif
