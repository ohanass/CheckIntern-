#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <iostream>

class Usuario{
    private:
    std::string _email;
    std::string _login;
    std::string _senha;
    public:
    Usuario(std::string email, std::string login, std::string senha) 
    : _email(email), _login(login), _senha(senha) {};
    void alterar_email(std::string email);
    void alterar_login(std::string login);
    void alterar_senha(std::string senha_nova);
    std::string get_email(void);
    std::string get_login(void);
    std::string get_senha(void);
};
#endif