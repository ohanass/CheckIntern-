#pragma once

#include "vaga.hpp"
#include <string>
#include <iostream>

class Estagiario{
    private:
    std::string _nome;
    std::string _senha;
    Vaga _curriculo;

    public:
    Estagiario(std::string nome, std::string senha);
    void atualizar_curriculo(Vaga* curriculo);
    void alterar_senha(std::string senha);
    void mostrar_curriculo();
    std::string get_nome();
    std::string get_senha();
    Vaga get_curriculo();
};