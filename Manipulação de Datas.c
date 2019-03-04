/* 
	Author: 
	Data: 07/11/2018
	Objectivo: 
*/
#include <stdio.h>
#include <stdlib.h>

/* Subprograma que recebe uma data como número inteiro no formato ddmmaaaa
e a separa em dia, mês e ano.*/
void separarData(int data, int *dia, int *mes, int *ano)
{
	*ano = data % 10000; //resto da divisao por 10000 para obter os 4 ultimos algarismos
	data = data/10000; //divisao por 10000 para remover os 4 ultimos algarismos
	
	*mes = data % 100; //resto da divisao por 100 para obter os 2 ultimos algarismos
	
	*dia = data / 100;  //divisao por 100 para obter os 2 primeiros  algarismos
	printf("\n[%d/%d/%d]\n", *dia, *mes, *ano);
	printf(" Dia: %d\n", *dia);
	printf(" Mes: %d\n", *mes);
	printf(" Ano: %d\n", *ano);
}	

/* Subprograma que recebe o ano e retorna verdadeiro (1) se ele for bissexto e
falso (0) no caso contrário. */
int anoBissexto(int ano)
{	
	if(ano % 400 == 0) //se o ano for multiplo de 400
		return 1;
	else 
		if(ano % 4 == 0)
			if(ano % 100 != 0) //se o ano for multiplo de 4 e nao de 100
				return 0;
}

/* Subprograma que recebe o dia, o mês e o ano e retorna verdadeiro (1) se a data
é válida e falso (0) no caso contrário */
int dataValida(int dia, int mes, int ano)
{
	if(dia >= 1 )
		if(dia <= 31)
			return 1;
	if(mes >= 1)
		if(mes <= 12)
			return 1;
	if(ano >= 0)
		return 1;
	return 0;
}

/* Subprograma que recebe o dia, o mês e o ano de uma data válida e devolve a
correspondente semana.*/
void diaDaSemana(int dia, int mes, int ano)
{
	int seculo, diaDaSemana;
	int passo1, passo2, passo3, passo4, passo5, passo6;
	//subtrai o mes inserido por 2 para ter o seu precedente , se der negativo ou igual 0, aumenta 12 para obter um mes valido (1-12)
	//por exemplo: se o usuario digitar mes = 2 (fevereiro), ou mes=1 (janeiro),  vai fazer 2 - 2 = 0 mais 12 = 12 (dezembro)
	//logo fevereiro = dezembro; mesma coisa para janeiro, 1 - 2 = -1 ... - 1 + 12 = 11 (novembro), logo 1 janeiro = novembro;
	mes = mes - 2; 
	if(mes <= 0) 
		mes = mes + 12;  
			
	seculo = ano / 100; //recuperar os dois primeiros digitos do ano
	ano = ano % 100; //recuperar os dois ultimos digitos do ano
	 
	passo1 = (mes * 13 - 1) / 5;
	passo2 = ano / 4;
	passo3 = seculo / 4;
	passo4 = seculo * 2;
	passo5 = passo1 + passo2 + passo3 + dia + ano;	
	passo6 = passo5 - passo4;
	
	diaDaSemana = passo6 % 7;
	
	if(diaDaSemana < 0){
		diaDaSemana = diaDaSemana + 7;
		diaDaSemana = diaDaSemana % 7;
	}
		
	switch (diaDaSemana){
		case 0: 
			printf("\t- domingo\n");
			break;
		case 1: 
			printf("\t- segunda-feira\n");
			break;
		case 2: 
			printf("\t- terca-feira\n");
			break;
		case 3: 
			printf("\t- quarta-feira\n");
			break;
		case 4: 
			printf("\t- quinta-feira\n");
			break;
		case 5: 
			printf("\t- sexta-feira\n");
			break;
		case 6: 
			printf("\t- sabado\n");
			break;
	}
}

/* Subprograma que recebe o dia, o mês e o dia de uma data válida e devolva a data 
do dia seguinte. */
void dataDiaSeguinte(int dia, int mes, int ano)
{
	dia = dia + 1;
	if(dia > 31){
		dia = 1;
		mes = mes + 1;
		if(mes > 12){	
			mes = 1;
			ano = ano + 1;
		}
	}		
	printf("Data do dia seguinte: %d/%d/%d\n",dia,mes,ano);
}

/* Subprograma que recebe o dia, o mês e o dia de uma data válida e devolva a data 
do dia anterior. */
void dataDiaAnterior(int dia, int mes, int ano)
{
	dia = dia - 1;
	if(dia < 1){
		dia = 31; 
		mes = mes - 1;
		if(mes < 1){
			dia = 31;
			mes = 12;
			ano = ano - 1;
		}
	}		
	printf("Data do dia Anterior: %d/%d/%d\n",dia,mes,ano);
}

/* Subprograma que recebe o dia, o mês e o ano de duas datas, calcula os
	números de anos entre elas. */
int diferencaDeAnos(int ano, int ano2)
{
	int diferenca = ano - ano2;
	if(diferenca < 0)
		diferenca = diferenca * (-1);
	return diferenca;	
}
	
/* Subprograma que recebe o dia, o mês e o ano de um par de datas e determina
	a data mais antiga e a data mais recente. */
void dataMaisAntiga(int dia, int mes, int ano, int dia2, int mes2, int ano2)
{
	if(ano2 > ano){
		printf("\nData mais recente :> %d/%d/%d", dia2, mes2, ano2);
		printf("\nData mais antiga :> %d/%d/%d\n", dia, mes, ano);
	}
	else 	
		if(ano2 < ano){
			printf("\nData mais recente :> %d/%d/%d", dia, mes, ano);
			printf("\nData mais antiga :> %d/%d/%d\n", dia2, mes2, ano2);
		}
		else
			if(mes2 > mes){
				printf("\nData mais recente :> %d/%d/%d", dia2, mes2, ano2);
				printf("\nData mais antiga :> %d/%d/%d\n", dia, mes, ano);
			}
			else 	
				if(mes2 < mes){
					printf("\nData mais recente :> %d/%d/%d", dia, mes, ano);
					printf("\nData mais antiga :> %d/%d/%d\n", dia2, mes2, ano2);
				}
				else
					if(dia2 > dia){
						printf("\nData mais recente :> %d/%d/%d", dia2, mes2, ano2);
						printf("\nData mais antiga :> %d/%d/%d\n", dia, mes, ano);
					}
					else 	
						if(dia2 < dia){
							printf("\nData mais recente :> %d/%d/%d", dia, mes, ano);
							printf("\nData mais antiga :> %d/%d/%d\n", dia2, mes2, ano2);
						}
						else
							printf("Datas Iguais!\n");		
}

int main()
{
	int dia, mes, ano, data;
	int dia2, mes2, ano2, data2;
	
	printf("\nEntre com duas datas: ");
	scanf("%d %d",&data, &data2);
	
	separarData(data, &dia, &mes, &ano);
	if(anoBissexto(ano) == 1)
		printf("{Ano Bissexto}\n");
	diaDaSemana(dia, mes, ano);
	dataDiaSeguinte(dia, mes, ano);
	dataDiaAnterior(dia, mes, ano);
	
	printf("\n=========================\n");
	
	separarData(data2, &dia2, &mes2, &ano2);
	if(anoBissexto(ano2) == 1)
		printf("{Ano Bissexto}\n");
	diaDaSemana(dia2, mes2, ano2);
	dataDiaSeguinte(dia2, mes2, ano2);
	dataDiaAnterior(dia2, mes2, ano2);
	
	printf("\n=========================\n");
	
	dataMaisAntiga(dia, mes, ano, dia2, mes2, ano2);
	printf("\nDiferenca de anos entre elas: %d anos",diferencaDeAnos(ano, ano2));
	
	
	return 0;
	system("PAUSE");
}
