
int mainLoop()
{
	int x,y,i = 1 ,ataque;
	while(1)
	{
			if(i == 1)
				ataque = 2;
			else
				ataque = 1;
			//print_tablero(i);
			print_tablero_enemigo(ataque);
			printf("Turno de player: %d\n", i);
			while(atacar_barco(ataque))
			{
				//print_tablero(i);
				print_tablero_enemigo(ataque);
				printf("Turno de player: %d\n", i);
				if(!vida[ataque-1])
				{
					printf("El player %d ha perdido\n",ataque);
					getchar();
					system("pause");
					return i;
				}
			}
		if (i == 1)
			i = 2;
		else 
			i = 1;
	}
	return -1;
}
