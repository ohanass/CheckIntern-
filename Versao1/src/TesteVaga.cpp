#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "vaga.hpp"

TEST_CASE("teste Vaga - criar vaga"){
    std::vector<std::string> beneficios{"VALE ALIMENTACAO","VALE TRANSPORTE"};
    std::vector<std::string> requisitos{"NIVEL TECNICO","OFFICE"};
    Vaga vaga1;
    CHECK(vaga1.get_salario() == 0);
    CHECK(vaga1.get_beneficios().empty());
    CHECK(vaga1.get_requisitos().empty());
    Vaga vaga2(1260.00,requisitos, beneficios);
    CHECK(vaga2.get_salario() == 1260.00);
    CHECK(vaga2.get_beneficios().at(0) == beneficios.at(0));
    CHECK(vaga2.get_beneficios().at(1) == beneficios.at(1));
    
    CHECK(vaga2.get_requisitos().at(0) == requisitos.at(0));
    CHECK(vaga2.get_requisitos().at(1) == requisitos.at(1));
}

TEST_CASE("teste Vaga - atualizar vaga"){
    std::vector<std::string> beneficios{"VALE ALIMENTACAO","VALE TRANSPORTE"};
    std::vector<std::string> requisitos{"NIVEL TECNICO","OFFICE"};
    Vaga vaga1;
    vaga1.atualizar_vaga(1260.00,requisitos, beneficios);
    CHECK(vaga1.get_salario() == 1260.00);
    CHECK(vaga1.get_beneficios().at(0) == beneficios.at(0));
    CHECK(vaga1.get_beneficios().at(1) == beneficios.at(1));

    CHECK(vaga1.get_requisitos().at(0) == requisitos.at(0));
    CHECK(vaga1.get_requisitos().at(1) == requisitos.at(1));

    requisitos = {"NIVEL TECNICO","OFFICE INTERMEDIARIO", "NIVEL SUPERIOR"};
    beneficios = {"SALA DE ALMOÇO","VALE TRANSPORTE","PLANO DE SAUDE"};
    Vaga vaga2(3000.00, requisitos, beneficios);
    vaga1.atualizar_vaga(&vaga2);
    CHECK(vaga1.get_salario() == 3000.00);
    CHECK(vaga1.get_beneficios().at(0) == beneficios.at(0));
    CHECK(vaga1.get_beneficios().at(1) == beneficios.at(1));
    CHECK(vaga1.get_beneficios().at(2) == beneficios.at(2));

    CHECK(vaga1.get_requisitos().at(0) == requisitos.at(0));
    CHECK(vaga1.get_requisitos().at(1) == requisitos.at(1));
    CHECK(vaga1.get_beneficios().at(2) == beneficios.at(2));

}