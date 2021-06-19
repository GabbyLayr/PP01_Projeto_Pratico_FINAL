//Nome completo: Gabrielly Antônio A Borges
//Matrícula: UC21100287 
//Engenharia de software | 1°semestre

//Não consegui concluir o código como deveria. Houve um erro com as chaves e mesmo depois 
//de verificar chavepor chave não encontrei o erro. Acredito que se eu tivesse solucionado esse ]
//esse erro o código rodaria melhor. Sinto muito!

//Projeto prático final: Venda de passagens aéreas

//Entradas: 1. destino de voo, 2. solicitação de vagas no avião, 3. reservas, 
//4. cancelamento de reservas, 5. confirmações de reservas
//Saídas: 1. lugares disponíveis (D.verde), 2. lugares confirmados (C.azul), 
//3. lugares reservadoS (R.vermelho). 
	
#include<stdio.h> //biblioteca para entrada e saída: pintf e scanf
#include<locale.h> //biblioteca para utilização de acentos gráficos: setlocale
#include<string.h> //biblioteca para manipulamento de strings: strlen e strcmp
#include<ctype.h> //biblioteca para converter letras minúsculas e letras maiúsculas: toupper e tolower
#include <stdlib.h> //biblioteca para formatação: system("função")
#include<math.h> //biblioteca que permite efetuar operações matemáticas
#include<conio.h> //biblioteca que permite a coloração dos textos através do enum DOS_COLORS
#include<windows.h>  //biblioteca para funções AIP, nesse código permite, junto com a biblioteca conio.h, a coloração dos textos através
//do void textcolor(int iColor)

enum DOS_COLORS{ //permite printar textos com cores
 preto, azul, verde, CYAN, vermelho, MAGENTA, castanho,
 cizento_claro, cizento_escuro, azul_claro, verde_claro, CYAN_claro,
 vermelho_claro, MAGENTA_claro, amarelo, branco};

void textcolor(int iColor){ //permite utilizar o textcolor para colorir os textos junto com enum DOS_COLORS
 HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
 CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
 BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
 bufferInfo.wAttributes &= 0x00F0;
 SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);}

int main(){
//Declaração de variáveis:	
	int menu, contador[200], assentos[100],passagens; //armazenamento de números inteiros
	int idDestino = 0, voos = 1, linha[100], A = 0, B = 0, confirmacao[20][10], Npassagens, escolhaAssento, idPassageiro, idVoo, totalValor[100], totalValorConfirmado[100];
	int reservados = 0, confirmados = 0, disponiveis = 0, aux, NNpassagens, id;
	float valorP[100], meiaPassagem, assentosReserva[20][10], codigo[20][10];
	char destino[100][50] , novaAcao; //armazenamento de caractéres
	setlocale (LC_ALL, "portuguese"); //permite a utilização de acentuação gráfica nas mensgaens aos usuários
//Entrada: solicitar destino de voo
	printf("Bem-vindo(a) SALUMAR LINHAS AEREAS! \nVamos iniciar a sessão:\n"); //apresentação da compainha aérea

do{//permite que esse bloco seja repetido caso o nome informado seja nulo, inferior ou igual a 5 caracteres
	printf("\n>Nos informe o nome do seu destino: "); //solicitação de dados: nome do destino
	fflush(stdin); //limpeza do buffer do teclado
	fgets(destino[idDestino], 50, stdin); //especifica em qual variável será armazenada a informação
	  if (strlen(destino[idDestino]) <= 5){ //condição para entrada de caracteres sendo <= 5
	  	printf("Invalido! Tente novamente!\n\n");
	  }else{ (strlen(destino[idDestino])>= 6);}
}while (strlen(destino[idDestino]) <= 5);
   //Verificação de valor iguais. Caso possua valores iguais retorna ao valor 0
	aux = 0;
	for(A = 0; A <= voos; A++){
		if(strcmp(destino[idDestino], destino[i])==0){
			if(idDestino != A){
				idDestino = A; 
	              aux = 1;break;}
		}
	}

do{ //permite que esse bloco seja repetido caso o valor de acentos informados seja <= 90 ou >= 201
   	printf(">Informe a quantidade de assentos disponíveis para esse voo: ");
   	fflush(stdin);
   	scanf("%d", &assentos[idDestino]);
   	if(assentos[idDestino] < 90 || assentos[idDestino] > 200){
		printf("Valor inserido inválido! Tente novamente:\n");}
}while(assentos[idDestino] < 90 || assentos[idDestino] > 200);
    linha[idDestino] = (assentos[idDestino] / 10) + 1;
	contador[idDestino] = 0;
	for(A = 0; A < linha[idDestino]; A++){
		for (B = 0; B < 10; B++){
		contador[idDestino]++;
		assentosReserva[A][B]= contador[idDestino];}  
	} 
	for(A = 0; A < linha[idDestino]; A++){
		for(B = 0; B < 10; B++){
		if(assentosReserva[A][B] <= assentos[idDestino]){
			codigo[A][B]='D';}
		}  
	} 
    
do{ //Permite que esse bloco se repita caso o valor a ser pago nas passagens seja negativo ou igual a 0
		printf(">Informe o valor da passagem: R$ ");
		fflush(stdin);
		scanf("%f", &valorP[idDestino]);
		if(valorP[idDestino]<=0){
			printf("Valor inserido invalido! Tente novamente:\n");}
}while(valorP[idDestino] <= 0);
		
//Menu de opções de saída/ações para os usuários

do{
	system("cls");
    printf("Selecione as opção de operação que deseja realizar:\n");
    printf("1.Efetuar uma reserva");
    printf("\n2.Cacelar a reserva ");
    printf("\n3.Confirmar passagem ");
    printf("\n4.Acessar mapa de acentos\n");
    printf("\nOpção: ");
    scanf("%d", &menu);
    
	switch(menu){ //cria o menu, permitindo a realização de ações em cada escolha *MELHORAR COMENTÁRIO		
//1° case: permite o usuário efetuar uma reserva de lugar
    	case 1: system("cls");
    	printf("1.Efetuar uma reserva\n");
do{ //repete o bloco caso o número de passagens de reserva ultrapassem a quantidade de assentos
		printf("Quantas passagens você deseja reservar? ");
		fflush(stdin);
		scanf("%d", &Npassagens);
		if(Npassagens <= 0 || Npassagens > assentos[idDestino]){
		printf("Valor inserido inválido! Tente novamente:\n");}
}while(Npassagens <= 0 || Npassagens > assentos[idDestino]);
    textcolor(verde_claro);
    printf("\nD.acentos Disponíveis");
    textcolor(branco);
    textcolor(vermelho);
    printf("\nR. acentos Reservados");
    textcolor(branco);
    textcolor(azul);
    printf("\nC. acentos Confirmados\n");
    textcolor(branco);
    printf("\nDigite a escolha dos assentos para cada passageiro:\n"); 
	for(A = 0; A < linha[idDestino]; A++){
        for(B = 0; B < 10; B++){
        if(assentosReserva[A][B] <= contador[idDestino]){
			if(codigo[A][B] == 'R'){
				textcolor(vermelho);
			    printf("%d", assentosReserva[A][B]);
			      printf(" %c\t ", codigo[A][B]);
			      textcolor(branco);
			        }else if (codigo[A][B] == 'D'){
			           textcolor(verde_claro);
			           printf("%d", assentosReserva[A][A]);
			             printf(" %c\t", codigo[A][B]);
			             textcolor(branco);
			               }else{(codigo[A][B] == 'C');
			               textcolor(azul);
			                  printf("%d", assentosReserva[A][B]);
			                    printf(" %c\t", codigo[A][B]);}  
		    } 
	    }
    }  
	aux=0;
	printf("\n");
do{
	printf("\n%d° passageiro. Assento: ", aux + 1);
	fflush(stdin);
	scanf("%d", &escolhaAssento);
	for(A = 0; A < linha[idDestino]; A++){  
	  for(B = 0; B < 10; B++){
	  if(assentosReserva[A][B] == escolhaAssento){
	    codigo[A][B] = 'R';
		  confirmacao[A][B] = idPassageiro;
		    aux++;} 
		}       
	}
}while(aux < Npassagens);
    totalValor[idPassageiro] = ((Npassagens - NNpassagens) * valorP[idDestino]) + (NNpassagens * (valorP[idDestino] / 2));
    //Confirma os dados de reserva
		printf("\nConfirmação da reserva:"); 
		printf("\n>Acentos reservados: %d", Npassagens);
		printf(">Possível valor das passagens reservadas: %.2f", totalValor[idPassageiro]);
		printf(">Id do passageiro : %d", idPassageiro);
		printf(">Id do destino: %d", idDestino);
		printf("Você precisa lembrar os IDs do pasageiro e de voo para realizar outras ações!\n");
	//Retornar ao menu, realizar novas ações
        printf("\nDeseja retornar ao menu?\n");
        printf("\nS. para sim / N. para não: ");
        scanf("%c", &novaAcao);
    	fflush(stdin);
    	novaAcao = toupper(novaAcao);
    	if(novaAcao == 'N'){ //Permite o usuário finalizar a sessão por completo 
		  printf("Sessão finalizada!\n");
		        }//final do if-else
		system ("cls");break;
    	
//2° case: permite o usuário confirmar uma passagem
		case 2: system("cls"); 
    	printf(" SALUMAR LINHAS AEREAS! %s\n", &destino);
    	printf("2.Confirmar passagem");
    	printf("\nPara confirmar sua reserva nos informe os dados:\n");
    	printf("\n>Id do passageiro: ");
    	scanf("%d", idPassageiro);
    	printf(">Id do destino: ");
    	scanf("%d", idDestino);
    	for(A = 0; A < linha[idVoo]; A++){ 
		    for(B = 0; B < 10; B++){
		      if(confirmacao[A][B] == id && codigo[A][B] == 'R'){
		        codigo[A][B]= 'C';}
		}       
	}
	
		for(A = 0; A < linha[idVoo]; A++){
        	for(B = 0; B < 10; B++){
            if(assentosReserva[A][B] <= contador[idVoo]){
			    if (codigo[A][B ]== 'R'){
			    	textcolor(vermelho);
			      printf("%d", assentosReserva[A][B]);
			        printf(" %c\t", codigo[A][B]);
			        textcolor(branco);
			          }else if (codigo[A][B]=='D'){
			          	textcolor(verde_claro);
			            printf("%d", assentosReserva[A][B]);
			              printf(" %c\t", codigo[A][B]);
			              textcolor(branco);
			                }else{(codigo[A][B] == 'C');
			                   textcolor(azul);
			                   printf("%d", assentosReserva[A][B]);
			                     printf(" %c\t", codigo[A][B]);}
								 textcolor(branco);  
			    } 
		    }      
        }
        totalValorConfirmado[idVoo] = totalValorConfirmado[idVoo] + totalValor[id];		
    	printf("\nPassagens confirmadas!:\n"); 
		printf(">Valor das passagens confirmadas: %.2f\n", totalValorConfirmado[idVoo]);
    //Voltar ao menu para fazer uma nova operação
		printf("\nDeseja retornar ao menu? Assim você pode realizar uma nova ação\n");
        printf("\nS. para sim / N. para não: ");
        scanf("%s", &novaAcao);
    	fflush(stdin);
    	novaAcao = toupper(novaAcao);
    	if(novaAcao == 'N'){ //Permite o usuário finalizar a sessão por completo 
		  printf("Sessão finalizada!\n");
		        }//final do if-else
		system("cls");
		break;
	
//3° opção: permite que o usuário cancele uma reserva
		case 3: system("cls");
		printf(" SALUMAR LINHAS AEREAS! %s\n", &destino);
    	printf("3.Cancelar as reservas");
    	printf("\nPara cancelamento das reservas nos informe os dados:\n");
    	printf("\n>Id do passageiro: ");
    	fflush(stdin);
    	scanf("%d", &id);
    	printf(">Id do destino: ");
    	fflush(stdin);
    	scanf("%d", &idVoo);
        for(A = 0; A < linha[idVoo]; A++){ 
            for(B = 0; B < 10; B++){
                if(confirmacao[A][B] == id && codigo[A][B] == 'R'){
                  codigo[A][B] = 'D';} 
            }  
	    }
	    for(A = 0; A < linha[idVoo]; A++){
        	for(B = 0; B < 10; B++){
            if(assentosReserva[A][B] <= contador[idVoo]){
			    if (codigo[A][B] == 'R'){
			      textcolor(vermelho);
			      printf("%d", assentosReserva[A][B]);
			        printf(" %c\t", codigo[A][B]);
			        textcolor(branco);
			          }else if (codigo[A][B] == 'D'){
			          	 textcolor(verde_claro);
			             printf("%d", assentosReserva[A][B]);
			               printf(" %c\t", codigo[A][B]);
			               textcolor(branco);
			                 }else{(codigo[A][B] == 'C');
			                 	textcolor(azul);
			                    printf("%d", assentosReserva[A][B]);
			                      printf(" %c\t", codigo[A][B]);}
								  textcolor(branco);  
			    } 
			}     
        }
		printf("Confirmado o cancelamento das reservas!\n");	
	//Voltar ao menu para fazer uma nova operação
		printf("\nDeseja retornar ao menu? Assim você pode realizar uma nova ação\n");
        printf("\nS. para sim / N. para não: ");
        scanf("%s", &novaAcao);
    	fflush(stdin);
    	novaAcao = toupper(novaAcao);
    	if(novaAcao == 'N'){ //Permite o usuário finalizar a sessão por completo 
		  printf("Sessão finalizada!\n");
		        }//final do if-else
		system("cls");
		break;		
//4° opção: permite o usuário visualizar o mapa de acentos com os dados das passagens  
    	case 4: system("cls"); 
    	printf(" SALUMAR LINHAS AEREAS!");
    	printf("4.Acessar mapa de acentos");
    	printf(">Id do seu voo: ");
		fflush(stdin);
		scanf("%d", &idVoo);
		textcolor(verde_claro);
		printf("\nD.acentos Disponíveis");
		textcolor(vermelho); 
    	printf("\nR. acentos Reservados");
    	textcolor(azul);
    	printf("\nC. acentos Confirmados\n");
		for(A = 0; A < linha[idVoo]; A++){
        	for(B = 0; B < 10; B++){
        	  if(assentosReserva[A][B] <= contador[idVoo]){
			  if(codigo[A][B] =='R'){
			  	textcolor(vermelho);
			    printf("%d", assentosReserva[A][B]);
			      printf(" %c\t", codigo[A][B]);
			      textcolor(branco);
			        }else if (codigo[A][B] == 'D'){
			        	textcolor(verde_claro);
			           printf("%d", assentosReserva[A][B]);
			             printf(" %c\t", codigo[A][B]);
			             textcolor(branco);
			               }else if (codigo[A][B] == 'C'){
			               	textcolor(azul);
			                  printf("%d", assentosReserva[A][B]);
			                    printf(" %c\t", codigo[A][B]);}
	textcolor(branco);  
			    } 
			}       
        }
    //Realização de contagem dos assentos para informar o usuário
    	for(A = 0; A < linha[idVoo]; A++){
        	for(B = 0; B < 10; B++){
            if(assentosReserva[A][B] <= contador[idVoo]){
			    if (codigo[A][B] == 'R'){
			      textcolor(vermelho);
			      printf("%d", assentosReserva[A][B]);
			        printf(" %c\t", codigo[A][B]);
			          reservados++;
			          textcolor(branco);
			            }else if(codigo[A][B] == 'D'){
			            	textcolor(verde_claro);
			               printf("%d", assentosReserva[A][B]);
			                 printf(" %c\t", codigo[A][B]);
			                   disponiveis++;
			                   textcolor(branco);
			                }else if (codigo[A][B] == 'C'){
			                	textcolor(azul);
			                   printf("%d", assentosReserva[A][B]);
			                     printf(" %c\t", codigo[A][B]);
			                       confirmados++;}  
			     } 
			}
		}
		textcolor(branco);
	printf("Esses são os dados do voo com destino para %d:\n", destino[idVoo]);	
    printf("\n>Assentos Reservados: %d\n", reservados);
	printf(">Assentos Confirmados: %d\n", confirmados);
	printf(">Assentos Disponíveis: %d\n\n", disponiveis);
	printf("Valor a ser pago pelas passagens: %.2f\n", totalValorConfirmado[idVoo]);
	//Voltar ao menu para fazer uma nova operação
		printf("\nDeseja retornar ao menu? Assim você pode realizar uma nova ação\n");
        printf("\nS. para sim\nN. para não");
        scanf("%s", &novaAcao);
    	fflush(stdin);
    	novaAcao = toupper(novaAcao);
    	if(novaAcao == 'N'){ //Permite o usuário finalizar a sessão por completo 
		  printf("Sessão finalizada!\n");
		        }//final do if-else
		system("cls");
		break;
		
		default: printf("Inválido!"); break;
	} //finaliza o menu (switch)
    system("pause");

}while(novaAcao == 'S'); //permite o usuário retornar ao menu de qualquer switch case 
return 0; 
}


