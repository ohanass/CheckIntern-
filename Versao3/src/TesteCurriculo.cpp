#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "curriculo.hpp"

TEST_CASE("teste Curriculo - criar curriculo"){
    std::vector<std::string> areas_interesse{"ENGENHARIA AMBIENTAL","AUTOMAÇÃO"};
    std::vector<std::string> beneficios{"VALE ALIMENTACAO","VALE TRANSPORTE"};
    std::vector<std::string> aptidoes{"NIVEL TECNICO","OFFICE"};
    Curriculo curriculo1;
    CHECK(curriculo1.get_salario()==0);
    CHECK(curriculo1.get_areasInteresse().empty());
    CHECK(curriculo1.get_aptidoes().empty());
    CHECK(curriculo1.get_beneficios().empty());
    Curriculo curriculo2(1260.00,areas_interesse, aptidoes, beneficios);
    CHECK(curriculo2.get_salario()==1260);
    CHECK(curriculo2.get_areasInteresse().at(0)=="ENGENHARIA AMBIENTAL");
    CHECK(curriculo2.get_beneficios().at(0)=="VALE ALIMENTACAO");
    CHECK(curriculo2.get_aptidoes().at(1)=="OFFICE");
}

TEST_CASE("teste Curriculo - atualizar curriculo"){
    std::vector<std::string> areas_interesse{"ENGENHARIA AMBIENTAL","AUTOMAÇÃO"};
    std::vector<std::string> beneficios{"VALE ALIMENTACAO","VALE TRANSPORTE"};
    std::vector<std::string> aptidoes{"NIVEL TECNICO","OFFICE"};
    Curriculo curriculo1;
    curriculo1.atualizar_curriculo(1260.00, areas_interesse, aptidoes, beneficios);
    CHECK(curriculo1.get_salario()==1260);
    CHECK(curriculo1.get_areasInteresse().at(1)=="AUTOMAÇÃO");
    CHECK(curriculo1.get_aptidoes().at(0)=="NIVEL TECNICO");
    CHECK(curriculo1.get_beneficios().at(0)=="VALE ALIMENTACAO");
    aptidoes={"NIVEL TECNICO","OFFICE INTERMEDIARIO", "NIVEL SUPERIOR"};
    beneficios={"SALA DE ALMOÇO","VALE TRANSPORTE","PLANO DE SAUDE"};
    curriculo1.atualizar_curriculo(new Curriculo(3000.00, areas_interesse, aptidoes, beneficios));
    CHECK(curriculo1.get_salario()==3000);
    CHECK(curriculo1.get_areasInteresse().at(0)=="ENGENHARIA AMBIENTAL");
    CHECK(curriculo1.get_beneficios().at(0)=="SALA DE ALMOÇO");
    CHECK(curriculo1.get_aptidoes().at(1)=="OFFICE INTERMEDIARIO");
}
