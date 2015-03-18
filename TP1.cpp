#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

#define Nmax 100


//ESTRUCTURA ESTUDIANTE--------------------------------------

// comentario de gaspar
typedef struct{
	
	char nombre[20];
	int dni;
	int anioIngreso;
	
}Estudiante;

//---------------------------------------------------------

int Codigo(){
	int cod;
	
	do
	cin>>cod;
	while(cod!=1 && cod!=0);
	
	return cod;
	
}


//-------------FUNCION  IMPRIMIR--------------------------------------------------
void printLista(Estudiante *lista, Estudiante * pun)     //IMPRIME LA LISTA DE DATOS
{
	cout<<"Nombre_______________"<<"Dni____________"<<"Ingreso________________\n";
	int i=0;
	
	
	while((lista+i)<pun)
	{
		cout<<left<<setw(21)<<(lista+i)->nombre;
		cout<<right<<setw(10)<<(lista+i)->dni<<setw(10)<<fixed<<(lista+i)->anioIngreso<<endl;
		i++;
		
	}
	
}
//------------------------------------------------------



int main()
{
	Estudiante *datos;   								//Declaraciones
	datos=(Estudiante *)malloc(sizeof(Estudiante)*100);
	
	
	
	Estudiante *ptr;
	ptr=datos;
	
	
	cout<<"\nCargar Archivo de Datos? 1:SI 0:NO"<<endl;
	
	
	if(Codigo()){
	
	//----------------LECTURA DEL ARCHIVO--------------------
	FILE *arch;
    arch = fopen ("loco.txt", "r");
	if (arch==NULL) {
        perror("Error");
        return 1;
    }
    else
	 { 
         
         
         while(!feof(arch))
         {     
              
            fscanf(arch,"%ld %s %d", &ptr->dni, &ptr->nombre, &ptr->anioIngreso);                  //Lee los datos de la estructura desde el archivo
           // printf ("%ld %s %d",pepe->dni, pepe->nombre, pepe->ingreso);                             //Esta linea es para ver que se leen bien los
            
            ptr++; 
			    
         
        }           
     }
    fclose(arch);
    cout<<"Archivo cargado con exito \n";
	}
	//----------------------------------------------------
	
	cout<<"\nIngresar Datos Manualmente?: \n";
	
//---------------DATOS INGRESADOS POR EL USUARIO------------------	
	if(Codigo())
{
	char aux [20];
	
	while(ptr<&datos[99])
	{
		cout<<"\nNombre: "<<endl;
		cin>>aux;
		strcpy (ptr->nombre, aux);
	//	cin.getline((ptr)->nombre, 20);
		//cin.getline((ptr)->nombre, 20);
		cout<<"Dni: ";
		cin>>(ptr)->dni;
		cout<<"Anio de Ingreso: ";
		cin>>(ptr)->anioIngreso;
		
		cout<<"\n Otro dato? : ";
				
		ptr++;
		if(!Codigo())
		\\break;
		
		
		
	}
}
//-------------------------------------------






	printLista(datos, ptr);   //IMPRIME LA LISTA
	
	
	cout<<"\n\n----FIN DEL PROGRAMA----";

}
