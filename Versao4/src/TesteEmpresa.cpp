#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "empresa.hpp"

TEST_CASE("teste Empresa - criar empresa"){
    std::vector<std::string> areas_interesse{"ENGENHARIA AMBIENTAL","AUTOMAÇÃO"};
    std::vector<std::string> requisitos{"NIVEL TECNICO","OFFICE"};
    std::vector<std::string> beneficios{"VALE ALIMENTACAO","VALE TRANSPORTE"};
    std::vector<std::string> aptidoes{"NIVEL TECNICO","OFFICE"};
    Empresa empresa("ufmg", "00112112000139", "31971481752", "antonio@gmail.com");
    empresa.adicionar_vaga(new Vaga("empacotador",1260.00,"AV. AMAZONAS, 3212", 40, requisitos, beneficios));
    empresa.adicionar_vaga(new Vaga("empacotador",1329.00,"AV. AMAZONAS, 3212", 40, requisitos, beneficios));
    empresa.adicionar_vaga(new Vaga("empacotador",1260.00,"AV. AMAZONAS, 3212", 40, requisitos, beneficios));
    CHECK(empresa.verifica_existenciaVaga(3));
    CHECK_FALSE(empresa.verifica_existenciaVaga(0));
    empresa.mostrar_vagas();
    empresa.remover_vaga(3);
    empresa.adicionar_vaga(new Vaga("empacotador",1260.00,"AV. AMAZONAS, 3212", 40, requisitos, beneficios));
    empresa.adicionar_vaga(new Vaga("empacotador",1210.00,"AV. AMAZONAS, 3212", 40, requisitos, beneficios));
    Aluno aluno("OHANA", "38381112191", 21, "av. antonio Carlos","engenharia de controle e automacao", 2, "31981818811", "ohana@gmail.com", "oh1234", "123456");
    aluno.atualizar_curriculo(new Curriculo(1260.00, areas_interesse, aptidoes, beneficios));
    empresa.receber_curriculo(4, &aluno);
    empresa.mostrar_curriculos();
    empresa.mostrar_vagas();
}