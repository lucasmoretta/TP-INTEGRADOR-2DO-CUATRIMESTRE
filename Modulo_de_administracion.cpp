#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

struct veterinario
{
	char usuario[10];
	char pass[10];
	char nombre[60];
};


int menuprincipal();
int usuario_(veterinario z)
{
	int size,may=0,num=0;
	veterinario aux;
	FILE *arch;
	arch=fopen("Veterinario.dat","rb");
	rewind(arch);
	if(arch==null){};
	else
	{
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
		}
	}
	size=strlen(z.usuario);
	if(size>10 or size<6)
	{
		printf("\n\t\t\tIngrese otro nombre de usuario\n");
		printf("\n\t\t\tEl usuario debe tener minimo 6 caracteres y maximo de 10...\n");
		printf("\n\n\n\t");system("pause");system("cls");
		return 1;
	}
	if(z.usuario[0]>64 or z.usuario[0]<91)
	{
		printf("\n\t\t\tIngrese otro nombre de usuario\n");
		printf("\n\t\t\tEl usuario debe comenzar con una minuscula\n");
		printf("\n\n\n\t");system("pause");system("cls");
		return 1;
	}
	for(i=0;i<size;i++)
	{
		if(z.usuario[i]>64 or z.usuario[i]<91)
		{	
			may++;
		}	
	}
	if(may<2)
	{
		printf("\n\t\t\tIngrese otro nombre de usuario\n");
		printf("\n\t\t\tEl usuario debe tener minimo 2 letras mayusculas\n");
		printf("\n\n\n\t");system("pause");system("cls");
		return 1;
	}
	for(i=0;i<size;i++)
	{
		if(z.usuario[i]>47 or z.usuario[i]<58)
		{	
			num++;
		}	
	}
	if(num>3)
	{
		printf("\n\t\t\tIngrese otro nombre de usuario\n");
		printf("\n\t\t\tEl usuario debe tener maximo 3 numeros\n");
		printf("\n\n\n\t");system("pause");system("cls");
		return 1;
	}
	fclose(arch);
	return 0;
}
int usuario_(veterinario z)
{
	int size,may=0,num=0;
	veterinario aux;
	
	size=strlen(z.usuario);
	if(size>10 or size<6)
	{
		printf("\n\t\t\tIngrese otro nombre de usuario\n");
		printf("\n\t\t\tEl usuario debe tener minimo 6 caracteres y maximo de 10...\n");
		printf("\n\n\n\t");system("pause");system("cls");
		return 1;
	}
	if(z.usuario[0]>64 or z.usuario[0]<91)
	{
		printf("\n\t\t\tIngrese otro nombre de usuario\n");
		printf("\n\t\t\tEl usuario debe comenzar con una minuscula\n");
		printf("\n\n\n\t");system("pause");system("cls");
		return 1;
	}
	for(i=0;i<size;i++)
	{
		if(z.usuario[i]>64 or z.usuario[i]<91)
		{	
			may++;
		}	
	}
	if(may<2)
	{
		printf("\n\t\t\tIngrese otro nombre de usuario\n");
		printf("\n\t\t\tEl usuario debe tener minimo 2 letras mayusculas\n");
		printf("\n\n\n\t");system("pause");system("cls");
		return 1;
	}
	for(i=0;i<size;i++)
	{
		if(z.usuario[i]>47 or z.usuario[i]<58)
		{	
			num++;
		}	
	}
	if(num>3)
	{
		printf("\n\t\t\tIngrese otro nombre de usuario\n");
		printf("\n\t\t\tEl usuario debe tener maximo 3 numeros\n");
		printf("\n\n\n\t");system("pause");system("cls");
		return 1;
	}
	return 0;
}

void opcion1()
{
	//FILE *arch;
	//arch=fopen("Veterinarios.dat","a+b"); rb   
	veterinario x;
	int b=1;
	system("CLS");
	printf("");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\t        Registrar Veterinario          \n");
	printf("\n\t\t\t=======================================\n");
	printf("\n\t\t\tIngrese el Nombre y Apellido:\n");
	cin.getline(x.nombre,60,'\n');
	do
	{
		system("CLS");
		printf("");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\t        Registrar Veterinario          \n");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\tIngrese el nombre de usuario :\n");
		cin.getline(x.usuario,10,'\n');
		b=usuario_(x);
	}while(b=1);
	do
	{
		system("CLS");
		printf("");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\t        Registrar Veterinario          \n");
		printf("\n\t\t\t=======================================\n");
		printf("\n\t\t\tIngrese la contrase%ca :\n",164);
		cin.getline(x.pass,10,'\n');
		b=pass_(x);
	}while(b=1);
	
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
		//		opcion2();//registrar usuario de administracion
				break;
			case 3:
		//		opcion3();//
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


