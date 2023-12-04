#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <map>
#include "colegiado.hpp"

int main(){
    Colegiado colegiado;
    std::string email,login, senha;
    std::string novo_email, novo_login, nova_senha;
    std::string nome, cnpj, numeroTelefone,curso, cargo, endereco,cpf, cadastroInstituicao;
    unsigned short int cargaHoraria, cod_vaga,idade, periodo;
    float salario;                            
    std::vector<std::string> beneficios, requisitos, areas_interesse, aptidoes;
    char escolha;
    while(1){
        std::cout << "Escolha a opção desejada: " << std::endl;
        std::cout << "s - Login de servidor" << std::endl;
        std::cout << "a - Login de aluno" << std::endl;
        std::cout << "c - Cadastrar servidor" << std::endl;
        std::cout << "d - Cadastrar aluno" << std::endl;
        std::cin >> escolha;
        std::cin.ignore();
        if (escolha == 's') {
            std::cout<<"login: ";
            std::cin>>login;
            std::cin.ignore();
            std::cout<<"senha: ";
            std::cin>>senha;
            std::cin.ignore();
            if(colegiado.entrar_servidor(login,senha)){
                do {
                    std::cout << "Pressione Enter para continuar...";
                    std::cin.get();
                    std::cout << "\033[2J\033[H";
                    std::cout << "Escolha a opção desejada:" << std::endl;
                    std::cout << "e - Alterar e-mail do servidor" << std::endl;
                    std::cout << "l - Alterar login do servidor" << std::endl;
                    std::cout << "s - Alterar senha do servidor" << std::endl;
                    std::cout << "c - Cadastrar empresa" << std::endl;
                    std::cout << "a - Adicionar vaga" << std::endl;
                    std::cout << "r - Remover vaga" << std::endl;
                    std::cout << "t - Mostrar todas as vagas" << std::endl;
                    std::cout << "m - Mostrar currículos enviados" << std::endl;
                    std::cout << "s - Sair" << std::endl;

                    std::cout << "Escolha: ";
                    std::cin >> escolha;
                    std::cin.ignore();
                    switch (escolha) {
                        case 'e':
                            std::cout<<"novo email: ";
                            std::cin>>email;
                            std::cin.ignore();
                            colegiado.alterar_email_servidor(login, novo_email);
                            break;
                        case 'l':
                            std::cout<<"novo login: ";
                            std::cin>>novo_login;
                            std::cin.ignore();
                            if(colegiado.alterar_login_servidor(login, novo_login)){
                                std::cout<<"realize o login novamente"<<std::endl;
                                escolha='s';
                            }
                            break;
                        case 's':
                            std::cout<<"senha atual: ";
                            std::cin>>senha;
                            std::cin.ignore();
                            std::cout<<"novo senha: ";
                            std::cin>>nova_senha;
                            std::cin.ignore();
                            if(colegiado.alterar_senha_servidor(login,senha, nova_senha )){
                                std::cout<<"realize o login novamente"<<std::endl;
                                escolha='s';
                            }
                            break;
                        case 'c':
                            std::cout<<"Insira os dados para o cadastro"<<std::endl;
                            std::cout<<"nome: ";
                            getline(std::cin, nome);
                            std::cout<<"cnpj: ";
                            validar_CNPJ(cnpj);
                            std::cout<<"numero telefone: ";
                            std::cin>>numeroTelefone;
                            std::cin.ignore();
                            std::cout<<"email: ";
                            std::cin>>email;
                            std::cin.ignore();
                            colegiado.cadastrar_empresa(new Empresa(nome, cnpj, numeroTelefone, email));
                            break;
                        case 'a':
                            std::cout<<"Insira os dados para o cadastro"<<std::endl;
                            validar_CNPJ(cnpj);
                            std::cout<<"cargo: ";
                            std::cin>>cargo;
                            std::cin.ignore();
                            std::cout<<"salario: ";
                            std::cin>>salario;
                            std::cin.ignore();
                            std::cout<<"endereco: ";
                            getline(std::cin, endereco);
                            std::cout<<"carga horaria semanal: ";
                            std::cin>>cargaHoraria;
                            std::cin.ignore();
                            std::cout<<"requisitos(separe por virgula): ";
                            separar_Str(&requisitos);
                            std::cout<<"beneficios(separe por virgula): ";
                            separar_Str(&beneficios);
                            colegiado.adicionar_vaga(cnpj,new Vaga(cargo, salario, endereco, cargaHoraria,requisitos,beneficios));
                            break;
                        case 'r':
                            std::cout<<"Insira os dados para o remocao"<<std::endl;
                            
                            validar_CNPJ(cnpj);
                            std::cout<<"codigo da vaga: ";
                            std::cin>>cod_vaga;
                            std::cin.ignore();
                            colegiado.remover_vaga(cnpj, cod_vaga);
                            break;
                        case 't':
                            colegiado.mostrar_todas_vagas();
                            break;
                        case 'm':
                            std::cout<<"Insira os dados para o impresao"<<std::endl;
                            validar_CNPJ(cnpj);
                            colegiado.mostrar_curriculos_enviados(cnpj);
                            break;
                        default:
                            std::cout << "Opção inválida!" << std::endl;
                            break;
                    }
                } while (escolha != 's');
            }
            else{
                std::cout << "Opção inválida." << std::endl; 
            }
        } else if (escolha == 'a') {
            std::cout<<"login: ";
            std::cin>>login;
            std::cin.ignore();
            std::cout<<"senha: ";
            std::cin>>senha;
            std::cin.ignore();
            if(colegiado.entrar_aluno(login, senha)){
            do {
                std::cout << "Pressione Enter para continuar...";
                std::cin.get();
                std::cout << "\033[2J\033[H";
                std::cout << "Escolha a opção desejada:" << std::endl;
                std::cout << "e - Alterar e-mail do aluno" << std::endl;
                std::cout << "l - Alterar login do aluno" << std::endl;
                std::cout << "s - Alterar senha do aluno" << std::endl;
                std::cout << "c - Atualizar curriculo" << std::endl;
                std::cout << "a - Enviar curriculo" << std::endl;
                std::cout << "r - Mostrar vagas compativeis" << std::endl;
                std::cout << "t - Mostrar vagas candidatadas" << std::endl;
                std::cout << "m - Mostrar vaga candidatada detalhada" << std::endl;
                std::cout << "s - Sair" << std::endl;
                std::cout << "Escolha: ";
                std::cin >> escolha;
                std::cin.ignore();
                switch (escolha) {
                    case 'e':
                        std::cout<<"novo email: ";
                        std::cin>>email;
                        std::cin.ignore();
                        colegiado.alterar_email_aluno(login, novo_email);
                        break;
                    case 'l':
                        std::cout<<"novo login: ";
                        std::cin>>novo_login;
                        std::cin.ignore();
                        if(colegiado.alterar_login_aluno(login, novo_login)){
                            std::cout<<"realize o login novamente"<<std::endl;
                            escolha='s';
                        }
                        break;
                    case 's':
                        std::cout<<"senha atual: ";
                        std::cin>>senha;
                        std::cin.ignore();
                        std::cout<<"novo senha: ";
                        std::cin>>nova_senha;
                        std::cin.ignore();
                        if(colegiado.alterar_senha_aluno(login,senha, nova_senha )){
                            std::cout<<"realize o login novamente"<<std::endl;
                            escolha='s';
                        }
                        break;
                    case 'c':
                        std::cout<<"Insira os dados para o cadastro do curriculo"<<std::endl;
                        validar_CNPJ(cnpj);
                        std::cout<<"salario: ";
                        std::cin>>salario;
                        std::cin.ignore();
                        std::cout<<"areas de interesse(separe por virgula): ";
                        separar_Str(&areas_interesse);
                        std::cout<<"aptidoes(separe por virgula): ";
                        separar_Str(&aptidoes);
                        std::cout<<"beneficios(separe por virgula): ";
                        separar_Str(&beneficios);
                        colegiado.atualizar_curriculo(login, new Curriculo(salario, areas_interesse, aptidoes, beneficios));
                        break;
                    case 'a':
                        std::cout<<"Insira os dados para o cadastro"<<std::endl;
                        validar_CNPJ(cnpj);
                        std::cout<<"codigo vaga: ";
                        std::cin>>cod_vaga;
                        std::cin.ignore();
                        colegiado.enviar_curriculo(login,cnpj,cod_vaga);
                        break;
                    case 'r':
                        colegiado.mostrar_vagas_compativeis(login);
                        break;
                    case 't':
                        colegiado.mostrar_vagas_candidatadas(login);
                        break;
                    case 'm':
                        std::cout<<"Insira os dados para a visualizacao"<<std::endl;
                        std::cout<<"codigo vaga: ";
                        std::cin>>cod_vaga;
                        colegiado.mostrar_vaga_candidatada_detalhada(login, cod_vaga);
                        break;
                    default:
                        std::cout << "Opção inválida!" << std::endl;
                        break;
                    }
                } while (escolha != 's');
            }
            else{
                std::cout << "Opção inválida." << std::endl; 
            }
        } else if (escolha == 'c') {
            std::cout<<"Insira os dados para o cadastro"<<std::endl;
            std::cout<<"nome: ";
            std::cin.ignore();
            getline(std::cin, nome);
            validar_CPF(cpf);
            std::cin.ignore();
            std::cout<<"endereco: ";
            getline(std::cin, endereco);
            std::cout<<"numero telefone: ";
            std::cin>>numeroTelefone;
            std::cin.ignore();
            std::cout<<"cadastro na instituicao: ";
            std::cin>>cadastroInstituicao;
            std::cin.ignore();
            std::cout<<"email: ";
            std::cin>>email;
            std::cin.ignore();
            std::cout<<"login: ";
            std::cin>>login;
            std::cin.ignore();
            std::cout<<"senha: ";
            std::cin>>senha;
            std::cin.ignore();
            colegiado.cadastrar_servidor(new Servidor(nome, cpf,endereco,numeroTelefone, cadastroInstituicao,email, login,senha));
        } else if (escolha == 'd') {
            std::cout<<"Insira os dados para o cadastro"<<std::endl;
            std::cout<<"nome: ";
            getline(std::cin, nome);
            validar_CPF(cpf);
            std::cout<<"idade: ";
            std::cin>>idade;
            std::cin.ignore();
            std::cout<<"endereco: ";
            std::cin.ignore();
            getline(std::cin, endereco);
            std::cout<<"curso: ";
            std::cin.ignore();
            getline(std::cin, curso);
            std::cout<<"periodo: ";
            std::cin>>periodo;
            std::cin.ignore();
            std::cout<<"numero telefone: ";
            std::cin>>numeroTelefone;
            std::cin.ignore();
            std::cout<<"email: ";
            std::cin>>email;
            std::cin.ignore();
            std::cout<<"login: ";
            std::cin>>login;
            std::cin.ignore();
            std::cout<<"senha: ";
            std::cin>>senha;
            std::cin.ignore();
            colegiado.cadastrar_aluno(new Aluno(nome, cpf,idade,endereco,curso,periodo, numeroTelefone,email, login,senha));
        } else {
            std::cout << "Opção inválida." << std::endl;
        }
    }
    return 0;
}
