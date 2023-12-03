#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "estagiario.hpp"
#include "empresa.hpp"
#include <string>
#include <map>
#include <utility>

class Sistema{
    private:
    std::map<std::string, Empresa*> _lista_empresas;
    std::map<std::string, Estagiario*> _lista_estagiarios;
    public:
    void cadastrar_empresa(std::string cnpj, Empresa* nova_empresa);
    void adicionar_conta_empresa(std::string cnpj, std::map<std::string,std::pair<std::string, std::string>> contas);
    bool entrar_conta_empresa(std::string cnpj, std::string email, std::string senha);
    void adicionar_vaga(std::string cnpj, Vaga* vagas);
    void remover_vaga(std::string cnpj, unsigned long int cod_vaga); 
    void avaliar_curriculos(std::string cnpj, unsigned long int cod_vaga);

    void cadastrar_estagiario(std::string email, std::string nome, std::string senha);
    bool entrar_conta_estagiario(std::string email, std::string senha);
    void atualizar_curriculo(std::string email, Vaga* curriculo);
    void mostrar_vagas_compativeis(std::string email);
    void enviar_curriculo(std::string email);
    void mostrar_todas_vagas(void);
};

void teste_compatibilidade(Vaga curriculo, std::vector<Vaga*> vagas);

#endif