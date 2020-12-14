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
struct veterinario
{
	char usuario[20];
	char pass[20];
	char nombre[60];
	int matricula;
	int dni;
	int telefono;
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
	char diagnostico[400];
};
struct users
{
	char usuario[20];
	char pass[20];
	char nombre[60];
};

using namespace std;

int menuprincipal();
void inicio(int &b,int &matr);/*
void evolucion_mascota();
void cargar_detalle(Turnos t);
void mostrar_turnos();
bool borrado_turno(FILE * turnos, int DNI_D);*/
void opcion2(int matr)
{
	Fecha hoy;
	FILE *arch;
	Turnos x;
	int dni_atender,i,b;
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
			if(matr==x.matricula and hoy.dia==x.fec.dia and hoy.mes==x.fec.mes and hoy.anio==x.fec.anio)
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
				printf("\n\t\t\tDiagnostico");
				_flushall();
				gets(x.diagnostico);
				x.borrado=true;
				fseek(arch,-sizeof(Turnos),SEEK_CUR);
				fwrite(&x,sizeof(Turnos),1,arch);
				v=1;	
				
			}
			fread(&x,sizeof(Turnos),1,arch);
			printf("%d",x.DNI_Dueno);
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
main()
{
	
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
					printf("\nNo existe el usuario ingresado");
				}
		}while(b!=1);

		do
		{
			b=0;
			rewind(arch);
			_flushall();
			printf("\nIngrese Contrase%ca: ",164);
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
/*
void evolucion_mascota(turnos t)
{
	
	FIlE *arch;
	mascota x;
	
	int DNI_d[60];
//	char [380];
	
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
			
			printf("\n\t\t\tIngrese el DNI del due%co ",164);
			scanf("%d",&DNI_d);
			fread(&x,sizeof(Turnos),1,arch);
			while(!feof(arch))
			{
				if(DNI_d == x.DNI_Dueno)
				{
					b=1;
					_flushall();
					printf("Ingrese el diagnostico de la mascota;");
					gets(x.diagnostico);
					fseek(arch,- sizeof(Turnos),SEEK_CUR);
					fwrite(&x,sizeof(Turnos),1,arch);
				}
				fread(&x,sizeof(Turnos),1,arch);
			}
			if(b==0)
			{
				printf("\n\t\t\tNo se registro ninguna mascota");
			}
			system("cls");
			
		//	cargar_detalle(turnos t);
			//borrado_turnos(turnos t, DNI_d);
				
		}while(b!=1);
		

	}

}*/
/*
void cargar_detalle(turnos t){
	
	FILE * arch
	
	arch = fopen("turnos.dat" , "a+b" );
	
	_flushall();
	printf("Ingrese el diagnostico de la mascota;");
	gets(t.detalle_atencion);
	
}*/
/*
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
				
			}else
			{
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
	
}*/
