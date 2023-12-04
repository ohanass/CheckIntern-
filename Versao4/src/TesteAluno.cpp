#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "aluno.hpp"

TEST_CASE("teste Aluno - criar aluno"){
    std::vector<std::string> areas_interesse{"ENGENHARIA AMBIENTAL","AUTOMAÇÃO"};
    std::vector<std::string> requisitos{"NIVEL TECNICO","OFFICE"};
    std::vector<std::string> beneficios{"VALE ALIMENTACAO","VALE TRANSPORTE"};
    std::vector<std::string> aptidoes{"NIVEL TECNICO","OFFICE"};
    Aluno aluno("OHANA", "38381112191", 21, "av. antonio Carlos","engenharia de controle e automacao", 2, "31981818811", "ohana@gmail.com", "oh1234", "123456");
    aluno.atualizar_curriculo(new Curriculo(1260.00, areas_interesse, aptidoes, beneficios));
    aluno.mostrar_curriculo();
    aluno.enviar_curriculo(new Vaga("empacotador",1260.00,"AV. AMAZONAS, 3212", 40, requisitos, beneficios));
    aluno.alterar_senha("10192");
    CHECK(aluno.get_senha() == "10192");
    aluno.mostrar_vagasCandidatadas();
    aluno.mostrar_vagaDetalhada(1);
}