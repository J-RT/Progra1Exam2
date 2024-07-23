#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<windows.h>
#include<ctype.h>
using namespace std;

// VARIABLES GLOBALES
int cantidadCandidatos = 0,totalVotos=0;
// AREGLOS GLOBALES
int numerosCedula[100],votosCandidatos[10] = {0,0,0,0,0,0,0,0,0,0};
string nombresCandidatos[10],partidosPoliticos[10],nombresVotante[100];
bool chekeoVotos[100];

// METODO PARA LAS CORDENADAS EN CONSOLA
void gotoxy(int x ,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
// Metodo PARA CREAR GRAFICOS
  void hacerGraficos(int a,int y){
int i;int j=20;
for (i=1; i<=a; i++){
        gotoxy(j,y); printf("%c",178);
		j++;
	}
  }

// METODO PARA REGISTRAR CANDIDATOS
void registrarCandidato () {
    //VARIABLES LOCALES
    char opcion,indice=0;
    system("cls");
    do {
    cout << "Ingrese el nombre del candidato\n";
    cin >> nombresCandidatos[indice];
    cout << "Ingrese el nombre del  partido politico\n";
    cin >> partidosPoliticos[indice];
    indice++;
    cantidadCandidatos++;
    cout << "s)Ingresar mas candidatos\nn)Salir\n";
    cin >> opcion;
    } while (opcion == 's' || opcion == 'S');
}

// METODO PARA GENERAR LISTA CANDIDATOS
void candidatos () {
    cout << "Elija su candidato\n";
    int opcionCandidato;
    int j=1;
    for (int i = 0;i < cantidadCandidatos; i++) {
        cout << j << ") " << nombresCandidatos[i] << "  Partido: " << partidosPoliticos[i] << "\n";
        j++;
    }
    cout << "su opcion es: ";
    cin >> opcionCandidato;
    switch(opcionCandidato) {
  case 1:
      votosCandidatos[0]+=1;
    break;
  case 2:
      votosCandidatos[1]+=1;
    break;
    case 3:
        votosCandidatos[2]+=1;
    break;
    case 4:
        votosCandidatos[3]+=1;
    break;
    case 5:
        votosCandidatos[4]+=1;
    break;
    case 6:
        votosCandidatos[5]+=1;
    break;
    case 7:
        votosCandidatos[6]+=1;
    break;
    case 8:
        votosCandidatos[7]+=1;
    break;
    case 9:
        votosCandidatos[8]+=1;
    break;
    case 10:
        votosCandidatos[9]+=1;
    break;
}

}
// METODO PARA REGISTRAR VOTANTES
void votantes () {
    // VARIABLES LOCALES
    int cedula,edad;
    string nombre;
    char opcion,indice=0;
    system("cls");
    do {
    cout << "Ingrese el nombre del votante\n";
    cin >> nombre;
    cout << "Ingrese el numero de cedula\n";
    cin >> cedula;
    cout << "Ingrese su edad\n";
    cin >> edad;
    if (edad < 18) {
        cout << "no puede votar\n";
    } else {
        cout << "Si puede votar\n";
        nombresCandidatos[indice] = nombre;
        numerosCedula[indice] = cedula;
        chekeoVotos[indice] == '1';
        indice++;
    }
     cout << "s)Registrar mas votantes\nn)Salir\n";
    cin >> opcion;
    } while (opcion == 's' || opcion == 'S');
}

// METODO PARA REGISTRAR VOTOS
void votos() {
    // VARIABLES LOCALES
    for (int b=0; b <100;b++){
            chekeoVotos[b] = false;
    }
    int cedula,indice,i;
    char opcion;
     bool verificacion;
     system("cls");
    do {
    verificacion = false;
    cout << "Ingrese el numero de cedula\n";
    cin >> cedula;
    for (indice = 0; indice < 100; indice++) {
    if (cedula == numerosCedula[indice] ) {
        verificacion = true;
        i = indice;
    }
}
    if (verificacion == true && chekeoVotos[i] == false) {
            candidatos();
            chekeoVotos[i]=true;
            totalVotos+=1;
    }else if (verificacion == true && chekeoVotos[i] == true){
        cout << "Usted ya a votado\n";
    } else {
        cout << "Lo sentimos, primero debe registrarse\n";
    }

     cout << "s)Registrar mas  votos\nn)Salir\n";
    cin >> opcion;
    } while (opcion == 's' || opcion == 'S');
}
// METODO PARA REGISTRAR VOTOS
void registrarVotos(){
    char opcion;
    system("cls");
    do{
    cout << "0) Registrar votante\n1) Registrar voto\n2) Salir\n";
    cin >> opcion;
    switch(opcion) {
  case '0':
      votantes();
    break;
  case '1':
      votos();
    break;
  case '2':
    break;
}
    } while (opcion != '2');
}
// METODO PARA MONSTAR RESULTADOS
void resultados () {
    system("cls");
    float porcentajeVotos[10] = {0,0,0,0,0,0,0,0,0,0};
    porcentajeVotos[0]=votosCandidatos[0]*100/totalVotos;
    porcentajeVotos[1]=votosCandidatos[1]*100/totalVotos;
    porcentajeVotos[2]=votosCandidatos[2]*100/totalVotos;
    porcentajeVotos[3]=votosCandidatos[3]*100/totalVotos;
    porcentajeVotos[4]=votosCandidatos[4]*100/totalVotos;
    porcentajeVotos[5]=votosCandidatos[5]*100/totalVotos;
    porcentajeVotos[6]=votosCandidatos[6]*100/totalVotos;
    porcentajeVotos[7]=votosCandidatos[7]*100/totalVotos;
    porcentajeVotos[8]=votosCandidatos[8]*100/totalVotos;
    porcentajeVotos[9]=votosCandidatos[9]*100/totalVotos;
    int y =4,y2=3,x2=4;
    for (int p=0;p < cantidadCandidatos;p++) {
    gotoxy(x2,y2);cout << "Nombre Candidato: "<< nombresCandidatos[p] << "   " << "Partido Politico: " << partidosPoliticos[p];
    hacerGraficos(porcentajeVotos[p],y);
    cout << " " << porcentajeVotos[p] << "%\n";
    y2+=3;
    y+=3;
    }
    int mayor=0,g;
    string ganador,ppGanador;
    for (g=0;g< cantidadCandidatos;g++) {
            if (votosCandidatos[g] > mayor) {
                mayor = votosCandidatos[g];
                ganador = nombresCandidatos[g];
                ppGanador = partidosPoliticos[g];
            }
    }
    cout << "\n";
    cout << "                   El ganador es: " << ganador << "   " << "Del partido: " << ppGanador << "\n";
    cout << "\n";
    cout << "<Pulse cualquier tecla para salir>";
	getch();
}
// MENU PRINCIPAL DEL SISTEMA
void menuPrincipal () {
   char opcion;
    system("cls");
    do {
    cout << "Sistema de Votaciones\n";
    cout << "Menu Principal\n";
    cout << "0) Registrar candidato\n1) Registrar votaciones\n2) Resultados\n3) Salir\n";
    cin >> opcion;
    switch(opcion) {
  case '0':
      registrarCandidato();
    break;
  case '1':
      registrarVotos();
    break;
  case '2':
      resultados();
    break;
}
} while (opcion != '3');
}
int main() {
  resultados();
  return 0;
}

