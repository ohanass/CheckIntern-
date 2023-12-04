#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "colegiado.hpp"

TEST_CASE("teste Colegiado - criar colegiado"){
    std::vector<std::string> areas_interesse{"ENGENHARIA AMBIENTAL","AUTOMAÇÃO"};
    std::vector<std::string> requisitos{"NIVEL TECNICO","OFFICE"};
    std::vector<std::string> beneficios{"VALE ALIMENTACAO","VALE TRANSPORTE"};
    std::vector<std::string> aptidoes{"NIVEL TECNICO","OFFICE"};
    Empresa empresa("ufmg", "00112112000139", "31971481752", "antonio@gmail.com");
    Colegiado colegiado;
    colegiado.cadastrar_servidor(new Servidor("OHANA", "38381112191", "av. antonio Carlos", "31981818811", "12308103","ohana@gmail.com", "oh1234", "123456"));
    CHECK(colegiado.entrar_servidor("oh1234","123456"));
    CHECK(colegiado.alterar_email_servidor("oh1234","oh@gmail.com"));
    colegiado.cadastrar_servidor(new Servidor("OHANA", "38381112191", "av. antonio Carlos", "31981818811", "12308103","ohana@gmail.com", "oh1234", "123456"));
    colegiado.cadastrar_empresa(new Empresa("ufmg", "00112112000139", "31971481752", "antonio@gmail.com"));
    colegiado.cadastrar_aluno(new Aluno("OHANA", "38381112191", 21, "av. antonio Carlos","engenharia de controle e automacao", 2, "31981818811", "ohana@gmail.com", "oh1234", "123456"));
    colegiado.adicionar_vaga("00112112000139",new Vaga("empacotador",1260.00,"AV. AMAZONAS, 3212", 40, requisitos, beneficios));
    requisitos={"NIVEL SUPERIOR","OFFICE"};
    beneficios={"VALE ALIMENTACAO","VALE TRANSPORTE"};
    colegiado.adicionar_vaga("00112112000139",new Vaga("engenheiro",1300.00,"AV. AMAZONAS, 3212", 40, requisitos, beneficios));
    requisitos={"NIVEL MEDIO","ELETRONICA"};
    beneficios={"PLANO DE SAUDE","VALE TRANSPORTE"};
    colegiado.adicionar_vaga("00112112000139",new Vaga("eletricista",1000.00,"AV. AMAZONAS, 3212", 40, requisitos, beneficios));
    requisitos={"NIVEL SUPERIOR","OFFICE", "BOA COMUNICACAO"};
    beneficios={"VALE ALIMENTACAO","VALE TRANSPORTE"};
    colegiado.adicionar_vaga("00112112000139",new Vaga("empacotador",3000.00,"AV. AMAZONAS, 3212", 40, requisitos, beneficios));
    colegiado.mostrar_todas_vagas();
    colegiado.atualizar_curriculo("oh1234",new Curriculo(1260.00,areas_interesse, aptidoes, beneficios));
    colegiado.enviar_curriculo("oh1234","00112112000139",1);
    colegiado.enviar_curriculo("oh1234","00112112000139",2);
    colegiado.enviar_curriculo("oh1234","00112112000139",3);
    colegiado.mostrar_vagas_compativeis("oh1234");
    colegiado.mostrar_vagas_candidatadas("oh1234");
    colegiado.remover_vaga("00112112000139", 1);
    colegiado.mostrar_vagas_candidatadas("oh1234");
}