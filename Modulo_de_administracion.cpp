#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

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
struct fecha
{
	int dia,mes,year;
};
struct turnos
{
	int matricula_vet;
	fecha fec;
	int DNI_dueno;
	char detalle_atencion[380];	
};
struct ranking
{
	char nombre[60];
	int matricula;
	int atenciones;
};
int menuprincipal();
int usuario_(users z,int tipo);
int pass_(users z);
void opcion1();
void opcion2();
void opcion3();
void ordenar_mostrar(ranking atenc[20],int n);
void opcion4();

void prueba()
{
	turnos x;
	FILE *arch;
	arch=fopen("Turnos.dat","wb");
	
	x.DNI_dueno=1;
	x.matricula_vet=789;
	strcpy(x.detalle_atencion,"Todo bien");
	x.fec.dia=10;x.fec.mes=12;x.fec.year=2020;
	fwrite(&x,sizeof(turnos),1,arch);
	
	x.DNI_dueno=2;
	x.matricula_vet=456;
	strcpy(x.detalle_atencion,"Todo ok");
	x.fec.dia=10;x.fec.mes=12;x.fec.year=2020;
	fwrite(&x,sizeof(turnos),1,arch);
	
	x.DNI_dueno=3;
	x.matricula_vet=789;
	strcpy(x.detalle_atencion,"Todo bien");
	x.fec.dia=10;x.fec.mes=12;x.fec.year=2020;
	fwrite(&x,sizeof(turnos),1,arch);
	
	x.DNI_dueno=4;
	x.matricula_vet=123;
	strcpy(x.detalle_atencion,"Todo bien");
	x.fec.dia=10;x.fec.mes=12;x.fec.year=2020;
	fwrite(&x,sizeof(turnos),1,arch);
	fclose(arch);
}
void listar_veterinarios()
{
	FILE *arch;
	veterinario x;
	int i=0;
	arch=fopen("Veterinarios.dat","rb");
	rewind(arch);
	fread(&x,sizeof(veterinario),1,arch);
	while(!feof(arch))
	{
		if(i==0)
		{
			system("CLS");
			printf("");
			printf("\n\t\t\t=========================================\n");
			printf("\n\t\t\tCONTROL DE DATOS DE VETERINARIO          \n");
			printf("\n\t\t\t=========================================\n");			
		}	
		printf("\n\t\t\tNombre: %s\n",x.nombre);
		printf("\n\t\t\tUsuario: %s           \n",x.usuario);
		printf("\n\t\t\tContrase%ca: %s           \n",164,x.pass);
		printf("\n\t\t\tMatricula: %d           \n",x.matricula);
		printf("\n\t\t\tDNI: %d           \n",x.dni);
		printf("\n\t\t\t=========================================\n");
		fread(&x,sizeof(veterinario),1,arch);
		i++;
	}
	printf("\n\n\n\t");system("pause");system("cls");	
}
void listar_users()
{
	FILE *arch;
	users x;
	int i=0;
	arch=fopen("Usuario.dat","rb");
	rewind(arch);
	fread(&x,sizeof(users),1,arch);
	while(!feof(arch))
	{
		if(i==0)
		{
			system("CLS");
			printf("");
			printf("\n\t\t\t=========================================\n");
			printf("\n\t\t\tCONTROL DE DATOS DE Usuarios de admin.          \n");
			printf("\n\t\t\t=========================================\n");			
		}	
		printf("\n\t\t\tnombre: %s\n",x.nombre);
		printf("\n\t\t\tUsuario: %s           \n",x.usuario);
		printf("\n\t\t\tContrase%ca: %s           \n",164,x.pass);
/*		printf("\n\t\t\tMatricula: %d           \n",x.matricula);
		printf("\n\t\t\tDNI: %d           \n",x.dni);*/
		printf("\n\t\t\t=========================================\n");
		fread(&x,sizeof(users),1,arch);
		i++;
	}
	printf("\n\n\n\t");system("pause");system("cls");	
}
main()
{
	int opcion=0;
	
	do
	{
		opcion=menuprincipal();
		switch(opcion)
		{
			case 1:
				opcion1();//registrar Veterinario
				break;
			case 2:
				opcion2();//registrar usuario de administracion
				break;
			case 3:
				opcion3();//Atenciones por veterinarios
				break;
			case 4:
				opcion4();//Ranking de veterinarios por atenciones realizadas
				break;
			case 1521:
				listar_veterinarios();//Control de datos de veterinarios
				listar_users();//control de datos de usuarios de adm.
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
	printf("\n\t\t\t        Modulo de Administracion          \n");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t 1.- Registrar Veterinario.    \n");
	printf("\n\t\t\t 2.- Registrar Usuario Asistente. \n");
	printf("\n\t\t\t 3.- Atenciones por Veterinarios. \n");
	printf("\n\t\t\t 4.- Ranking de Veterinarios por Atenciones.      \n\n");
	printf("\n\t\t\t 0.- Salir del programa.               \n");
	printf("\n\t\t\t ======================================\n");
	printf("\n\t\t\t    Ingrese su Opcion ...: "); scanf(" %d",&opcion);
	return opcion;
}
int usuario_(users z,int tipo)
{
	int size,may=0,num=0,i,b=0;
	users aux;
	FILE *arch;
	if(tipo=1)
	{
		arch=fopen("Veterinario.dat","rb");	
	}
	if(tipo=2)
	{
		arch=fopen("Usuario.dat","rb");	
	}
	rewind(arch);
	//inciso a
	if(arch==NULL)
	{
		printf("error");
	}
	else
	{
		printf("error");
		fread(&aux,sizeof(veterinario),1,arch);
		while(!feof(arch))
		{
			if(strcmp(z.usuario,aux.usuario)==0)
			{
				printf("\n\t\t\tIngrese otro nombre de usuario\n");
				printf("\n\t\t\tEste ya se encuentra en uso\n");
				printf("\n\n\n\t");system("pause");system("cls");
				return 1;
			}
			fread(&aux,sizeof(veterinario),1,arch);
		}
	}
	//tamaño
	size=strlen(z.usuario);
	if(size>10 or size<6)
	{
		fread(&aux,sizeof(veterinario),1,arch);
		printf("\n\t\t\tIngrese otro nombre de usuario\n");
		printf("\n\t\t\tEl usuario debe tener minimo 6 caracteres y maximo de 10...\n");
		printf("\n\n\n\t");system("pause");system("cls");
		return 1;
	}
	//inciso b
	if(z.usuario[0]>122 or z.usuario[0]<97)
	{
		fread(&aux,sizeof(veterinario),1,arch);
		printf("\n\t\t\tIngrese otro nombre de usuario\n");
		printf("\n\t\t\tEl usuario debe comenzar con una minuscula\n");
		printf("\n\n\n\t");system("pause");system("cls");
		return 1;
	}
	//inciso c
	for(i=0;i<size;i++)
	{
		fread(&aux,sizeof(veterinario),1,arch);
		if(z.usuario[i]>64 and z.usuario[i]<91)
		{	
			may++;
		}	
	}
	if(may<2)
	{
		fread(&aux,sizeof(veterinario),1,arch);
		printf("\n\t\t\tIngrese otro nombre de usuario\n");
		printf("\n\t\t\tEl usuario debe tener minimo 2 letras mayusculas\n");
		printf("\n\n\n\t");system("pause");system("cls");
		return 1;
	}
	//inciso d
	for(i=0;i<size;i++)
	{
		fread(&aux,sizeof(veterinario),1,arch);
		if(z.usuario[i]>47 and z.usuario[i]<58)
		{	
			num++;
		}	
	}
	if(num>3)
	{
		fread(&aux,sizeof(veterinario),1,arch);
		printf("\n\t\t\tIngrese otro nombre de usuario\n");
		printf("\n\t\t\tEl usuario debe tener maximo 3 numeros\n");
		printf("\n\n\n\t");system("pause");system("cls");
		return 1;
	}
	fclose(arch);
	return 0;
}
int pass_(users z)
{
	int size,may=0,num=0,min=0,i;
	users aux;
	char auxiliar[11];
	//inciso c
	size=strlen(z.pass);
	if(size>10 or size<6)
	{
		printf("\n\t\t\tIngrese otra contrase%ca\n",164);
		printf("\n\t\t\tLa contrase%ca debe tener minimo 6 caracteres y maximo de 10...\n",164);
		printf("\n\n\n\t");system("pause");system("cls");
		return 1;
	}
	//inciso b
	for(i=0;i<size;i++)
	{
		if((z.pass[i]<65 or z.pass[i]>90) and (z.pass[i]<97 or z.pass[i]>122) and (z.pass[i]<48 or z.pass[i]>57))
		//if(z.pass[i]<65 or z.pass[i]>90 or z.pass[i]<97 or z.pass[i]>122 or z.pass[i]<48 or z.pass[i]>57)
		{	
			printf("\n\t\t\tIngrese otra contrase%ca \n",164);
			printf("\n\t\t\tLa contrase%ca debe ser alfanumerica \n",164);
			printf("\n\n\n\t");system("pause");system("cls");
			return 1;
		}	
	}
	//inciso a
	for(i=0;i<size;i++)
	{
		if(z.pass[i]>64 and z.pass[i]<91)
		{
			may++;
		}
		if(z.pass[i]>96 and z.pass[i]<123)
		{
			min++;
		}
		if(z.pass[i]>47 and z.pass[i]<58)
		{
			num++;
		}	
	}
//	printf("mayus:%d minus:%d num:%d",may,min,num);
	if(may==0 or min==0 or num==0)
	{
		printf("\n\t\t\tIngrese otra contrase%ca \n",164);
		printf("\n\t\t\tLa contrase%ca debe contener al menos una letra mayuscula, una letra minuscula y un numero \n",164);
		printf("\n\n\n\t");system("pause");system("cls");
		return 1;
	}
	//inciso d
	for(i=0;i<size;i++)
	{
		if(z.pass[i]>47 and z.pass[i]<58)
		{
			if((z.pass[i+1]>47 and z.pass[i+1]<58) and (z.pass[i+2]>47 and z.pass[i+2]<58) and (z.pass[i+3]>47 and z.pass[i+3]<58) )
			{
				printf("\n\t\t\tIngrese otra contrase%ca \n",164);
				printf("\n\t\t\tLa contrase%ca no debe tener mas de 3 numeros consecutivos \n",164);
				printf("\n\n\n\t");system("pause");system("cls");
				return 1;	
			}
		}	
	}
	//inciso e
	strcpy(auxiliar,z.pass);
	strupr(auxiliar);
	for(i=0;i<size;i++)
	{
		if(auxiliar[i]>64 and auxiliar[i]<91)
		{
			if(auxiliar[i+1]==(auxiliar[i]+1))
			{
				printf("\n\t\t\tIngrese otra contrase%ca \n",164);
				printf("\n\t\t\tNo debe tener 2 caracteres consecutivos que refieran a letras alfabeticas \n");
				printf("\n\n\n\t");system("pause");system("cls");
				return 1;	
			}
		}
	}

	return 0;
}

void opcion1()
{
	users x;
	veterinario regis;
	int b=1,tipo=1;
	system("CLS");
	printf("");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t        Registrar Veterinario          \n");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\tIngrese el Nombre y Apellido:\n");
	_flushall();
	printf("\n\t\t\t");
	gets(x.nombre);
	do
	{
		system("CLS");
		printf("");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\t        Registrar Veterinario          \n");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\tIngrese el nombre de usuario :\n");
		_flushall();
		printf("\n\t\t\t");
		gets(x.usuario);
		b=usuario_(x,tipo);
	}while(b==1);
	do
	{
		system("CLS");
		printf("");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\t        Registrar Veterinario          \n");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\tIngrese la contrase%ca :\n",164);
		_flushall();
		printf("\n\t\t\t");
		gets(x.pass);
		b=pass_(x);
	}while(b==1);
	strcpy(regis.nombre,x.nombre);
	strcpy(regis.usuario,x.usuario);
	strcpy(regis.pass,x.pass);
	system("CLS");
	printf("");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t        Registrar Veterinario          \n");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\tIngrese la matricula :\n");
	_flushall();
	printf("\n\t\t\t");
	scanf("%d",&regis.matricula);
	system("CLS");
	printf("");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t        Registrar Veterinario          \n");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\tIngrese el dni:\n");
	printf("\n\t\t\t");
	scanf("%d",&regis.dni);
	system("CLS");
	printf("");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t        Registrar Veterinario          \n");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\tIngrese el numero de telefono :\n");
	printf("\n\t\t\t");
	scanf("%d",&regis.telefono);	
	FILE *arch;
	arch=fopen("Veterinarios.dat","a+b");
	fwrite(&regis,sizeof(veterinario),1,arch);
	fclose(arch);  
}
void opcion2()
{
	users x;int tipo=2;
	int b=1;
	system("CLS");
	printf("");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t      Registrar Usuario Asistente          \n");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\tIngrese el Nombre y Apellido:\n");
	_flushall();
	printf("\n\t\t\t");
	gets(x.nombre);
	do
	{
		system("CLS");
		printf("");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\t      Registrar Usuario Asistente          \n");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\tIngrese el nombre de usuario :\n");
		_flushall();
		printf("\n\t\t\t");
		gets(x.usuario);
		
		b=usuario_(x,tipo);
	}while(b==1);
	do
	{
		system("CLS");
		printf("");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\t      Registrar Usuario Asistente          \n");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\tIngrese la contrase%ca :\n",164);
		_flushall();
		printf("\n\t\t\t");
		gets(x.pass);
		b=pass_(x);
	}while(b==1);
	FILE *arch;
	arch=fopen("Usuario.dat","a+b");
	fwrite(&x,sizeof(users),1,arch);
	fclose(arch);  
}
void opcion3()
{
	prueba();
	turnos x;
	FILE *arch;
	arch=fopen("Turnos.dat","rb");
	if(arch==NULL)
	{
		system("CLS");
		printf("");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\t      No hay atenciones registradas          \n");
		printf("\n\t\t\t=======================================\n");	
		printf("\n\n\n\t");system("pause");system("cls");	
	}
	else
	{
		int matr,b=0;
		system("CLS");
		printf("");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\t      Atenciones por Veterinarios          \n");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\tIngrese la matricula del veterinario :\n");
		printf("\n\t\t\t");
		scanf("%d",&matr);
		system("CLS");
		rewind(arch),
		fread(&x,sizeof(turnos),1,arch);
		while(!feof(arch))
		{
			if(matr==x.matricula_vet)
			{
				b++;
				if(b==1)
				{
					printf("\n\t\t\t=======================================\n");
					printf("\n\t\t\t      Atenciones por Veterinario          \n");
					printf("\n\t\t\t      Matricula:%d          \n",matr);
					printf("\n\t\t\t=======================================\n");	
				}
				printf("\n\t\t\tDNI due%co de la mascota:%d\n",164,x.DNI_dueno);
				printf("\n\t\t\tFecha:%d/%d/%d \n",x.fec.dia,x.fec.mes,x.fec.year);
				printf("\n\t\t\t=======================================\n");
				
			}
			fread(&x,sizeof(turnos),1,arch);
		}
		if(b==0)
		{
			system("CLS");
			printf("");
			printf("\n\t\t\t=======================================\n");
			printf("\n\t\t\t      No hay atenciones registradas          \n");
			printf("\n\t\t\t=======================================\n");
			printf("\n\n\n\t");system("pause");system("cls");	
		}
		else
		{
			printf("\n\n\n\t");system("pause");system("cls");	
		}
	}
	
}

void ordenar_mostrar(ranking atenc[20],int n)
{
	int i,b=0;
	ranking aux;
	do
	{
		b=0;
		for(i=0;i<n;i++)
		{
			if(atenc[i].atenciones<atenc[i+1].atenciones)
			{
				aux=atenc[i];
				atenc[i]=atenc[i+1];
				atenc[i+1]=aux;
				b=1;
			}
		}	
	}while(b==1);
	system("CLS");
	printf("");
	printf("\n\t\t\t=========================================\n");
	printf("\n\t\t\t Ranking de Veterinarios por Atenciones          \n");
	printf("\n\t\t\t=========================================\n");
	for(i=0;i<n;i++)
	{
		printf("\n\t\t\t%d) %s           \n",i+1,atenc[i].nombre);
		printf("\n\t\t\tAtenciones: %d           \n",atenc[i].atenciones);
		printf("\n\t\t\tmatricula: %d           \n",atenc[i].matricula);
		printf("\n\t\t\t=========================================\n");
	}
	printf("\n\n\n\t");system("pause");system("cls");	
}
void opcion4()
{
	
	veterinario x;turnos z;ranking atenc[20];
	FILE *veter,*att;
	int contador=0,i=0;
	veter=fopen("Veterinarios.dat","rb");
	if(veter==NULL)
	{
		system("CLS");
		printf("");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\t     No hay Veterinarios registrados          \n");
		printf("\n\t\t\t=======================================\n");
		printf("\n\n\n\t");system("pause");system("cls");
	}
	else
	{
		att=fopen("Turnos.dat","rb");
		if(att==NULL)
		{
			system("CLS");
			printf("");
			printf("\n\t\t\t=======================================\n");
			printf("\n\t\t\t      No hay atenciones registradas          \n");
			printf("\n\t\t\t=======================================\n");
			printf("\n\n\n\t");system("pause");system("cls");
		}
		else
		{
			fread(&x,sizeof(veterinario),1,veter);
			while(!feof(veter))
			{
				contador=0;
				rewind(att);
				fread(&z,sizeof(turnos),1,att);
				while(!feof(att))
				{
					if(x.matricula==z.matricula_vet)
					{
						contador++;
					}
					fread(&z,sizeof(turnos),1,att);
				}
				atenc[i].atenciones=contador;
				atenc[i].matricula=x.matricula;
				strcpy(atenc[i].nombre,x.nombre);
				i++;
				fread(&x,sizeof(veterinario),1,veter);	
			}	
		}
	}
	fclose(veter);
	fclose(att);
	ordenar_mostrar(atenc,i);
}

