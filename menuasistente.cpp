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
	char detalle_atencion[380];
	bool borrado;
};
struct users
{
	char usuario[20];
	char pass[20];
	char nombre[60];
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

int menuasistente();
void inicio(int &b);
void mascot();
void turno();
void rank();


main()
{
	mascota m;
	Turnos v[100];
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
	arch=fopen("mascotas.dat","a+b");
	
	
	_flushall();
	printf("\nNombre de la Mascota: ");
	gets(m.ApeyNom);
	_flushall();
	printf("\nDomicilio: ");
	gets(m.Domicilio);
	printf("\nDNI: ");
	scanf("%d",&m.DNI_Dueno);
	_flushall();
	printf("\nLocalidad: ");
	gets(m.localidad);
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
	fwrite(&m,sizeof(mascota),1,arch);
	fclose(arch);
}

void turno()
{
	FILE *arch,*att;
	mascota m;
	Turnos z;
	int i=0,b=0;
	system("CLS");
	printf("");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t      Registro de Turnos          \n");
	printf("\n\t\t\t=======================================\n");
	
	printf("\n\t\t\t");
	arch=fopen("mascotas.dat","rb");
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
			while(feof(arch))
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
		fwrite(&z,sizeof(Turnos),1,att);
		fclose(arch);
		fclose(att);
	}
}

void rank()
{
	FILE *att,*arch;
	veterinario vet;
	Turnos z;
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
			_flushall();
			printf("\nIngrese la matricula del veterinario a buscar: ");
			scanf("%d",&matricula);		
			rewind(arch);
			fread(&vet,sizeof(veterinario),1,att);
			while(!feof(arch))
			{
				if(vet.matricula==z.matricula)
				{
					printf("\nIngrese el mes de las atenciones del veterinario: ");
					scanf("%d",&mess);
					fread(&z,sizeof(Turnos),1,att);
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
						fread(&z,sizeof(Turnos),1,att);
					}
				}
				fread(&vet,sizeof(veterinario),1,att);	
			}		
		}
		if(i==0)
		{
			system("CLS");
			printf("\n\t\t\t=======================================\n");
			printf("\n\t\t\t      EL veterinario no tiene turnos este mes           \n");
			printf("\n\t\t\t=======================================\n");
		}
	}
}

