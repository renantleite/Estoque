#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Registro {
    char Nome[101];
    long long int Cpf;
    char Local[51];
    int Dia, Mes, Ano, Hora, Minuto;
    int DiaS, MesS, AnoS, HoraS, MinutoS;
};

int main() {
    struct Registro *A;
    int Controle = 27, n = 1, r;

    A = malloc(n*sizeof(struct Registro));//alocando um espaço de memoria apenas para permitir uma realloc depois.


    printf("Bem Vindo!\n");
    while(Controle != 0){
    printf("~~~~~O que deseja fazer?~~~~~\n\n1 - Criar Registro.\n");
    printf("2 - Adicionar horario de saida.\n3 - Buscar registro.\n4 - Listar registros.\n");
    printf("0 - Sair");
    printf("\nSelecione a opcao dejesada digitando o seu numero.\n");
    scanf("%d", &Controle); getchar();
    if(Controle == 1){
        n++;//A começa do A[1]
        A = realloc(A,n*sizeof(struct Registro));
        printf("Nome:\n");
        fgets(A[n-1].Nome,100,stdin);//n-1 é porque o n agora é 2, então o primeiro registro é o A[1] e não o A[0].
        printf("Cpf sem pontuacao:\n");
        scanf("%lld", &A[n-1].Cpf); getchar();//getchar() para o /n do teclado não interferir no fgets
        printf("Local:\n");
        fgets(A[n-1].Local,50,stdin);
        printf("Dia mes e ano de entrada:\n");
        scanf("%d %d %d",&A[n-1].Dia, &A[n-1].Mes, &A[n-1].Ano); getchar();
        printf("Hora e minuto de entrada:\n");
        scanf("%d %d",&A[n-1].Hora, &A[n-1].Minuto); getchar();

    } else if(Controle == 2){
        printf("Selecione o registro usando o seu numero:\n");
        scanf("%d", &r); getchar();
    if(r <= 0 || r>=n){
        printf("opcao invalida.\n");
    } else {
        printf("Dia mes e ano de saida:\n");
        scanf("%d %d %d",&A[r].DiaS, &A[r].MesS, &A[r].AnoS); getchar();
        printf("Hora e minuto de saida:\n");
        scanf("%d %d",&A[r].HoraS, &A[r].MinutoS); getchar();
        printf("Dados atualizados!\n\n");
    }
    } else if(Controle == 3){
        struct Registro B;//crindo um struct para armazenar os dados que o usuario digitar e comparar com os salvos
        int Q, verdadeiro;
        verdadeiro = 0;
        printf("Escolha pelo que voce ira buscar:\n\n1 - Nome\n2 - Local\n3 - Data\n4 - Cpf\n");
        scanf("%d", &Q); getchar();
        if(Q == 1){
            printf("Digite o nome que foi cadastrado:\n");
            fgets(B.Nome,100,stdin);
            for(int i = 1; i < n; i++) {
                if(!(strcmp(B.Nome, A[i].Nome))){//comparação
                        verdadeiro = 1;
                    printf("-----------------------------------\nNome: %sCpf: %lld\nLocal: %sData de entrada: %d/%d/%d %d:%d\n",A[i].Nome,A[i].Cpf,A[i].Local,A[i].Dia,A[i].Mes,A[i].Ano,A[i].Hora,A[i].Minuto);
            if(A[i].DiaS < 50)
            printf("Data de saida: %d/%d/%d %d:%d\n",A[i].DiaS, A[i].MesS, A[i].AnoS, A[i].HoraS, A[i].MinutoS);
            printf("NUMERO: %d\n", i);
                }
            }
                if(verdadeiro == 0){
                    printf("Registro nao encontrado\n");
                }

        } else if(Q == 2) {
            printf("Digite o local que foi cadastrado:\n");
            fgets(B.Local,50,stdin);
            for(int i = 1; i < n; i++) {
                if(!(strcmp(B.Local, A[i].Local))){
                        verdadeiro = 1;
                    printf("-----------------------------------\nNome: %sCpf: %lld\nLocal: %sData de entrada: %d/%d/%d %d:%d\n",A[i].Nome,A[i].Cpf,A[i].Local,A[i].Dia,A[i].Mes,A[i].Ano,A[i].Hora,A[i].Minuto);
            if(A[i].DiaS < 50)
            printf("Data de saida: %d/%d/%d %d:%d\n",A[i].DiaS, A[i].MesS, A[i].AnoS, A[i].HoraS, A[i].MinutoS);
            printf("NUMERO: %d\n", i);
                }
            }
                if(verdadeiro == 0){
                    printf("Registro nao encontrado\n");
                }

        } else if(Q == 3) {
            printf("Digite a data de entrada cadastrada, sem barra e com espaco:\n");
            scanf("%d %d %d", &B.Dia, &B.Mes, &B.Ano); getchar();
            for(int i = 1; i < n; i++) {
                if(B.Dia == A[i].Dia && B.Mes == A[i].Mes && B.Ano == A[i].Ano){
                        verdadeiro = 1;
                    printf("-----------------------------------\nNome: %sCpf: %lld\nLocal: %sData de entrada: %d/%d/%d %d:%d\n",A[i].Nome,A[i].Cpf,A[i].Local,A[i].Dia,A[i].Mes,A[i].Ano,A[i].Hora,A[i].Minuto);
            if(A[i].DiaS < 50)
            printf("Data de saida: %d/%d/%d %d:%d\n",A[i].DiaS, A[i].MesS, A[i].AnoS, A[i].HoraS, A[i].MinutoS);
            printf("NUMERO: %d\n", i);
                }
            }
                if(verdadeiro == 0){
                    printf("Registro nao encontrado\n");
                }

        } else if(Q == 4) {
            printf("Digite o cpf cadastrado:\n");
            scanf("%lld", &B.Cpf); getchar();
            for(int i = 1; i < n; i++) {
                if(B.Cpf == A[i].Cpf){
                        verdadeiro = 1;
                    printf("-----------------------------------\nNome: %sCpf: %lld\nLocal: %sData de entrada: %d/%d/%d %d:%d\n",A[i].Nome,A[i].Cpf,A[i].Local,A[i].Dia,A[i].Mes,A[i].Ano,A[i].Hora,A[i].Minuto);
            if(A[i].DiaS < 50)
            printf("Data de saida: %d/%d/%d %d:%d\n",A[i].DiaS, A[i].MesS, A[i].AnoS, A[i].HoraS, A[i].MinutoS);
            printf("NUMERO: %d\n", i);
                }
            }
                if(verdadeiro == 0){
                    printf("Registro nao encontrado\n");
                }
        } else {
            printf("opcao invalida\n");
        }
    } else if(Controle == 4) {
        struct Registro *C, AUX;//criando dois structs. um para copiar todos os salvos, e outro para auxiliar.
        int T, g, l, k;
        int *NUM;//quando ordenados, as posicões mudariam, logo dificultando o acesso do usuario caso quisesse inserir data de saida.
        NUM = malloc(n*sizeof(int));
        T = n;
        C = malloc(T*sizeof(struct Registro));//obs: nao usar o C[0] pois o A começa do A[1]
        for(int i = 1; i< n; i++){
            C[i]=A[i];//agora podemos ordenar as copias sem desodernar a ordem das originais, apenas para mostrar ao usuário.
            NUM[i]=i;
        }
        printf("Escolha pelo que voce ira listar:\n\n1 - Nome\n2 - Local\n3 - Data de entrada\n4 - Cpf\n");
        scanf("%d", &g); getchar();
        if(g == 1) {
            for(int i = 1; i < n; i++){
                for(int j = i+1;j < n; j++){
                        l = strcmp(C[i].Nome,C[j].Nome);
                if(l > 0){
                    AUX = C[i];
                    C[i] = C[j];
                    C[j] = AUX;
                    k = NUM[i];
                    NUM[i] = NUM[j];//quando for efetuado uma mudança os números acompanharão a mudança.
                    NUM[j] = k;
                }

                }
            }
            for(int i = 1; i < n; i++){
            printf("-----------------------------------\nNome: %sCpf: %lld\nLocal: %sData de entrada: %d/%d/%d %d:%d\n",C[i].Nome,C[i].Cpf,C[i].Local,C[i].Dia,C[i].Mes,C[i].Ano,C[i].Hora,C[i].Minuto);
            if(C[i].DiaS < 50)
            printf("Data de saida: %d/%d/%d %d:%d\n",C[i].DiaS, C[i].MesS, C[i].AnoS, C[i].HoraS, C[i].MinutoS);
            printf("NUMERO: %d\n", NUM[i]);
            }
        } else if(g == 2) {
            for(int i = 1; i < n; i++){
                for(int j = i+1;j < n; j++){
                        l = strcmp(C[i].Local,C[j].Local);
                if(l > 0){
                    AUX = C[i];
                    C[i] = C[j];
                    C[j] = AUX;
                    k = NUM[i];
                    NUM[i] = NUM[j];
                    NUM[j] = k;
                }

                }
            }
            for(int i = 1; i < n; i++){
            printf("-----------------------------------\nNome: %sCpf: %lld\nLocal: %sData de entrada: %d/%d/%d %d:%d\n",C[i].Nome,C[i].Cpf,C[i].Local,C[i].Dia,C[i].Mes,C[i].Ano,C[i].Hora,C[i].Minuto);
            if(C[i].DiaS < 50)
            printf("Data de saida: %d/%d/%d %d:%d\n",C[i].DiaS, C[i].MesS, C[i].AnoS, C[i].HoraS, C[i].MinutoS);
            printf("NUMERO: %d\n", NUM[i]);
            }
        } else if(g == 3) {
            for(int i = 1; i < n; i++){
                for(int j = i+1; j < n; j++){
                    if(C[i].Ano > C[j].Ano){
                        AUX = C[i];
                        C[i] = C[j];
                        C[j] = AUX;
                        k = NUM[i];
                        NUM[i] = NUM[j];
                        NUM[j] = k;
                    }
                }
            }
            for(int i = 1; i < n; i++){
                for(int j = i+1; j < n; j++){
                    if(C[i].Mes > C[j].Mes && C[i].Ano == C[j].Ano){
                        AUX = C[i];
                        C[i] = C[j];
                        C[j] = AUX;
                        k = NUM[i];
                        NUM[i] = NUM[j];
                        NUM[j] = k;
                    }
                }
            }
            for(int i = 1; i < n; i++){
                for(int j = i+1; j < n; j++){
                    if(C[i].Dia > C[j].Dia && C[i].Mes == C[j].Mes && C[i].Ano == C[j].Ano){
                        AUX = C[i];
                        C[i] = C[j];
                        C[j] = AUX;
                        k = NUM[i];
                        NUM[i] = NUM[j];
                        NUM[j] = k;
                    }
                }
            }
            for(int i = 1; i < n; i++){
            printf("-----------------------------------\nNome: %sCpf: %lld\nLocal: %sData de entrada: %d/%d/%d %d:%d\n",C[i].Nome,C[i].Cpf,C[i].Local,C[i].Dia,C[i].Mes,C[i].Ano,C[i].Hora,C[i].Minuto);
            if(C[i].DiaS < 50)
            printf("Data de saida: %d/%d/%d %d:%d\n",C[i].DiaS, C[i].MesS, C[i].AnoS, C[i].HoraS, C[i].MinutoS);
            printf("NUMERO: %d\n", NUM[i]);
            }
        } else if(g == 4) {
            for(int i = 1; i < n; i++){
                for(int j = i+1; j < n; j++){
                    if(C[i].Cpf > C[j].Cpf){
                        AUX = C[i];
                        C[i] = C[j];
                        C[j] = AUX;
                        k = NUM[i];
                        NUM[i] = NUM[j];
                        NUM[j] = k;
                    }
                }
            }
            for(int i = 1; i < n; i++){
            printf("-----------------------------------\nNome: %sCpf: %lld\nLocal: %sData de entrada: %d/%d/%d %d:%d\n",C[i].Nome,C[i].Cpf,C[i].Local,C[i].Dia,C[i].Mes,C[i].Ano,C[i].Hora,C[i].Minuto);
            if(C[i].DiaS < 50)
            printf("Data de saida: %d/%d/%d %d:%d\n",C[i].DiaS, C[i].MesS, C[i].AnoS, C[i].HoraS, C[i].MinutoS);
            printf("NUMERO: %d\n", NUM[i]);
            }
        } else {
            printf("opcao invalida\n");
        }

        free(C);
        free(NUM);
    } else if(Controle == 0){
        printf("Ok, fechando o programa\n");
    } else {
        printf("opcao invalida\n");
    }
    }

    free(A);
    return 0;
}