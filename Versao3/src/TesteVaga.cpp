#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "vaga.hpp"

TEST_CASE("teste Vaga - criar vaga"){
    std::vector<std::string> beneficios{"VALE ALIMENTACAO","VALE TRANSPORTE"};
    std::vector<std::string> requisitos{"NIVEL TECNICO","OFFICE"};
    Vaga vaga1;
    CHECK(vaga1.get_cargo().empty());
    CHECK(vaga1.get_salario() == 0);
    CHECK(vaga1.get_endereco().empty());
    CHECK(vaga1.get_cargaHoraria() == 0);
    CHECK(vaga1.get_beneficios().empty());
    CHECK(vaga1.get_requisitos().empty());
    Vaga vaga2("empacotador",1260.00,"AV. AMAZONAS, 3212", 40, requisitos, beneficios);
    CHECK(vaga2.get_cargo() == "empacotador");
    CHECK(vaga2.get_salario() == 1260);
    CHECK(vaga2.get_endereco() == "AV. AMAZONAS, 3212");
    CHECK(vaga2.get_cargaHoraria() == 40);
    CHECK(vaga2.get_beneficios().at(0) == "VALE ALIMENTACAO");
    CHECK(vaga2.get_requisitos().at(1) == "OFFICE");
}

TEST_CASE("teste Vaga - atualizar vaga"){
    std::vector<std::string> beneficios{"VALE ALIMENTACAO","VALE TRANSPORTE"};
    std::vector<std::string> requisitos{"NIVEL TECNICO","OFFICE"};
    Vaga vaga1;
    vaga1.atualizar_vaga("empacotador",1260.00,"AV. AMAZONAS, 3212", 40, requisitos, beneficios);
    CHECK(vaga1.get_cargo() == "empacotador");
    CHECK(vaga1.get_salario() == 1260);
    CHECK(vaga1.get_endereco() == "AV. AMAZONAS, 3212");
    CHECK(vaga1.get_cargaHoraria() == 40);
    CHECK(vaga1.get_beneficios().at(0) == "VALE ALIMENTACAO");
    CHECK(vaga1.get_requisitos().at(1) == "OFFICE");

    requisitos={"NIVEL TECNICO","OFFICE INTERMEDIARIO", "NIVEL SUPERIOR"};
    beneficios={"SALA DE ALMOÇO","VALE TRANSPORTE","PLANO DE SAUDE"};
    vaga1.atualizar_vaga(new Vaga("vendedor",3000.00,"AV. AMAZONAS, 3212", 40, requisitos, beneficios));
    CHECK(vaga1.get_cargo() == "vendedor");
    CHECK(vaga1.get_salario() == 3000.00);
    CHECK(vaga1.get_endereco() == "AV. AMAZONAS, 3212");
    CHECK(vaga1.get_cargaHoraria() == 40);
    CHECK(vaga1.get_beneficios().at(0) == "SALA DE ALMOÇO");
    CHECK(vaga1.get_requisitos().at(1) == "OFFICE INTERMEDIARIO");

}