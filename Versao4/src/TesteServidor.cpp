#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "servidor.hpp"

TEST_CASE("teste servidor - criar servidor"){
    Servidor servidor("OHANA", "38381112191", "av. antonio Carlos", "31981818811", "12308103","ohana@gmail.com", "oh1234", "123456");
    servidor.mostrar_servidor();
    servidor.alterar_senha("10192");
    CHECK(servidor.get_senha()=="10192");
}
