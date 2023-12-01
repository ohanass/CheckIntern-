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

    /// @brief Contrutor da classe "Estagiario" com parâmetros
    /// @param nome Nome do estagiário
    /// @param senha Senha da conta do estagiário
    Estagiario(std::string nome, std::string senha);

    /// @brief Atualiza o currículo com base nas informações de outro currículo
    /// @param curriculo Ponteiro que aponta para o currículo que terá seus atributos
    ///                           copiados para o currículo o qual queremos atualizar
    void atualizar_curriculo(Vaga* curriculo);

    /// @brief Altera a senha do usuário
    /// @param senha Nova senha da conta do usuário
    void alterar_senha(std::string senha);

    /// @brief Exibe informações do currículo do usuário
    void mostrar_curriculo();

    /// @return O nome do estagiário
    std::string get_nome();

    /// @return A senha do usuário
    std::string get_senha();

    /// @return Currículo de um estagiário
    Vaga get_curriculo();
};
