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
    void cadastrar_empresa(Empresa* nova_empresa);
    void adicionar_vaga(std::string cnpj, Vaga* vagas);
    void remover_vaga(std::string cnpj, unsigned long int cod_vaga); 

    void cadastrar_usuario(Usuario* novo_usuario);
    bool entrar_conta_usuario(std::string login, std::string senha);
    void atualizar_curriculo(std::string login, Curriculo* curriculo);
    void mostrar_vagas_compativeis(std::string login);
    void enviar_curriculo(std::string email);
    void mostrar_todas_vagas(void);
};

void teste_compatibilidade(Curriculo curriculo, std::vector<Vaga*> vagas);

#endif