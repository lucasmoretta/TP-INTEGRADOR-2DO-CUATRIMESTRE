#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.>

struct Fecha
{
	
	int dia,mes,anio;

};
struct mascota
{
	
	char ApeyNom[60];
	char Domicilio[60];
	int DNI_Dueno;
	char localidad[60];
	Fecha fec;
	float Peso;
	int telefono;
	char diagnostico[380];

};
struct Turnos
{

	int matricula;
	Fecha fec;
	int DNI_Dueno;
	char detalle[380];

};
struct users
{

	char usuario[20];
	char pass[20];
	char nombre[60];

};

using namespace std;

int menuprincipal();
void inicio(int &b);
void evolucion_mascota(turnos t);
void cargar_detalle(turnos t);
viod mostrar_turnos();

main()
{
	
	turnos t;
	int opcion=0,b;
	
	do
	{
		opcion=menuprincipal();
		switch(opcion)
		{
			case 1:
				inicio(b);
				break;
			case 2:
				//opcion2();//registrar usuario de administracion
				break;
			case 3:
		//		opcion3();//
				break;
			case 4:
		//		opcion4();//
				break;
		}
	}while(opcion!=0);	
}


int menuprincipal()
{
	int opcion;
	system("CLS");
	printf("");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t     Modulo consultorio veterinario          \n");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t 1.- Iniciar secion.    \n");
	printf("\n\t\t\t 2.- visualizar lista de espera de turnos. \n");
	printf("\n\t\t\t 3.- registrar evolucionde la mascota. \n");
	printf("\n\t\t\t 4.- Salir del programa.      \n\n");
	printf("\n\t\t\t ======================================\n");
	printf("\n\t\t\t    Ingrese su Opcion ...: "); scanf(" %d",&opcion);
	return opcion;
}

void inicio(int &b)
{
	FILE *arch;
	veterinario x;
	
	char asist[60];
	char contr[60];
 	system("cls");
	
	arch=fopen("veterinario.dat","rb");

	if(arch==NULL)
	{
		printf("\nNo hay usuarios registrados...");
		system("pause");
	}
	else
	{
		do
		{
			rewind(arch);
			_flushall();
			printf("\nIngrese Usuario: ");
			gets(asist);
			fread(&x,sizeof(users),1,arch);
			while(!feof(arch))
			{
			if(strcmp(x.usuario,veterinario)==0)
			{

				b=1;
			}
			fread(&x,sizeof(users),1,arch);
			}
			if(b==0)
			{
				printf("\nNo existe el usuario ingresado");
			}
		}while(b!=1);

		do
		{
			rewind(arch);
			_flushall();
			printf("\nIngrese Contraseña: ");
			gets(contr);
			fread(&x,sizeof(users),1,arch);
			while(!feof(arch))
			{
			if(strcmp(x.pass,contr)==0)
			{
				b=1;
			}
			fread(&x,sizeof(users),1,arch);
			}
			if(b==0)
			{
				printf("\nContraseña Incorrecta...");
			}
		}while(b!=1);
	}
}

void evolucion_mascota(turnos t){
	
	FIlE * arch;
	mascota x;
	
	int DNI_d[60];
	char [380];
	system("cls");
	
	arch=fopen("turnos","rb");
	
	if(arch==NULL)
	{
		printf("\nNo se registro ningun turno..");
		system("pause");
	}
	else
	{
		do
		{
			rewind(arch);
			_flushall();
			printf("\ingrese el DNI del due%:co ",164);
			gets(DNI_d);
			fread(&x,sizeof(turno),1,arch);
			while(!feof(arch))
			{
			if(strcmp(x.DNI_Dueno)==0)
			{

				b=1;
			}
			fread(&x,sizeof(turnos),1,arch);
			}
			if(b==0)
			{
				
				printf("\nNo se registro ninguna mascota");
			
			}
			
			system("cls");
			cargar_detalle(turnos t);
				
		}while(b!=1);

}

}

void cargar_detalle(turnos t){
	
	FILE * arch
	
	arch = fopen("turnos.dat" , "a+b" );
	
	_flushall();
	printf("Ingrese el diagnostico de la mascota;");
	gets(t.detalle_atencion);
	
}

void mostrar_turnos(){
	
	ifstream archivo;
	string turnos;
	
	archivo.open("turnos.dat",ios::in);
	
	if(archivo.fail()){
		
		printf("No se registro ningun turno");
		
	} 
	
	while(!archivo.eof()){
		
		getline(archivo,turnos);
		cout<<turnos<<endl
		
	}
	
	archivo.close();
	
}
