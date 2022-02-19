#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <vector>


#define CLEAR "cls"


using namespace std;

float precioParqueo();
void baseDatos();
void lectura();
void cambio();
void gotoxy(int,int);
void dibujarCuadro(int x1,int y1,int x2,int y2);
void carga();
void consola();

int opcion = 0;

int main(int argc, char *argv[]){
	
	
    cambio();
    
    time_t now = time(0);

/* Objeto de una estructura tm con fecha/hora local */
tm * time = localtime(&now);

vector<string> dia_semana;
dia_semana.push_back("Domingo");
dia_semana.push_back("Lunes");
dia_semana.push_back("Martes");
dia_semana.push_back("Miercoles");
dia_semana.push_back("Jueves");
dia_semana.push_back("Viernes");
dia_semana.push_back("Sabado");

vector<string> mes;
mes.push_back("Enero");
mes.push_back("Febrero");
mes.push_back("Marzo");
mes.push_back("Abril");
mes.push_back("Mayo");
mes.push_back("Junio");
mes.push_back("Julio");
mes.push_back("Agosto");
mes.push_back("Septiembre");
mes.push_back("Octubre");
mes.push_back("Noviembre");
mes.push_back("Diciembre");

int year = 1900 + time->tm_year;


cout << "Hoy " << dia_semana[time->tm_wday] << ", ";
cout << time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
cout << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;
	 
  system ("pause");
  return 0;
}

void dibujarCuadro(int x1,int y1,int x2,int y2){
	int i;
	
    for (i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "\304"; //linea horizontal superior
		gotoxy(i,y2); cout << "\304"; //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); cout <<"\263"; //linea vertical izquierda
		gotoxy(x2,i); cout <<"\263"; //linea vertical derecha
	}
	
    gotoxy(x1,y1); cout<< "\332"; 
    gotoxy(x1,y2); cout<< "\300";
    gotoxy(x2,y1); cout<< "\277";
    gotoxy(x2,y2); cout<< "\331";
}

void baseDatos (){
  ofstream archivo;
  
  string baseDatos,inicio = " ",nombre,tipo,placa,final = " ";
  
  archivo.open("parqueadero.txt",ios::out);
  if(archivo.fail()){ //Si a ocurrido algun error
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
		
	cout<<"\n Ingrese sus datos para registrar en el sistema"<<endl;
	getline(cin,inicio);
	cout<<"\n Ingrese su nombre: ";
	getline(cin,nombre);
    cout<<"\n Ingrese su tipo de vehiculo:" ;
	getline(cin,tipo);
    cout<<"\n Ingrese la placa del vehiculo:" ;
	getline(cin,placa);
	cout<<"\n Presione ENTER para salir ";
	getline(cin,final);
	
	
    archivo<<inicio<<endl;
	archivo<<"Su nombre: "<<nombre<<endl;
	archivo<<"Su tipo de vehiculo: "<<tipo<<endl;
	archivo<<"Su placa: "<<placa<<endl;
	archivo<<final<<endl;
	
	
	archivo.close(); //Cerramos el archivo
	system(CLEAR);
}

void lectura(){
	ifstream archivo;
	string texto;
	
	archivo.open("parqueadero.txt",ios::in); // Abrimos el archivo en modo lectura
	if(archivo.fail()){ //Si a ocurrido algun error
		cout<<"No ha ingresado datos todavia en el archivo";
		exit(1);
	}
	
	while(!archivo.eof()){
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	
	archivo.close();
	system("PAUSE");
	
}

void cambio(){
do{
	
	  consola();
	
    cout << "  Seleccione 1 para ingresar sus datos: "<<endl;
    cout << "  Seleccione 2 para ver el monto a pagar: "<<endl;
    cout << "  Seleccione 3 para ver sus datos: "<<endl;
    cout << "  Seleccione 4 para salir: "<<endl;
    cout << "  ";
    cin >>opcion;
    

	switch(opcion)
{
    case 1: 
    cout << " Ingrese sus datos para registrar en el sistema"<<endl;
    system(CLEAR);
    carga();
    system(CLEAR);
    
    baseDatos();
    
    break;
    case 2: 
    cout << " Ingrese el monto a pagar de su vehiculo"<<endl;
    system(CLEAR);
    carga();
    system(CLEAR);
    precioParqueo();
    break;
    case 3: 
    cout << " Datos del usuario"<<endl;
    system(CLEAR);
    carga();
    system(CLEAR);
    lectura();
    break;
    default: 
    
    cout << "\nPresione una ENTER para salir."<<endl;
    		
	
	break; 
	
}
}while(opcion != 4);

{
	cout << " Esperamos que haya disfrutado su estadia."<<endl;
}


}

float precioParqueo()
{
  float precio;
  cout<<" Digite el tiempo de estancia:"<<endl;
  cout<<" ";
  cin>>precio;
  
  if (precio == 1)
      {
    cout<<" El total a pagar es: "<<1.50<<endl;
      }
  else
      {
      cout<<" El total a pagar es: "<<(precio*1.50)<<endl;
	  }
	system("PAUSE");
}
    
void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void consola(){
	  system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
    system("COLOR B0");                  //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
    dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
    dibujarCuadro(1,1,78,3); //SE DIBUJA EL CUADRO DEL TITULO
    gotoxy(20,2); cout << "SISTEMA DE ESTACIONAMIENTO\n\n";
}

void carga(){
	char a = 177, b = 219;
cout <<"\n\n\n\t\t\t\tLoading....";
cout <<"\n\n\n";
cout << "\t\t\t";
     for (int i = 0; i <= 25; i++)
cout << a;
Sleep(150);
cout <<"\r"; // Retorno de Carro o ENTER
cout <<"\t\t\t";
for (int i = 0; i <= 25; i++){
cout << b;
Sleep (200);
}
}
