#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.>

struct Fecha
{
	int dia=0,mes=0,anio=0;
};
struct mascota
{
	char ApeyNom[60]="palabra";
	char Domicilio[60]="palabra";
	int DNI_Dueno=0;
	char localidad[60]="palabra";
	Fecha fec;
	float Peso=0;
	int telefono=0;
};
struct Turnos
{
	int matricula=0;
	Fecha fec;
	int DNI_Dueno=0;
	char detalle_atencion[380]="palabra";
	bool borrado=false;
	char diagnostico[400]="palabra";
};
struct users
{
	char usuario[20]="palabra";
	char pass[20]="palabra";
	char nombre[60]="palabra";
};
struct veterinario
{
	char usuario[20]="palabra";
	char pass[20]="palabra";
	char nombre[60]="palabra";
	int matricula=0;
	int dni=0;
	int telefono=0;
};

using namespace std;

int menuprincipal();
void inicio(int &b,int &matr);
void opcion2(int matr);
void opcion3(int matr);

main()
{
	system("color F4");
	veterinario vet;
	Turnos t;
	int matr,opcion=0,b=0;
	
	do
	{
		opcion=menuprincipal();
		switch(opcion)
		{
			case 1:
				inicio(b,matr);
				break;
			case 2:
				if(b==1)
				{
					opcion2(matr);
				}
				else
				{
					system("CLS");
					printf("\n\n\n\t\t\t===================================================\n");
					printf("\n\t\t\t Inicie sesion para realizar las otras opciones...         \n");
					printf("\n\t\t\t===================================================\n");
					printf("\n\n\n\t\t\t");system("pause");system("cls");	
				}
				break;
			case 3:
				if(b==1)
					{
						opcion3(matr);
					}
					else
					{
						system("CLS");
						printf("\n\n\n\t\t\t===================================================\n");
						printf("\n\t\t\t Inicie sesion para realizar las otras opciones...         \n");
						printf("\n\t\t\t===================================================\n");
						printf("\n\n\n\t\t\t");system("pause");system("cls");	
					}
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
	printf("\n\t\t\t 1.- Iniciar sesion.    \n");
	printf("\n\t\t\t 2.- visualizar lista de espera de turnos. \n");
	printf("\n\t\t\t 3.- registrar evolucionde la mascota. \n");
	printf("\n\t\t\t 0.- Salir del programa.      \n\n");
	printf("\n\t\t\t ======================================\n");
	printf("\n\t\t\t    Ingrese su Opcion ...: "); scanf(" %d",&opcion);
	return opcion;
}

void inicio(int &b,int &matr)
{
	FILE *arch;
	veterinario x;
//	int matr;
	char vet[60];
	char contr[60];
 	
 	system("cls");
 	
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t      Iniciar sesion          \n");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t");
	
	arch=fopen("Veterinarios.dat","rb");

	if(arch==NULL)
	{
		printf("\n\t\t\tNo hay usuarios registrados...");
		printf("\n\t\t\t");
		system("pause");
	}
	else
	{
		do
		{
			b=0;
			rewind(arch);
			_flushall();
			printf("\n\t\t\tIngrese Usuario: ");
			printf("\n\n\n\t");
			gets(vet);
			fread(&x,sizeof(veterinario),1,arch);
			while(!feof(arch))
			{
				if(strcmp(x.usuario,vet)==0)
				{
					b=1;
				}
				fread(&x,sizeof(users),1,arch);
			}
			if(b==0)
				{
					printf("\n\t\t\t");
					printf("No existe el usuario ingresado");
				}
		}while(b!=1);

		do
		{
			b=0;
			rewind(arch);
			_flushall();
			printf("\n\t\t\t");
			printf("Ingrese Contrase%ca: ",164);
			printf("\n\t\t\t");
			gets(contr);
			fread(&x,sizeof(veterinario),1,arch);
			while(!feof(arch))
			{
				if(strcmp(x.pass,contr)==0)
				{
					b=1;
					matr=x.matricula;
				}
				fread(&x,sizeof(users),1,arch);
			}
			if(b==0)
			{
				printf("\n\t\t\tContrase%ca Incorrecta...",164);
			}
		}while(b!=1);
	}
	fclose(arch);
}
void opcion2(int matr)
{
	Fecha hoy;
	FILE *arch;
	Turnos x;
	int dni_atender,i=0,b;
	arch=fopen("Turnos.dat","rb");
	if(arch==NULL)
	{
		printf("\n\t\t\tNo hay turnos registrados...");
		printf("\n\n\n\t\t\t");system("pause");system("cls");
	}
	else
	{
		system("CLS");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\t        Listar Turnos         \n");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\tIngrese el dia:\n");
		printf("\n\t\t\t");
		scanf("%d",&hoy.dia);
		printf("\n\t\t\tIngrese el mes:\n");
		printf("\n\t\t\t");
		scanf("%d",&hoy.mes);
		printf("\n\t\t\tIngrese el a%co:\n",164);
		printf("\n\t\t\t");
		scanf("%d",&hoy.anio);
		rewind(arch);
		system("CLS");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\t       Listas de Turnos del dia          \n");
		printf("\n\t\t\t=======================================\n");
		fread(&x,sizeof(Turnos),1,arch);
		b=0;
		
		while(!feof(arch))
		{
			if(matr==x.matricula && hoy.dia==x.fec.dia && hoy.mes==x.fec.mes && hoy.anio==x.fec.anio)
			{
				i++;
				printf("\n\t\t\t%d) DNI del due%co: %d",i,164,x.DNI_Dueno);
				b=1;			
			}
			fread(&x,sizeof(Turnos),1,arch);
		}
		
		if(b==0)
		{
			printf("\n\t\t\tNo hay turnos para el dia de hoy");
		}
		printf("\n\n\n\t\t\t");system("pause");system("cls");
	}	
	fclose(arch);
}
void opcion3(int matr)
{
	system("cls");
	int v;
	FILE *arch;
	Turnos x;
	arch=fopen("Turnos.dat","rb");
	int dni_atender;
	if(arch==NULL)
	{
		printf("\n\t\t\tNo hay turnos registrados...");
		printf("\n\n\n\t\t\t");system("pause");system("cls");
	}
	else
	{
		system("CLS");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\t     Registra Evolucion de mascota         \n");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\tIngrese el DNI del paciente a atender:");
		scanf("%d",&dni_atender);
		rewind(arch);
		v=0;
		fread(&x,sizeof(Turnos),1,arch);
		while(!feof(arch))
		{
			if(dni_atender==x.DNI_Dueno)
			{
				printf("\n\t\t\tDiagnostico:");
				_flushall();
				printf("\n\t\t\t");
				gets(x.diagnostico);
				x.borrado=true;
				fseek(arch,-sizeof(Turnos),SEEK_CUR);
				fwrite(&x,sizeof(Turnos),1,arch);
				v=1;	
				fread(&x,sizeof(Turnos),1,arch);
			}
			fread(&x,sizeof(Turnos),1,arch);
			printf("\n\n\n\t\t\t");system("pause");system("cls");
		}
		if(v==0)
		{
			printf("\n\t\t\tIngrese un dni valido...");	
			printf("\n\t\t\tConsulte el listado de turnos del dia...");
			printf("\n\n\n\t\t\t");system("pause");system("cls");
		}	
	}
	fclose(arch);	
}
