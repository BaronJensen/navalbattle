#include "init.h"



int main(int argc, char const *argv[])
{
	int i,winner;
	
	clean_matrix();//Se limpia el tablero
	for (i = 1; i < 3; ++i)
	{
		printf("Ingresar barcos del player %d\n", i );
		print_tablero(i);
		ingresar_Barco(i);
		if(!LINUX)
			system("pause");
	}

	if(winner = mainLoop())
	{
		system("clear");
		printf("\t\t=====Winner: player %d ======\t\t\n GAME OVER BITCHES!\n",winner); 
	}
	return 0;
}