#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
struct sreceitaougasto{
float valor;

};

struct sdata{
int dia;
int mes;
int ano;
};
struct sdescricao{
char descr[100];
};
struct scategoria{
int categ;
};

void cadastrarreceita(){
    FILE *arq = fopen("gerenciador_financeiro.txt","a");
struct sreceitaougasto x;
struct sdata y;
struct sdescricao z;
struct scategoria w;
int i;
printf("\n =========================\n");
printf("|CADASTRAMENTO DE RECEITA |");
printf("\n =========================\n");
printf("\nDigite o valor: R$ ");
scanf("%f",&x.valor);
printf("\n __________________________________________\n");
puts("|                                          |");
printf("|Informe a data (dia:01, mes:02, ano: 2020)|");
printf("\n|__________________________________________|\n");
printf("\nDia: ");
scanf("%d",&y.dia);
printf("\nMes: ");
scanf("%d",&y.mes);
printf("\nAno: ");
scanf("%d",&y.ano);
printf("\nDescricao, digite somente uma palavra(caso nao queira por descricao digite n): ");
scanf("%s",z.descr);
printf("\nCategoria (adote 1 para Moradia, 2 para Estudos, 3 para Transportes, 4 para alimentacao e 5 para Trabalho): ");
scanf("%d",&w.categ);

float *p = &x.valor;
int *p2 = &y.dia;
int *p3 = &y.mes;
int *p4 = &y.ano;

if (*p4 < 0){
    printf("\nNao coloque valores negativos para o ano\n");
    printf("\nColoque outro valor para o ano:");
    scanf("%d",&y.ano);
}
if ((*p3 < 0) || (*p3 > 12)){
    printf("\nNao coloque valores negativos ou maiores que 12 para o mes\n");
    printf("\nColoque outro valor para o mes:");
    scanf("%d",&y.mes);
}
if ((*p2 < 0) || (*p2 > 31)){
    printf("\nNao coloque valores negativos ou maiores que 31 para o dia\n");
    printf("\nColoque outro valor para o dia:");
    scanf("%d",&y.dia);
}
if ((*p4 % 4 == 0 || *p4 % 400 == 0) && (*p4 % 100 >= 1 && *p4 > 0)){
      if(*p3 == 2 && *p2 > 0 && *p2 < 30){
        i++;
      }
      else if ((*p3 == 2 && *p2 > 0 && *p2 > 29) || (*p3 == 2 && *p2 < 0 && *p2 > 29  )){
        printf("\nDia invalido, eh ano bissexto, Fevereiro vai ate dia 29.\n");
        printf("Coloque outro dia:");
        scanf("%d",&y.dia);

      }
}
 if (*p3 > 0 && *p3 < 13){
    if(*p3 == 2 && *p2 > 0 && *p2 < 29){
        i++;
      }
      else if ((*p3 == 2 && *p2 > 0 && *p2 > 28) || (*p3 == 2 && *p2 < 0 && *p2 > 28  )){
        printf("\nDia invalido, Fevereiro so vai ate dia 28, e ate 29 em ano bissexto.\n");
        printf("Coloque outro dia:");
        scanf("%d",&y.dia);
      }
      else if (*p3 == 4 || *p3 == 6 || *p3 == 9 || *p3 == 11){
        if(*p2 > 30){
        printf("\nDia invalido, esse mes so tem 30 dias.\n");
        printf("Coloque outro dia:");
        scanf("%d",&y.dia);
        }
      }
}
FILE *arq3 = fopen("saldo.txt","a");
fprintf(arq3," %.2f", *p);
fclose(arq3);
printf("\n ================================\n");
printf("|RECEITA CADASTRADA COM SUCESSO! |");
printf("\n ================================\n");

FILE *arq2 = fopen("gerenciadorReceita.txt","a");
fprintf(arq,"==============================================================================\n");
fprintf(arq,"|Receita");
fprintf(arq," |Valor: R$ %.2f", *p);
        if(w.categ == 1){
          fprintf(arq," |Categoria: Moradia");
        }
        if(w.categ == 2){
          fprintf(arq," |Categoria: Estudos");
        }
        if(w.categ == 3){
          fprintf(arq," |Categoria: Transportes");
        }
        if(w.categ == 4){
          fprintf(arq," |Categoria: Alimentacao");
        }
        if(w.categ == 5){
          fprintf(arq," |Categoria: Trabalho");
        }
fprintf(arq," |Data: %d ", *p2);
fprintf(arq,"/ %d ", *p3);
fprintf(arq,"/ %d", *p4);
fprintf(arq," |Descricao: %s|\n", z.descr);

fprintf(arq2,"1");
fprintf(arq2," %.2f", *p);
fprintf(arq2," %d", w.categ);
fprintf(arq2," %d", *p2);
fprintf(arq2," %d", *p3);
fprintf(arq2," %d\n", *p4);
fclose(arq);
fclose(arq2);
}
//////////////////////////////////////////////////////////////
void cadastrargasto(){
    FILE *arq = fopen("gerenciador_financeiro.txt","a");
struct sreceitaougasto a;
struct sdata b;
struct sdescricao c;
struct scategoria d;
int i;

printf("\n =======================\n");
printf("|CADASTRAMENTO DE GASTO |");
printf("\n =======================\n");
printf("\nDigite o valor: R$ ");
scanf("%f",&a.valor);
if(a.valor > 0){
  printf("\nValor invalido, digite um valor negativo:\n");
  scanf("%f",&a.valor);
}
printf("\n __________________________________________\n");
puts("|                                          |");
printf("|Informe a data (dia:01, mes:02, ano: 2020)|");
printf("\n|__________________________________________|\n");
printf("\nDia: ");
scanf("%d",&b.dia);
printf("\nMes: ");
scanf("%d",&b.mes);
printf("\nAno: ");
scanf("%d",&b.ano);

printf("\nDescricao, digite somente uma palavra(caso nao queira por descricao digite n): ");
scanf("%s",c.descr);
printf("\nCategoria (adote 1 para Moradia, 2 para Estudos, 3 para Transportes, 4 para alimentacao e 5 para Trabalho): ");
scanf("%d",&d.categ);

float *pp = &a.valor;
int *pp2 = &b.dia;
int *pp3 = &b.mes;
int *pp4 = &b.ano;

if (*pp4 < 0){
    printf("\nNao coloque valores negativos para o ano\n");
    printf("\nColoque outro valor para o ano:");
    scanf("%d",&b.ano);
}
if ((*pp3 < 0) || (*pp3 > 12)){
    printf("\nNao coloque valores negativos ou maiores que 12 para o mes\n");
    printf("\nColoque outro valor para o mes:");
    scanf("%d",&b.mes);
}
if ((*pp2 < 0) || (*pp2 > 31)){
    printf("\nNao coloque valores negativos ou maiores que 31 para o dia\n");
    printf("\nColoque outro valor para o dia:");
    scanf("%d",&b.dia);
}
if ((*pp4 % 4 == 0 || *pp4 % 400 == 0) && (*pp4 % 100 >= 1 && *pp4 > 0)){
      if(*pp3 == 2 && *pp2 > 0 && *pp2 < 30){
        i++;
      }
      else if ((*pp3 == 2 && *pp2 > 0 && *pp2 > 29) || (*pp3 == 2 && *pp2 < 0 && *pp2 > 29  )){
        printf("\nDia invalido, eh ano bissexto, Fevereiro vai ate dia 29.\n");
        printf("Coloque outro dia:");
        scanf("%d",&b.dia);

      }
}
 if (*pp3 > 0 && *pp3 < 13){
    if(*pp3 == 2 && *pp2 > 0 && *pp2 < 29){
        i++;
      }
      else if ((*pp3 == 2 && *pp2 > 0 && *pp2 > 28) || (*pp3 == 2 && *pp2 < 0 && *pp2 > 28  )){
        printf("\nDia invalido, Fevereiro so vai ate dia 28, e ate 29 em ano bissexto.\n");
        printf("Coloque outro dia:");
        scanf("%d",&b.dia);
      }
      else if (*pp3 == 4 || *pp3 == 6 || *pp3 == 9 || *pp3 == 11){
        if(*pp2 > 30){
        printf("\nDia invalido, esse mes so tem 30 dias.\n");
        printf("Coloque outro dia:");
        scanf("%d",&b.dia);
        }
      }
}
printf("\n ==============================\n");
printf("|GASTO CADASTRADO COM SUCESSO! |");
printf("\n ==============================\n");
FILE *arq2 = fopen("gerenciadorGasto.txt","a");
fprintf(arq,"==============================================================================\n");
fprintf(arq,"|Gasto");
fprintf(arq," |Valor: R$ %.2f", *pp);
        if(d.categ == 1){
          fprintf(arq," |Categoria: Moradia");
        }
        if(d.categ == 2){
          fprintf(arq," |Categoria: Estudos");
        }
        if(d.categ == 3){
          fprintf(arq," |Categoria: Transportes");
        }
        if(d.categ == 4){
          fprintf(arq," |Categoria: Alimentacao");
        }
        if(d.categ == 5){
          fprintf(arq," |Categoria: Trabalho");
        }
fprintf(arq," |Data: %d ", *pp2);
fprintf(arq,"/ %d ", *pp3);
fprintf(arq,"/ %d", *pp4);
fprintf(arq," |Descricao: %s|\n", c.descr);

fprintf(arq2,"2");
fprintf(arq2," %.2f", *pp);
fprintf(arq2," %d", d.categ);
fprintf(arq2," %d", *pp2);
fprintf(arq2," %d", *pp3);
fprintf(arq2," %d\n", *pp4);
fclose(arq);
fclose(arq2);
}
//////////////////////////////////////////////
void relatorio12meses(){
  int ano;
  FILE *arq3 = fopen("gerenciadorGasto.txt","a");
  FILE *arq6 = fopen("estilo.css","w");
 FILE *arq4 = fopen("gerenciadorReceita.txt","a");
 FILE *arq5 = fopen("relatorio_12meses.html","w");
 fclose(arq3);
 fclose(arq4);
  FILE *arq2 = fopen("gerenciadorGasto.txt","r");
 FILE *arq = fopen("gerenciadorReceita.txt","r");
 printf("\n ======================\n");
printf("|RELATORIO DOS 12 MESES |");
printf("\n =======================\n");
printf("Insira o ano para poder ver o relatorio: ");
scanf("%d", &ano);
fprintf(arq6,".a{font-family: 'Arial Black';color:black;text-align: center;align-content: center;font-size: 30pt;}.t{font-family: 'Arial Black';color:darkred;text-align: center;font-size: 12pt;}.e{font-family: 'Arial Black';color:darkred;font-size: 15pt;text-align: center;}table{text-align:center;border-color: red;border-style: solid;background-color: black;}.body{background-color: darkblue;}");
int r = 0;
  float x;
  float v[1000];

  int i=0;

int z = 0;
float a;
float v2[1000];
int n = 0;
fclose(arq6);
fprintf(arq5,"<!DOCTYPE html>");
fprintf(arq5,"<html>");
fprintf(arq5,"<head><meta charset='UTF-8'><title>Relatorio Anual</title><link href='estilo.css'rel='stylesheet'></head><body class='body' align='center'> <a class='a' >Relatorio Anual</a><br>");

fprintf(arq5,"<table border='2' align='left' ><tr class='e'><td>Cadastro</td><td>Valor</td><td>Categoria</td><td>Data</td></tr>");
  for (i = 0;(fscanf(arq, "%f", &x)) != EOF;) {
    v[i] = x;
    for(r=0; v[r]!= 0;){
    if(v[i] == ano && r % 5 == 0){
        i = i-5;

        fprintf(arq5,"<tr class='t'>");
        fprintf(arq5,"<td> Receita </td>");
        i = i+1;
        fprintf(arq5,"<td> R$%.2f </td>",v[i]);
        i = i+1;
        if(v[i]== 1){
          fprintf(arq5,"<td> Moradia </td>");
        }
        if(v[i]== 2){
          fprintf(arq5,"<td> Estudos </td>");
        }
        if(v[i]== 3){
          fprintf(arq5,"<td> Transportes </td>");
        }
        if(v[i]== 4){
          fprintf(arq5,"<td> Alimentacao </td>");
        }
        if(v[i]== 5){
          fprintf(arq5,"<td> Trabalho </td>");
        }
        i = i+1;
        fprintf(arq5,"<td> %.0f ",v[i]);
        i = i+1;
        fprintf(arq5," / %.0f ",v[i]);
        i = i+1;
        fprintf(arq5," / %.0f ",v[i]);
        fprintf(arq5,"</td>");
        fprintf(arq5,"</tr>");
      i++;
    }
  r++;
    }

 i++;
  }
  fprintf(arq5,"</table>" );

fprintf(arq5,"<table border='2' align='40px' ><tr class='e'><td>Cadastro</td><td>Valor</td><td>Categoria</td><td>Data</td></tr>");
for (n = 0;(fscanf(arq2, "%f", &a)) != EOF;) {
    v2[n] = a;
    for(z=0; v2[z]!= 0;){
    if(v2[n] == ano && z % 5 == 0){
        n = n-5;
        fprintf(arq5,"<tr class='t'>");
        fprintf(arq5,"<td> Gasto </td>");
        n = n+1;
        fprintf(arq5,"<td> R$%.2f </td>",v2[n]);
        n = n+1;
        if(v2[n]== 1){
          fprintf(arq5,"<td> Moradia </td>");
        }
        if(v2[n]== 2){
          fprintf(arq5,"<td> Estudos </td>");
        }
        if(v2[n]== 3){
          fprintf(arq5,"<td> Transportes </td>");
        }
        if(v2[n]== 4){
          fprintf(arq5,"<td> Alimentacao </td>");
        }
        if(v2[n]== 5){
          fprintf(arq5,"<td> Trabalho </td>");
        }
        n = n+1;
        fprintf(arq5,"<td> %.0f ",v2[n]);
        n = n+1;
        fprintf(arq5," / %.0f ",v2[n]);
        n = n+1;
        fprintf(arq5," / %.0f ",v2[n]);
        fprintf(arq5,"</td>");
        fprintf(arq5,"</tr>");
      n++;
    }

  z++;
    }

 n++;
  }
  fprintf(arq5,"</table>" );
fprintf(arq5,"</body></html>");
  fclose(arq);
  fclose(arq2);
  fclose(arq5);
printf("\n ==============================================\n");
printf("|ARQUIVOS HTML E CSS FORAM CRIADOS COM SUCESSO!|");
printf("\n ==============================================\n");

}
////////////////////////////////////////////////
void relatoriocategmensal(){
int ano, mes, categ;
  FILE *arq3 = fopen("gerenciadorGasto.txt","a");
 FILE *arq4 = fopen("gerenciadorReceita.txt","a");
 FILE *arq6 = fopen("estilo.css","w");
 fprintf(arq6,".a{font-family: 'Arial Black';color:black;text-align: center;align-content: center;font-size: 30pt;}.t{font-family: 'Arial Black';color:darkred;text-align: center;font-size: 12pt;}.e{font-family: 'Arial Black';color:darkred;font-size: 15pt;text-align: center;}table{text-align:center;border-color: red;border-style: solid;background-color: black;}.body{background-color: rebeccapurple;}");
 fclose(arq6);
 FILE *arq5 = fopen("relatorio_mensal_categoria.html","w");
 fclose(arq3);
 fclose(arq4);
  FILE *arq2 = fopen("gerenciadorGasto.txt","r");
 FILE *arq = fopen("gerenciadorReceita.txt","r");
printf("\n ===============================\n");
printf("|RELATORIO MENSAL POR CATEGORIA |");
printf("\n ===============================\n");
printf("\nInsira o ano para poder ver o relatorio:\n");
scanf("%d", &ano);
printf("\nInsira o mes para poder ver o relatorio:\n");
scanf("%d", &mes);
printf("\nInsira a categoria para poder ver o relatorio, lembrando:1 para Moradia, 2 para Estudos, 3 para Transportes,4 para alimentacao e 5 para Trabalho \n");
scanf("%d", &categ);

  int r = 0;
  float x;
  float v[1000];
  int i=0;
  int z = 0;
  float a;
  float v2[1000];
  int n = 0;
  fprintf(arq5,"<!DOCTYPE html>");
fprintf(arq5,"<html>");
fprintf(arq5,"<head><meta charset='UTF-8'><title>Relatorio Mensal</title><link href='estilo.css'rel='stylesheet'></head><body class='body' align='center'> <a class='a' >Relatorio Mensal por categoria</a><br>");
fprintf(arq5,"<table border='2' align='left' ><tr class='e'><td>Cadastro</td><td>Valor</td><td>Categoria</td><td>Data</td></tr>");
for (i = 0;(fscanf(arq, "%f", &x)) != EOF;) {
    v[i] = x;
    for(r=0; v[r]!= 0;){
    if(v[i] == ano && r == 5){
        i = i-1;
        if(v[i] == mes){
          i = i-2;
          if(v[i] == categ){
            i = i - 2;
        fprintf(arq5,"<tr class='t'>");
        fprintf(arq5,"<td> Receita </td>");
        i = i+1;
        fprintf(arq5,"<td> R$%.2f </td>",v[i]);
        i = i+1;
        if(v[i]== 1){
          fprintf(arq5,"<td> Moradia </td>");
        }
        if(v[i]== 2){
          fprintf(arq5,"<td> Estudos </td>");
        }
        if(v[i]== 3){
          fprintf(arq5,"<td> Transportes </td>");
        }
        if(v[i]== 4){
          fprintf(arq5,"<td> Alimentacao </td>");
        }
        if(v[i]== 5){
          fprintf(arq5,"<td> Trabalho </td>");
        }
        i = i+1;
        fprintf(arq5,"<td> %.0f ",v[i]);
        i = i+1;
        fprintf(arq5," / %.0f ",v[i]);
        i = i+1;
        fprintf(arq5," / %.0f ",v[i]);
        fprintf(arq5,"</td>");
        fprintf(arq5,"</tr>");
      i++;
          }
        }

    }
   r++;
    }

 i++;
  }
  fprintf(arq5,"</table>" );
  fprintf(arq5,"<table border='2' align='left' ><tr class='e'><td>Cadastro</td><td>Valor</td><td>Categoria</td><td>Data</td></tr>");
  for (n = 0;(fscanf(arq2, "%f", &a)) != EOF;) {
    v2[n] = a;
    for(z=0; v2[z]!= 0;){
    if(v2[n] == ano && z == 5){
        n = n-1;
        if(v2[n]== mes){
          n = n-2;
          if(v2[n]== categ){
            n = n - 2;
            fprintf(arq5,"<tr class='t'>");
        fprintf(arq5,"<td> Gasto </td>");
        n = n+1;
        fprintf(arq5,"<td> R$%.2f </td>",v2[n]);
        n = n+1;
        if(v2[n]== 1){
          fprintf(arq5,"<td> Moradia </td>");
        }
        if(v2[n]== 2){
          fprintf(arq5,"<td> Estudos </td>");
        }
        if(v2[n]== 3){
          fprintf(arq5,"<td> Transportes </td>");
        }
        if(v2[n]== 4){
          fprintf(arq5,"<td> Alimentacao </td>");
        }
        if(v2[n]== 5){
          fprintf(arq5,"<td> Trabalho </td>");
        }
        n = n+1;
        fprintf(arq5,"<td> %.0f ",v2[n]);
        n = n+1;
        fprintf(arq5," / %.0f ",v2[n]);
        n = n+1;
        fprintf(arq5," / %.0f ",v2[n]);
        fprintf(arq5,"</td>");
        fprintf(arq5,"</tr>");
      n++;
          }
        }

    }
   z++;
    }

 n++;
  }
fprintf(arq5,"</table>" );
fprintf(arq5,"</body></html>");
fclose(arq);
fclose(arq2);
fclose(arq5);
printf("\n ==============================================\n");
printf("|ARQUIVOS HTML E CSS FORAM CRIADOS COM SUCESSO!|");
printf("\n ==============================================\n");
}
////////////////////////////////////////////
void apagarcadastros(){
  FILE *arq3 = fopen("gerenciadorGasto.txt","a");
  FILE *arq2 = fopen("saldo.txt","a");
 FILE *arq4 = fopen("gerenciadorReceita.txt","a");
 printf("\n ===============\n");
printf("|REMOCAO DE DADOS|");
printf("\n ================\n");
    puts("================================================");
    puts("| 1 - Se deseja remover os cadastros de gastos |");
    puts("|----------------------------------------------|");
    puts("| 2 - deseja remover os cadastros de receitas  |");
    puts("|----------------------------------------------|");
    puts("| 3 - Se deseja remover tudo                   |");
    puts("================================================");
    printf("opcao: ");
fclose(arq2);
 fclose(arq3);
 fclose(arq4);
int remov;
scanf("%d", &remov);

printf("\nApagando cadastro(s)...\n");
sleep(2);

if( remov == 1){
remove("gerenciadorGasto.txt");

}
if( remov == 2){
  remove("gerenciadorReceita.txt");
  remove("saldo.txt");
}
if( remov == 3){
  remove("gerenciadorReceita.txt");
  remove("gerenciadorGasto.txt");
  remove("gerenciador_financeiro.txt");
  remove("saldo.txt");
}
printf("\n ===================================\n");
printf("|CADASTRO(S) APAGADO(S) COM SUCESSO!|");
printf("\n ===================================\n");
}
/////////////////////////////////////////////
void consultarsaldo(){
    printf("\n =====\n");
    printf("|SALDO|");
    printf("\n =====\n");
  printf("\nConsultando seu saldo ...\n");
  sleep(2);
  FILE *arq3 = fopen("gerenciadorGasto.txt","a");
 FILE *arq4 = fopen("saldo.txt","a");
  FILE *arq2 = fopen("gerenciadorGasto.txt","r");
 FILE *arq = fopen("saldo.txt","r");
  int z = 0;
  float a,x;
  float v2[1000], v[1000];
  int n = 0, m =0;
  int b = 0;
  float aux_soma=0.0, aux_soma2=0.0;
  for (m = 0;(fscanf(arq, "%f", &x)) != EOF;) {
    v[m] = x;
        aux_soma2 = v[m] + aux_soma2;
 m++;
  }

  for (n = 0;(fscanf(arq2, "%f", &a)) != EOF;) {
    v2[n] = a;

    for(z=0; v2[z]!= 0;){

    if(v2[n] < 0&&z == 1){

        aux_soma = v2[n] + aux_soma;
      n++;

    b++;}
    z++;}

 n++;

  }
  float aux = aux_soma2 + aux_soma;
  if(aux>0){
    printf("\n ---------------\n");
    printf("|SALDO POSITIVO!|");
    printf("\n ---------------\n");
    printf("Seu saldo eh de: R$%.2f ",(aux_soma2 + aux_soma));
  }
  else if(aux<0){
    printf("\n ---------------\n");
    printf("|SALDO NEGATIVO!|");
    printf("\n ---------------\n");
    printf("Seu saldo eh de: R$%.2f ",(aux_soma2 + aux_soma));
  }
  else if(aux == 0.0){
    printf("\n -----------\n");
    printf("|SALDO NULO!|");
    printf("\n -----------\n");
    printf("Seu saldo eh de: R$%.2f ",(aux_soma2 + aux_soma));
  }


  fclose(arq2);
  fclose(arq);
  fclose(arq3);
  fclose(arq4);
}
//////////////////////////////////////////////////////
void relatoriodiario(){
  int ano, mes, dia;
  FILE *arq3 = fopen("gerenciadorGasto.txt","a");
 FILE *arq4 = fopen("gerenciadorReceita.txt","a");
 fclose(arq3);
 fclose(arq4);
  FILE *arq2 = fopen("gerenciadorGasto.txt","r");
 FILE *arq = fopen("gerenciadorReceita.txt","r");
printf("\n =================\n");
printf("|RELATORIO DIARIO |");
printf("\n =================\n");
printf("\nInsira o dia para poder ver o relatorio: ");
scanf("%d", &dia);
printf("\nInsira o mes para poder ver o relatorio: ");
scanf("%d", &mes);
printf("\nInsira o ano para poder ver o relatorio: ");
scanf("%d", &ano);
puts("");

  int r = 0;
  float x;
  float v[1000];
  int i=0;
  int z = 0;
  float a;
  float v2[1000];
  int n = 0;
for (i = 0;(fscanf(arq, "%f", &x)) != EOF;) {
    v[i] = x;
    for(r=0; v[r]!= 0;){
    if(v[i] == ano && r == 5){
        i = i-1;
        if(v[i]== mes){
          i = i-1;
          if(v[i]== dia){
            i = i - 3;
            printf("| Receita ");
        i = i+1;
        printf(" R$%.2f ",v[i]);
        i = i+1;
        if(v[i]== 1){
          printf(" Categoria: Moradia   ");
        }
        if(v[i]== 2){
          printf(" Categoria: Estudos   ");
        }
        if(v[i]== 3){
          printf(" Categoria: Transportes   ");
        }
        if(v[i]== 4){
          printf(" Categoria: Alimentacao   ");
        }
        if(v[i]== 5){
          printf(" Categoria: Trabalho   ");
        }
        i = i+1;
        printf("Data: %.0f",v[i]);
        i = i+1;
        printf(" / %.0f",v[i]);
        i = i+1;
        printf(" / %.0f |\n",v[i]);
      i++;
          }
        }

    }
   r++;
    }

 i++;
  }
  for (n = 0;(fscanf(arq2, "%f", &a)) != EOF;) {
    v2[n] = a;
    for(z=0; v2[z]!= 0;){
    if(v2[n] == ano && z == 5){
        n = n-1;
        if(v2[n]== mes){
          n = n-1;
          if(v2[n]== dia){
           n = n - 3;
            printf("| Gasto   ");
        n = n+1;
        printf("R$%.2f  ",v2[n]);
        n = n+1;
        if(v2[n]== 1){
          printf(" Categoria: Moradia   ");
        }
        if(v2[n]== 2){
          printf(" Categoria: Estudos   ");
        }
        if(v2[n]== 3){
          printf(" Categoria: Transportes   ");
        }
        if(v2[n]== 4){
          printf(" Categoria: Alimentacao   ");
        }
        if(v2[n]== 5){
          printf(" Categoria: Trabalho   ");
        }
        n = n+1;
        printf("Data: %.0f",v2[n]);
        n = n+1;
        printf(" / %.0f",v2[n]);
        n = n+1;
        printf(" / %.0f |\n",v2[n]);
      n++;
          }
        }

    }
   z++;
    }

 n++;
  }
    fclose(arq);
  fclose(arq2);
fclose(arq3);
  fclose(arq4);
}
//////////////////////////////////////////////////////
void todoscadastros(){


 FILE *arq4 = fopen("gerenciador_financeiro.txt","a");
 fclose(arq4);
  FILE *arq2 = fopen("gerenciador_financeiro.txt","r");

printf("\nConsultando todos os cadastros:\n");
sleep(1);
puts("");
  char a;
  char v2[1000];
  int n = 0;

  for (n = 0;(fscanf(arq2, "%c", &a)) != EOF;) {
    v2[n] = a;

    printf("%c",v2[n]);

 n++;
  }

  fclose(arq2);


}
void menu()
{
  int i = 0;
  while(i==0){

    puts("");
    puts(" ===============================================");
    printf("|       /\\    /\\     __                        |\n");
    printf("|      /  \\  /  \\   |__   /\\  /  |   |         |\n");
    printf("|     /    \\/    \\  |__  /  \\/   |___|         |\n");

    puts("================================================");
    puts("| 1 - Cadastrar Receita                        |");
    puts("|----------------------------------------------|");
    puts("| 2 - Cadastrar Gasto                          |");
    puts("|----------------------------------------------|");
    puts("| 3 - Relatorio para os ultimos 12 meses       |");
    puts("|----------------------------------------------|");
    puts("| 4 - Relatorio mensal para cada categoria     |");
    puts("|----------------------------------------------|");
    puts("| 5 - Apagar seus cadastros                    |");
    puts("|----------------------------------------------|");
    puts("| 6 - Consultar o saldo                        |");
    puts("|----------------------------------------------|");
    puts("| 7 - Relatorio diario                         |");
    puts("|----------------------------------------------|");
    puts("| 8 - Todos os cadastramentos                  |");
    puts("|----------------------------------------------|");
    puts("| 0 - Sair                                     |");
    puts(" ==============================================");
    int op;
    puts("");
    puts("=================");
    printf("Digite a opcao: ");
    scanf("%d", &op);
    printf("=================");




puts("");
printf("opcao => %d\n", op);
    if(op == 1){
    cadastrarreceita();

   }
   if(op == 2){
    cadastrargasto();

   }
    if(op == 3){
    relatorio12meses();
   }
    if(op == 4){
    relatoriocategmensal();
   }
   if(op == 5){
    apagarcadastros();
   }
   if(op == 6){
    consultarsaldo();
   }
    if(op == 7){
    relatoriodiario();
   }
   if(op == 8){
    todoscadastros();
   }
   if(op == 0){
    printf("\nSaindo ...\n");
    sleep(2);
    break;
   }
  }

}
int main()
{

menu();


return 0;
}
