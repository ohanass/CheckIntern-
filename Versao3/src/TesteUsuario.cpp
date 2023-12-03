#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "usuario.hpp"

TEST_CASE("teste Usuario - criar usuario"){
    std::vector<std::string> areas_interesse{"ENGENHARIA AMBIENTAL","AUTOMAÇÃO"};
    std::vector<std::string> requisitos{"NIVEL TECNICO","OFFICE"};
    std::vector<std::string> beneficios{"VALE ALIMENTACAO","VALE TRANSPORTE"};
    std::vector<std::string> aptidoes{"NIVEL TECNICO","OFFICE"};
    Usuario usuario("OHANA", "38381112191", 21, "av. antonio Carlos","engenharia de controle e automacao", 2, "31981818811", "ohana@gmail.com", "oh1234", "123456");
    usuario.atualizar_curriculo(new Curriculo(1260.00, areas_interesse, aptidoes, beneficios));
    usuario.mostrar_curriculo();
    usuario.enviar_curriculo(new Vaga("empacotador",1260.00,"AV. AMAZONAS, 3212", 40, requisitos, beneficios));
    usuario.alterar_senha("10192");
    CHECK(usuario.get_senha()=="10192");
    usuario.mostrar_vagasCadidatadas();
    usuario.mostrar_vagaDetalhada(1);

}
