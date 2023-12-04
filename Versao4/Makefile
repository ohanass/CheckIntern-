CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -O3 -std=c++11 -I include/ 

#vaga:
vaga:
	@mkdir -p build
	$(CC) $(CFLAGS) -c src/vaga.cpp -o build/vaga.o
testeVaga: vaga
	$(CC) $(CFLAGS) src/TesteVaga.cpp build/vaga.o -o Testes/Vaga	
curriculo:
	$(CC) $(CFLAGS) -c src/curriculo.cpp -o build/curriculo.o
testeCurriculo: curriculo
	$(CC) $(CFLAGS) src/TesteCurriculo.cpp build/curriculo.o -o Testes/Curriculo
usuario:
	$(CC) $(CFLAGS) -c src/usuario.cpp -o build/usuario.o
testeUsuario: usuario
	$(CC) $(CFLAGS) src/TesteUsuario.cpp build/usuario.o -o Testes/Usuario
aluno:
	$(CC) $(CFLAGS) -c src/aluno.cpp -o build/aluno.o
testeAluno: usuario curriculo vaga aluno
	$(CC) $(CFLAGS) src/TesteAluno.cpp build/curriculo.o build/vaga.o build/usuario.o build/aluno.o -o Testes/Aluno
servidor:
	$(CC) $(CFLAGS) -c src/servidor.cpp -o build/servidor.o
testeServidor: usuario curriculo vaga servidor
	$(CC) $(CFLAGS) src/TesteServidor.cpp build/servidor.o build/usuario.o -o Testes/Servidor
empresa:
	$(CC) $(CFLAGS) -c src/empresa.cpp -o build/empresa.o
testeEmpresa: vaga curriculo usuario aluno empresa
	$(CC) $(CFLAGS) src/TesteEmpresa.cpp build/vaga.o build/curriculo.o build/usuario.o build/aluno.o build/empresa.o -o Testes/Empresa
colegiado:
	$(CC) $(CFLAGS) -c src/colegiado.cpp -o build/colegiado.o
testeColegiado: vaga curriculo usuario aluno servidor empresa colegiado
	$(CC) $(CFLAGS) src/TesteColegiado.cpp build/vaga.o build/curriculo.o build/usuario.o build/aluno.o build/servidor.o build/empresa.o build/colegiado.o -o Testes/Colegiado

# Modifique a funcao main
build: test run
test: testeVaga testeCurriculo testeUsuario testeAluno testeServidor testeEmpresa testeColegiado
run: vaga curriculo usuario aluno servidor empresa colegiado
	$(CC) $(CFLAGS) build/vaga.o build/curriculo.o build/usuario.o build/aluno.o build/servidor.o build/empresa.o build/colegiado.o src/main.cpp -o $(TARGET)
clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
