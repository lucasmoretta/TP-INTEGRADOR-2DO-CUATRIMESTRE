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
	bool borrado;
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
void evolucion_mascota();
void cargar_detalle(turnos t);
viod mostrar_turnos();
bool borrado_turno(FILE * turnos, int DNI_D)
main()
{
	
	veterinario vet;
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
				mostrar_turnos();
				break;
			case 3:
				evolucion_mascota();
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
 	
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t      Iniciar secion          \n");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t");
	
	arch=fopen("veterinario.dat","rb");

	if(arch==NULL)
	{
		printf("\n\t\t\tNo hay usuarios registrados...");
		system("pause");
	}
	else
	{
		do
		{
			rewind(arch);
			_flushall();
			printf("\n\t\t\tIngrese Usuario: ");
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
				printf("\n\t\t\tContraseña Incorrecta...");
			}
		}while(b!=1);
	}
}

void evolucion_mascota(turnos t){
	
	FIlE * arch;
	mascota x;
	
	int DNI_d[60];
	char [380];
	
	printf("\n\t\t\t========================================\n");
	printf("\n\t\t\t  registrar la evolucion de la mascota          \n");
	printf("\n\t\t\t========================================\n");
	
	arch=fopen("turnos.dat","r+b");
	
	if(arch==NULL)
	{
		printf("\n\t\t\tNo se registro ningun turno..");
		system("cls");
		system("pause");
	}
	else
	{
		do
		{
			rewind(arch);
			
			printf("\n\t\t\tingrese el DNI del due%:co ",164);
			scanf("%d",&DNI_d);
			fread(&x,sizeof(turno),1,arch);
			while(!feof(arch))
			{
			if(DNI_d == x.DNI_Dueno)
			{
				b=1;
			}
			fread(&x,sizeof(turnos),1,arch);
			}
			if(b==0)
			{
				printf("\n\t\t\tNo se registro ninguna mascota");
			}
			
			system("cls");
			cargar_detalle(turnos t);
			borrado_turnos(turnos t, DNI_d);
				
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

bool borrado_turno(FILE * turnos, int DNI_D){
	
	bool borrado;
	borrado = false;
	
	regturnos reg;
	
	FILE * archtemp;
	archtemp = fopen("turnos.dat","w+b");
	
	if(DNI_D>0){
		
		rewind(turnos);
		fread(&reg,sizeof(reg),1,turnos);
		
		while(!=feof(turnos)){
			
			if(DNI_D != reg.DNI_dueno){
				
				fwrite(&reg,sizeof(reg),1,archtemp);
				
			}else{
				
				borrado = true;
				
			}
			
			fread(&reg, sizeof(regturnos),1,turnos);
			
		}
		
	}else{
		
		fclose(archtemp);
		
	}
	
	if(borrado){
		
		fclese(archtemp);
		fclose(turnos);
		remove("turnos.dat");
		rename("turnostemp.dat","turnos.dat");
		
		printf("El turnos se cumplio y ha sido eliminado del registro");
		
	}else{
		
		printf("El turno no se cumplio, aun no fue eliminado del registro ");
		fclose(archtemp);
		
	}
	
	system("cls");
	remove("turnostemp.dat");
	return borrado;
	
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
