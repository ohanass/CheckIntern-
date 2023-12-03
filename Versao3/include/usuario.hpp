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
    Usuario(std::string nome, std::string cpf, unsigned short int idade, std::string endereco, std::string curso, unsigned short int periodo,
    std::string numeroTelefone, std::string email, std::string login, std::string senha) :
    Aluno(nome, cpf, idade, endereco, curso, periodo, numeroTelefone), _email(email), _login(login), _senha(senha) {};
    void atualizar_curriculo(Curriculo* curriculo);
    void alterar_email(std::string email);
    void alterar_login(std::string login);
    void alterar_senha(std::string senha);
    void mostrar_curriculo(void);
    void enviar_curriculo(Vaga* vaga);
    void mostrar_vagasCadidatadas(void);
    void mostrar_vagaDetalhada(unsigned long int id);
    std::string get_email(void);
    std::string get_login(void);
    std::string get_senha(void);
    Curriculo get_curriculo(void);
};
#endif