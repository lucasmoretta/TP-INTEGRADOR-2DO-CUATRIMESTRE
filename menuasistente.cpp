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
void mascot(mascota m);
void turno(Turnos v[100],mascota m);
void rank(veterinario vet,Turnos v[100]);


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
				mascota(m);
				else
				printf("\nInicie sesion para realizar las otras opciones...");
				break;
			case 3:
				if(b==1)
				turno(v,m);
				else
				printf("\nInicie sesion para realizar las otras opciones...");
				break;
			case 4:
				if(b==1)
				rank(vet,v);
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
 	
 	system("CLS");
	printf("");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t      Inicio de sesion Asistente         \n");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t");
	
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

void mascot(mascota m)
{
	FILE *arch;
	
	system("CLS");
	printf("");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t      Registro de Mascota          \n");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t");
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
	printf("\nA%o: ",164);
	scanf("%d",&m.fec.anio);
	
	printf("\nPeso: ");
	scanf("%f",&m.Peso);
	printf("\nTelefono: ");
	scanf("%d",&m.telefono);
	fwrite(&m,sizeof(mascota),1,arch);
	fclose(arch);
}

void turno(Turnos v[100],mascota m)
{
	FILE *arch,att;
	int i=0;
	system("CLS");
	printf("");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t      Registro de Turnos          \n");
	printf("\n\t\t\t=======================================\n");
	
	printf("\n\t\t\t");
	
	att=fopen("Turnos.dat","a+b");
	arch=fopen("mascotas.dat","rb");
	fread(&m,sizeof(mascota),1,arch);
	while(!feof(arch))
	{
		printf("\nIngrese matricula de veterinario: ");
		scanf("%d",&v[i].matricula);
		printf("\nFecha del turno: ");
		printf("\nDia: ");
		scanf("%d",&v[i].fec.dia);
		printf("\nMes: ");
		scanf("%d",&v[i].fec.mes);
		printf("\nA%o: ",164);
		scanf("%d",&v[i].fec.anio);
		
		printf("\nIngrese el DNI del due%o: ",164);
		scanf("%d",&v[i].DNI_Dueno);
		while(m.DNI_Dueno!=v[i].DNI_Dueno)
		{
			printf("\nDNI incorrecto...");
			
			printf("\nIngrese el DNI del due%o: ",164);
			scanf("%d",&v[i].DNI_Dueno);
			fread(&m,sizeof(mascota),1,arch);
		}
		
		_flushall();
		printf("\nDetalles de la atencion: ");
		gets(v[i].detalle_atencion);
		
		i++;
		fwrite(&v,sizeof(Turnos),1,att);
	}
	fclose(att);
	fclose(arch);
}

void rank(veterinario vet,Turnos v[100])
{
	FILE *att,*arch;
	
	char veter[80];
	int mess,i=0;
	
	_flushall();
	printf("\nIngrese el nombre de veterinario a buscar: ");
	gets(veter);
	
	att=fopen("Turnos.dat","rb");
	arch=fopen("Veterinarios.dat","rb");
	
	fread(&vet,sizeof(veterinario),1,att)
	
	while(!feof(arch))
	{
		if(strcmp(vet.nombre,veter)==0)
		{
			printf("\nIngrese el mes de las atenciones del veterinario: ");
			scanf("%d",&mess);
			
			fread(&v,sizeof(Turnos),1,att);
			if(v[i].fec.mes==mess)
			{
				_flushall();
				printf("\nNombre del Veterinario: ");
				puts(vet.nombre);
				printf("\nMatricula: %d",vet.matricula);
				
				printf("\nTurnos en la fecha de %d/%d/%d",v[i].fec.dia,v[i].fec.mes,v[i].fec.anio);
				printf("\nDNI del dueño: %d",v[i].DNI_Dueno);
				_flushall();
				printf("\nDetalle de atencion: ");
				printf("\n");
				puts(v[i].detalle_atencion);
			}
			i++;
		}
		
	}
}

