#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
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
struct turnos
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

int menuasistente();
void inicio(int &b);
void mascot();
void turno();
void rank();
void listar_mascota()
{
	FILE *arch;
	mascota x;
	int i=0;
	arch=fopen("Mascotas.dat","rb");
	if(arch==NULL)
	{
		//	printf("\n\n\n\t ERROR");system("pause");system("cls");	
	}
	else
	{
		i=0;
		rewind(arch);
		//fread(&x,sizeof(mascota),1,arch);
		while(!feof(arch))
		{
			if(i==0)
			{
				system("CLS");
			//	printf("");
				printf("\n\t\t\t=========================================\n");
				printf("\n\t\t\tCONTROL DE DATOS DE MASCOTAS\n");
				printf("\n\t\t\t=========================================\n");			
			}	
			_flushall();
			printf("\n\t\t\tnombre: %s\n",x.ApeyNom);
			printf("\n\t\t\tdni dueno: %d           \n",x.DNI_Dueno);
			//printf("\n\t\t\tContrase%ca: %s           \n",164,x.pass);
	/*		printf("\n\t\t\tMatricula: %d           \n",x.matricula);
			printf("\n\t\t\tDNI: %d           \n",x.dni);*/
			printf("\n\t\t\t=========================================\n");
			fread(&x,sizeof(mascota),1,arch);
			i++;
		}
		printf("\n\n\n\tFRAN");system("pause");system("cls");	
	}
	
	printf("\n\n\n\t");system("pause");system("cls");	
}
void listar_turnos()
{
	FILE *arch;
	turnos x;
	int i=0;
	arch=fopen("Turnos.dat","rb");
	rewind(arch);
	fread(&x,sizeof(turnos),1,arch);
	while(!feof(arch))
	{
		if(i==0)
		{
			system("CLS");
			printf("");
			printf("\n\t\t\t=========================================\n");
			printf("\n\t\t\tCONTROL DE DATOS DE TURNOS\n");
			printf("\n\t\t\t=========================================\n");			
		}	
		printf("\n\t\t\tmatricula del veterinario: %d\n",x.matricula);
		printf("\n\t\t\tdni dueno: %d           \n",x.DNI_Dueno);
		printf("\n\t\t\tfecha: %d/%d/%d           \n",x.fec.dia,x.fec.mes,x.fec.anio);
		//printf("\n\t\t\tContrase%ca: %s           \n",164,x.pass);
/*		printf("\n\t\t\tMatricula: %d           \n",x.matricula);
		printf("\n\t\t\tDNI: %d           \n",x.dni);*/
		printf("\n\t\t\t=========================================\n");
		fread(&x,sizeof(turnos),1,arch);
		i++;
	}
	printf("\n\n\n\t");system("pause");system("cls");	
}
main()
{
	mascota m;
	turnos v[100];
	veterinario vet;
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
				mascot();
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
				turno();
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
				if(b==1)
				rank();
				else
				{
					system("CLS");
					printf("\n\n\n\t\t\t===================================================\n");
					printf("\n\t\t\t Inicie sesion para realizar las otras opciones...         \n");
					printf("\n\t\t\t===================================================\n");
					printf("\n\n\n\t\t\t");system("pause");system("cls");	
				}
				break;
			case 1521:
				listar_mascota();
				break;
		}
 		
	}while(opcion!=0);
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
	printf("\n\t\t\t 0.- Salir del programa.               \n");
	printf("\n\t\t\t ======================================\n");
	printf("\n\t\t\t    Ingrese su Opcion ...: ");
	printf("\n\n\n\t\t\t");
	scanf(" %d",&opcion);
	return opcion;
}

void inicio(int &b)
{
	FILE *arch;
	users x;
	
	char asist[60];
	char contr[60];
 	
 	system("CLS");
	printf("");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t      Inicio de sesion Asistente         \n");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t");
	
	arch=fopen("Usuario.dat","rb");

	if(arch==NULL)
	{
		printf("\n\t\t\tNo hay usuarios registrados...");
		printf("\n\n\n\t\t\t");system("pause");system("cls");	
	}
	else
	{
		do
		{
			rewind(arch);
			_flushall();
			printf("\n\t\t\t");
			printf("Ingrese Usuario: ");
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
				printf("\n\t\t\t");
				printf("No existe el usuario ingresado");
			}
		}while(b!=1);
		do
		{
			rewind(arch);
			_flushall();
			printf("\n\t\t\t");
			printf("Ingrese Contraseña: ");
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
					printf("\n\t\t\t");
					printf("\nContraseña Incorrecta...");
				}
		
		}while(b!=1);
	}
}

void mascot()
{
	FILE *arch;
	mascota m;
	
	system("CLS");
	printf("");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t      Registro de Mascota          \n");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t");
//	system("pause");
	
	
	
	_flushall();
	printf("\nNombre de la Mascota: ");
	gets(m.ApeyNom);
	_flushall();
	printf("\nDomicilio: ");
	gets(m.Domicilio);
	_flushall();
	printf("\nDNI: ");
	scanf("%d",&m.DNI_Dueno);
	_flushall();
	printf("\nLocalidad: ");
	gets(m.localidad);
	_flushall();
	printf("\nFecha de nacimiento: ");
	printf("\nDia: ");
	scanf("%d",&m.fec.dia);
	printf("\nMes: ");
	scanf("%d",&m.fec.mes);
	printf("\nA%co: ",164);
	scanf("%d",&m.fec.anio);
	
	printf("\nPeso: ");
	scanf("%f",&m.Peso);
	printf("\nTelefono: ");
	scanf("%d",&m.telefono);
	arch=fopen("Mascotas.dat","a+b");
	fwrite(&m,sizeof(mascota),1,arch);	
	
	fclose(arch);
}

void turno()
{
	FILE *arch,*att;
	mascota m;
	turnos z;
	int i=0,b=0;
	system("CLS");
	printf("");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t      Registro de Turnos          \n");
	printf("\n\t\t\t=======================================\n");
	
	printf("\n\t\t\t");
	arch=fopen("Mascotas.dat","rb");
	if(arch==NULL)
	{
		system("CLS");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\t      Primero registre mascotas          \n");
		printf("\n\t\t\t=======================================\n");			
	}
	else
	{
		printf("\nIngrese matricula de veterinario: ");
		scanf("%d",&z.matricula);
		printf("\nFecha del turno: ");
		printf("\nDia: ");
		scanf("%d",&z.fec.dia);
		printf("\nMes: ");
		scanf("%d",&z.fec.mes);
		printf("\nA%co: ",164);
		scanf("%d",&z.fec.anio);
		
		do
		{
			b=0;
			printf("\nIngrese el DNI del due%co: ",164);
			scanf("%d",&z.DNI_Dueno);
			rewind(arch);
			fread(&m,sizeof(mascota),1,arch);
			while(!feof(arch))
			{
				if(z.DNI_Dueno==m.DNI_Dueno)
				{
					b=1;
				}
				fread(&m,sizeof(mascota),1,arch);		
			}
			if(b==0)
			{
				printf("Ingrese un dni valido. . .");
			}
		}while(b==0);
		_flushall();
		printf("\nDetalles de la atencion: ");
		gets(z.detalle_atencion);
		z.borrado=false;
		att=fopen("Turnos.dat","a+b");
		fwrite(&z,sizeof(turnos),1,att);
		fclose(arch);
		fclose(att);
	}
}

void rank()
{
	FILE *att,*arch;
	veterinario vet;
	turnos z;
	char veter[80];
	int mess,i=0,matricula;
	arch=fopen("Veterinarios.dat","rb");
	if(arch==NULL)
	{
		system("CLS");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\t      No hay veterinarios registrados           \n");
		printf("\n\t\t\t=======================================\n");			
	}
	else
	{
		att=fopen("Turnos.dat","rb");
		if(att==NULL)
		{
			system("CLS");
			printf("\n\t\t\t=======================================\n");
			printf("\n\t\t\t      No hay turnos registrados           \n");
			printf("\n\t\t\t=======================================\n");	
		}
		else
		{
			system("cls");
			_flushall();
			printf("\nIngrese la matricula del veterinario a buscar: ");
			scanf("%d",&matricula);		
			rewind(arch);
			fread(&vet,sizeof(veterinario),1,arch);
			while(!feof(arch))
			{
				if(vet.matricula==matricula)
				{
					printf("\nIngrese el mes de las atenciones del veterinario: ");
					scanf("%d",&mess);
					fread(&z,sizeof(turnos),1,att);
					while(!feof(att))
					{
						if(z.fec.mes==mess and z.borrado==false)
						{
							i=1;
							_flushall();
							printf("\nNombre del Veterinario: %s",vet.nombre);
							printf("\nMatricula: %d",vet.matricula);
							printf("\nTurnos en la fecha de %d/%d/%d",z.fec.dia,z.fec.mes,z.fec.anio);
							printf("\nDNI del dueño: %d",z.DNI_Dueno);
							printf("\nDetalle de atencion: %s",z.detalle_atencion);
							printf("\n\t\t\t=======================================\n");
						}
						fread(&z,sizeof(turnos),1,att);
					}
				}
				fread(&vet,sizeof(veterinario),1,arch);	
			}
			printf("\n\n\n\t");system("pause");system("cls");		
		}
		if(i==0)
		{
			system("CLS");
			printf("\n\t\t\t=======================================\n");
			printf("\n\t\t\t      EL veterinario no tiene turnos este mes           \n");
			printf("\n\t\t\t=======================================\n");
				printf("\n\n\n\t");system("pause");system("cls");
		}
	}
}

