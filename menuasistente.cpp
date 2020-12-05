#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

int menuasistente();
void inicio(int &b);
void mascota();

main()
{
 	int opcion=0,b=0;
 	
 	do
 	{
 		opcion=menuasistente();
 		switch(opcion)
 		{
 			case 1:
				inicio(b);
				break;
			case 2:
				if(b==1)
				mascota();
				else
				printf("\nInicie sesion para realizar las otras opciones...");
				break;
		}
 		
	}while(opcion!=5);

    printf("\n\n");
    system("pause");
}

int menuasistente()
{
	int opcion;
	system("CLS");
	printf("");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t        Modulo del Asistente           \n");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t 1.- Iniciar Sesion.    \n");
	printf("\n\t\t\t 2.- Registrar Mascota. \n");
	printf("\n\t\t\t 3.- Registrar Turno.  \n");
	printf("\n\t\t\t 4.- Listado de Atenciones por Veterinario y Fecha.      \n\n");
	printf("\n\t\t\t 5.- Salir del programa.               \n");
	printf("\n\t\t\t ======================================\n");
	printf("\n\t\t\t    Ingrese su Opcion ...: "); scanf(" %d",&opcion);
	return opcion;
}

void inicio(int &b)
{
	FILE *arch;
	users x;
	
	char asist[60];
	char contr[60];
 	system("cls");
	
	arch=fopen("Usuarios.dat","rb");

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
			if(strcmp(x.usuario,asist)==0)
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

void mascota()
{
	FILE *arch;
}
