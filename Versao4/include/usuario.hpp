#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <iostream>

class Usuario {
private:
    std::string _email; 
    std::string _login; 
    std::string _senha; 

public:
    // @brief Construtor da classe Usuario.
    // @param email Endereço de e-mail do usuário.
    // @param login Nome de login do usuário.
    // @param senha Senha do usuário.
    Usuario(std::string email, std::string login, std::string senha)
        : _email(email), _login(login), _senha(senha) {};

    // @brief Altera o endereço de e-mail do usuário.
    // @param email Novo endereço de e-mail.
    void alterar_email(std::string email);

    // @brief Altera o nome de login do usuário.
    // @param login Novo nome de login.
    void alterar_login(std::string login);

    // @brief Altera a senha do usuário.
    // @param senha_nova Nova senha.
    void alterar_senha(std::string senha_nova);

    // @brief Obtém o endereço de e-mail do usuário.
    // @return Endereço de e-mail do usuário.
    std::string get_email(void);

    // @brief Obtém o nome de login do usuário.
    // @return Nome de login do usuário.
    std::string get_login(void);

    // @brief Obtém a senha do usuário.
    // @return Senha do usuário.
    std::string get_senha(void);
};

#endif
