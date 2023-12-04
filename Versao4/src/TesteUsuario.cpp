#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "usuario.hpp"

TEST_CASE("teste Usuario - criar usuario"){
    Usuario usuario("ohana@gmail.com", "oh1234", "123456");
    usuario.alterar_email("ohana12@gmail.com");
    usuario.alterar_senha("12333");
    usuario.alterar_login("ohana");
    CHECK(usuario.get_email()=="ohana12@gmail.com");
    CHECK(usuario.get_login()=="ohana");
    CHECK(usuario.get_senha()=="12333");

}
