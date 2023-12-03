#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "aluno.hpp"

TEST_CASE("teste Aluno - criar aluno"){
    Aluno aluno("OHANA", "38381112191", 21, "av. antonio Carlos","engenharia de controle e automacao", 2, "3181818811");
    aluno.mostrar_aluno();
    CHECK(aluno.get_nome() == "OHANA");
    CHECK(aluno.get_cpf() == "38381112191");
    CHECK(aluno.get_idade() == 21);
    CHECK(aluno.get_endereco()=="av. antonio Carlos");
    CHECK(aluno.get_curso() == "engenharia de controle e automacao");
    CHECK(aluno.get_periodo() == 2);
    CHECK(aluno.get_numeroTelefone() == "3181818811");
}