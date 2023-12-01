#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "estagiario.hpp"

TEST_CASE("teste Estagiario - criar estagiario"){
    Estagiario estagiario1("OHANA","123456");
    CHECK(estagiario1.get_nome()=="OHANA");
    CHECK(estagiario1.get_senha()=="123456");
}

TEST_CASE("teste Vaga - atualizar curriculo"){
    Estagiario estagiario1("OHANA","123456");
    std::vector<std::string> beneficios{"VALE ALIMENTACAO","VALE TRANSPORTE"};
    std::vector<std::string> requisitos{"NIVEL TECNICO","OFFICE"};
    estagiario1.atualizar_curriculo(new Vaga(1260.00, requisitos, beneficios));
    CHECK(estagiario1.get_curriculo().get_salario() == 1260);
    CHECK(estagiario1.get_curriculo().get_beneficios().at(0) == beneficios.at(0));
    CHECK(estagiario1.get_curriculo().get_beneficios().at(1) == beneficios.at(1));
    
    CHECK(estagiario1.get_curriculo().get_requisitos().at(0) == requisitos.at(0));
    CHECK(estagiario1.get_curriculo().get_requisitos().at(1) == requisitos.at(1));
    requisitos={"NIVEL TECNICO","OFFICE INTERMEDIARIO", "NIVEL SUPERIOR"};      
    beneficios={"SALA DE ALMOÇO","VALE TRANSPORTE","PLANO DE SAUDE"};
    estagiario1.atualizar_curriculo(new Vaga(3000.00, requisitos, beneficios));
    CHECK(estagiario1.get_curriculo().get_salario()== 3000);
    CHECK(estagiario1.get_curriculo().get_beneficios().at(0) == beneficios.at(0));
    CHECK(estagiario1.get_curriculo().get_beneficios().at(1) == beneficios.at(1));
    CHECK(estagiario1.get_curriculo().get_beneficios().at(2) == beneficios.at(2));
    
    CHECK(estagiario1.get_curriculo().get_requisitos().at(0) == requisitos.at(0));
    CHECK(estagiario1.get_curriculo().get_requisitos().at(1) == requisitos.at(1));
    CHECK(estagiario1.get_curriculo().get_requisitos().at(2) == requisitos.at(2));
}

TEST_CASE("teste Vaga - atualizar senha"){
    Estagiario estagiario1("OHANA","123456");
    CHECK(estagiario1.get_senha() == "123456");
    estagiario1.alterar_senha("654321");
    CHECK(estagiario1.get_senha() == "654321");
}