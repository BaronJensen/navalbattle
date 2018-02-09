/*Funciones principales*/

void print_tablero(int );//Imprime todo el tablero
void print_tablero_enemigo(int );//Muestra el tablero del enemigo con tus ataques y sus barcos ocultos
	int convert_char(int ,int );//Cambia los iconos que se veran en la impresion final
void clean_matrix();//Limpia la matiz
void ingresar_Barco(int );//Ingresa barco a partir de una pociocion inicial y usa fill_barco_*() para terminar de rellenar
	void fill_barco_horizontal(int , int ,int , int );//Rellena la amtriz con un barco horizontalmete
	void fill_barco_vertical(int , int ,int , int );//Rellena --- verticalmente
		int  colision_h(int ,int ,int ,int );//analiza si ya existe un barco en la posicion h
		int  colision_v(int ,int ,int ,int );//analiza si ya existe un barco en la posicion v
int atacar_barco( int );//Permite atacar a un barco enemigo
int char_to_XY(int );//Convierte un char A,B,C,a,b,c,1,2,3 en un entere que se usara como coordenada

/*
====================================================================================================
Desarollado por Jensen Baronville 2016 ®Todo los derechos reservados
-Detalles de version v0.6

Futuras actualizaciones:
-Menu principal
-Imprimir el nombre del barco segun su tamaño
-Guardar partida
-Multijugador LAN

*/




int atacar_barco( int player_atacado)
{
	char y_c;
	int x,y,add = 0;
	int return_v = 0;
	int player = 1;

	if (player_atacado == 1)
		player = 2;
	else
		add = SIZE;


		
	printf("Ingresar coordenada de ataque: \n");
	scanf("%d",&x);
	x--;
	scanf("%c",&y_c);
	y = char_to_XY((int) y_c);
	y--;


	//Condiciones de ataque
	if(TABLERO[x+add][y+add] == 0)
		printf("Misil perdido atacando al player: %d\n",player_atacado);
	else if(TABLERO[x+add][y+add] == player_atacado)
	{
		printf("Has atacado el barco del player: %d\n",player_atacado);
		TABLERO[x+add][y+add] = player;
		vida[player_atacado-1]--;
		return_v = 1;
	}
		if(!LINUX)
			system("pause");
return return_v;	
}

int char_to_XY(int y)
{
	if (y > 64 && y < 90)
		y -=64;
	else if(y > 96)
		y -= 96;
	else
		y -=47;
return y;
}

int convert_char(int val,int ataque)
{
	switch (val)
	{
		case 0:
			val = 177;
		break;
		case 1:
		case 2:
			if (!ataque)
			val = 17;
			else
			val = 270;
		break;

	}
	return val;
}





void print_tablero(int player)
{
	if(LINUX)
	system("clear");
	else
	system("cls");

	int i,j;

	printf("\tBatalla naval by Jensen Baronville \n=====================================================\n");
	printf("\tPlayer :%d \tVida restante:%d \n---------------------------------------------------\n", player,vida[player-1]);

	printf("\t\t");
	for ( i = 0; i < SIZE; ++i)
	{
		printf("  %c", i+65);
	}
	printf("\n \n \n");

	for ( i = 0; i < SIZE; ++i)
	{
		printf("\t%d\t", i+1);
		for ( j = 0; j < SIZE; ++j)
		{
			if (player == 2 )
				printf("  %c",convert_char(TABLERO[i+SIZE][j+SIZE],0));
			else
				printf("  %c",convert_char(TABLERO[i][j],0));

		}

		printf("\t\t %d", i+1);	
		printf("\n");
	}
		
}




void print_tablero_enemigo(int player)
{
	if(LINUX)
	system("clear");
	else
	system("cls");
	int i,j,tmp;

	int player_c = 1;

	if (player == 1)
		player_c = 2;

	
	
	printf("\tBatalla naval by Jensen Baronville \n=====================================================\n");
	printf("\tPlayer :%d \tVida restante:%d \n---------------------------------------------------\n", player_c,vida[player_c-1]);

	printf("\n\n\n\t\t+++++++Mapa enemigo+++++\n");
	printf("\n\n");
	printf("\t\t");
	for ( i = 0; i < SIZE; ++i)
	{
		printf("  %c", i+65);
	}
	printf("\n \n \n");
	for ( i = 0; i < SIZE; ++i)
	{
		printf("\t%d\t", i+1);
		for ( j = 0; j < SIZE; ++j)
		{
			if (player == 2 )
			{
				if (TABLERO[i+SIZE][j+SIZE] == player)
					printf("  %c",177); 
				else
				printf("  %c",convert_char(TABLERO[i+SIZE][j+SIZE],1));
			}
			else
			{
				if (TABLERO[i][j] == player)
						printf("  %c",177); 
				else
				printf("  %c",convert_char(TABLERO[i][j],1));
			}

		}

		printf("\t\t %d", i+1);
		printf("\n");

	}
	printf("\n \n ");
	printf("\t\t");
	for ( i = 0; i < SIZE; ++i)
	{
		printf("  %c", i+65);
	}
	
		printf("\t\n=====================================================\n");
}




void ingresar_Barco(int player)
{
	int i;
	int x = 0;
	int y = 0;
	int h = 0;
	char y_c;
	
	 for (i = 0; i < BARCOS; ++i)
	 {
		printf("Ingresar popa: \n");
		scanf("%d",&x);
		y_c = getc(stdin);
		y = char_to_XY(y_c);
		
		printf("1 para poner el barco horizontal y 2 para poner el barco en vertical : \n");
		scanf("%d",&h);
	 	switch (h)
	 	{

		 	case 1:
		 		fill_barco_horizontal(player,x,y,barco[i]);
		 		break;
		 	case 2:
		 		fill_barco_vertical(player,x,y,barco[i]);
		 		break;
		 	default:
		 		break;
		}
	 }
	

}





void clean_matrix()
{
	int i,j;
	for ( i = 0; i < SIZE*2; ++i)
		for ( j = 0; j < SIZE*2; ++j)
			TABLERO[i][j] = 0;
}

void fill_barco_horizontal(int player, int x,int y, int size)
{
	int i;
	
	while ((y + size) > 10 || colision_h(player,x,y,size))
	{

		printf("Error, la posicion ingesada esta fuera del mapa. Intenta de nuevo:%d %d\n",x, size );
		scanf("%d",&x);
		scanf("%d",&y);
		
	}

	for ( i = 0; i < size; ++i)
		if (player == 2 )
				TABLERO[(x-1)+SIZE][(y-1)+SIZE+i] = player;
			else
				TABLERO[(x-1)][(y-1)+i] = player;
	print_tablero(player);
	printf("Barco tamaño %d guardado con exito\n", size);



}

void fill_barco_vertical(int player, int x,int y, int size)
{
	int i;
	
	while ((x + size) > 10 || colision_v(player,x,y,size))
	{
		printf("Error, la posicion ingesada esta fuera del mapa o sobre barco. Intenta de nuevo:\n");
		scanf("%d",&x);
		scanf("%d",&y);
	}
	for ( i = 0; i < size; ++i)
		if (player == 2 )
				TABLERO[(x-1)+SIZE+i][(y-1)+SIZE] = player;
			else
				TABLERO[(x-1)+i][(y-1)] = player;

				
	print_tablero(player);
	printf("Barco tamaño %d guardado con exito\n", size);

}



int  colision_h(int player,int x,int y,int size)
{
	int i, add = 0, return_v = 0;
	if (player == 2)
		add = SIZE;
	for ( i = 0; i < size; ++i)
			if (TABLERO[(x-1)+SIZE][(y-1)+SIZE+i])
			{
				return_v = 1;
				break;
			}
				


return return_v;
}

int  colision_v(int player,int x,int y,int size)
{
	int i, add = 0, return_v = 0;
	if (player == 2)
		add = SIZE;
	for ( i = 0; i < size; ++i)
			if (TABLERO[(x-1)+SIZE+i][(y-1)+SIZE])
			{
				return_v = 1;
				break;
			}

return return_v;
}