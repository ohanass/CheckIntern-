#include "colegiado.hpp"

void teste_compatibilidade(Curriculo curriculo, std::vector<Vaga*> vagas){
    int compatibilidade;
    std::map<double, Vaga*> ordenador;
    for(long unsigned int i=0; i<vagas.size(); ++i){
        
        compatibilidade=0;
        for(long unsigned int j=0; j<curriculo.get_beneficios().size(); ++j){

            for(long unsigned int k=0; k<vagas.at(i)->get_beneficios().size(); ++k){
                if(vagas.at(i)->get_beneficios().at(k).find(curriculo.get_beneficios().at(j))!=std::string::npos){
                    compatibilidade++;
                    break;
                }
            }
        }
        for(long unsigned int j=0; j<curriculo.get_aptidoes().size(); ++j){
            for(long unsigned int k=0; k<vagas.at(i)->get_requisitos().size(); ++k){
                if(vagas.at(i)->get_requisitos().at(k).find(curriculo.get_aptidoes().at(j))!=std::string::npos){
                    compatibilidade++;
                    break;
                }
            }  
        }
        ordenador.insert(std::make_pair(100.0-(((double)compatibilidade/(double)(curriculo.get_beneficios().size()+curriculo.get_aptidoes().size()))*100),vagas.at(i)));
    }
    for(std::map<double, Vaga*>::iterator it=ordenador.begin();it!=ordenador.end();++it){
        if((100.0-it->first)>=50.0){
            std::cout<<"---------------------------"<<std::endl;
            it->second->mostrar_vaga();
            std::cout<<"---------------------------"<<std::endl;
            std::cout<<"COMPATIBILIDADE: "<<std::fixed<<std::setprecision(2)<<(100.0-it->first)<<"%"<<std::endl;
        }
    }
    std::cout<<"---------------------------"<<std::endl<<std::endl;
}

void Colegiado::cadastrar_empresa(Empresa* nova_empresa){
    if(_lista_empresas.find(nova_empresa->get_CNPJ())==_lista_empresas.end()){
        _lista_empresas.insert(std::make_pair(nova_empresa->get_CNPJ(), nova_empresa));
    }
    else{
        std::cout<<"EMPRESA JÁ CADASTRADA"<<std::endl;
    }
}

void Colegiado::adicionar_vaga(std::string cnpj, Vaga* vagas){
    _lista_empresas.at(cnpj)->adicionar_vaga(vagas);
}

void Colegiado::cadastrar_usuario(Usuario* novo_usuario){
    if(_lista_usuarios.find(novo_usuario->get_login())==_lista_usuarios.end()){
        _lista_usuarios.insert(std::make_pair(novo_usuario->get_login(), novo_usuario));
    }
    else{
        std::cout<<"USUARIO JÁ CADASTRAO"<<std::endl;
    }
}

bool Colegiado::entrar_conta_usuario(std::string login, std::string senha){
    if(_lista_usuarios.find(login)!=_lista_usuarios.end()){
        if(_lista_usuarios.at(login)->get_senha()==senha){
            std::cout<<"SEJA BEM VINDO "<<_lista_usuarios.at(login)->get_nome()<<std::endl;
            return true;
        }
    }
    std::cout<<"SENHA OU USUARIO INCORRETOS"<<std::endl;
    return false;
}

void Colegiado::atualizar_curriculo(std::string email, Curriculo* curriculo){
    _lista_usuarios.at(email)->atualizar_curriculo(curriculo);
}

void Colegiado::mostrar_vagas_compativeis(std::string login){
    for(std::map<std::string, Empresa*>::iterator it=_lista_empresas.begin();it!=_lista_empresas.end();++it){
        std::cout<<it->second->get_nome()<<std::endl;
        std::cout<<"CNPJ: "<<it->first<<std::endl;
        teste_compatibilidade(_lista_usuarios.at(login)->get_curriculo(), it->second->get_vagas());
    }
}

void Colegiado::mostrar_todas_vagas(void){
    for(std::map<std::string, Empresa*>::iterator it=_lista_empresas.begin();it!=_lista_empresas.end();++it){
        std::cout<<"---------------------------"<<std::endl;
        std::cout<<it->second->get_nome()<<std::endl;
        std::cout<<"CNPJ: "<<it->first<<std::endl;
        it->second->mostrar_vagas();
    }
}