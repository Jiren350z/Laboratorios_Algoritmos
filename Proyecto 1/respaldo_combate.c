
/*
printf("Turno del jugador\n");
			printf("Que quieres hacer?\n");
			printf("opcion 1: atacar\n");
			printf("opcion 2: defender\n");
			scanf("%d",&op);
			//ataque
			if(op==1)
			{
				if(player!=NULL)
				{
					dado = getRollResult();
					printf("Resultado del lanzamiento de dados: %d\n",dado);
					Ataque(player,oponente,dado);	
				}
				if(seleccionado!=NULL)
				{
					dado = getRollResult();
					printf("Resultado del lanzamiento de dados: %d\n",dado);
					Ataque(seleccionado,oponente,dado);		
				}

			}
			//defensa
			if(op==2)
			{
				if(player!=NULL)
				{
					dado = getRollResult();
					printf("Resultado del lanzamiento de dados: %d\n",dado);
					Defensa(player,dado);		
				}
				if(seleccionado!=NULL)
				{
					dado = getRollResult();
					printf("Resultado del lanzamiento de dados: %d\n",dado);
					Defensa(seleccionado,dado);	
				}		
			}
			
			printf("turno del rival\n");
			printf("rival: %s",oponente->nombre);
			srand(time(NULL));
			int randop=0;
			randop=rand()%2+1;
			if(randop==1)
			{
				if(player!=NULL)
				{
				dado_rival = getRollResult();
				printf("Resultado del lanzamiento de dados: %d\n",dado_rival);
				Ataque(oponente,player,dado_rival);
				}
				if(seleccionado!=NULL)
				{
				dado_rival = getRollResult();
				printf("Resultado del lanzamiento de dados: %d\n",dado_rival);
				Ataque(oponente,seleccionado,dado_rival);
				}
			}
			if(randop==2)
			{
				dado_rival = getRollResult();
				printf("Resultado del lanzamiento de dados: %d\n",dado_rival);
				Defensa(oponente,dado_rival);
			}
			if(oponente->vida==0)
			{
				i++;
				sacar_personaje(&headRef,oponente->nombre);
			}
			if(seleccionado->vida == 0)
			{
				printf("has perdido\n");
				sacar_personaje(&headRef,seleccionado->nombre);
			}
			if(player->vida == 0)
			{
				printf("has perdido\n");
				sacar_personaje(&headRef,player->nombre);
			}
		}
	}
	
		
		
			printf("Turno del jugador\n");
			printf("Que quieres hacer?\n");
			printf("opcion 1: atacar\n");
			printf("opcion 2: defender\n");
			scanf("%d",&op);
			//ataque
			if(op==1)
			{
				if(player!=NULL)
				{
					dado = getRollResult();
					printf("Resultado del lanzamiento de dados: %d\n",dado);
					Ataque(player,oponente,dado);	
				}
				if(seleccionado!=NULL)
				{
					dado = getRollResult();
					printf("Resultado del lanzamiento de dados: %d\n",dado);
					Ataque(seleccionado,oponente,dado);		
				}

			}
			//defensa
			if(op==2)
			{
				if(player!=NULL)
				{
					dado = getRollResult();
					printf("Resultado del lanzamiento de dados: %d\n",dado);
					Defensa(player,dado);		
				}
				if(seleccionado!=NULL)
				{
					dado = getRollResult();
					printf("Resultado del lanzamiento de dados: %d\n",dado);
					Defensa(seleccionado,dado);	
				}		
			}
		*/
		
		
		
	//respaldo actual
	//}
		//while(c<riv)
		//{
			
		//}
		
		//while(c<riv)
		//{
		//	c++;
		//	printf("rival: %d\n",c);
		//}
		//seleccionar al azar
		
	//		c++;
	//	}
		/*
		while(c<riv)
		{
			srand(time(NULL));
			int num = rand()%count+1;
			Guardian* rival = oponente;
			rival = headRef;
			for(i=1;i<num;i++)
			{
				rival=rival->next;
			}
			printf("rival al azar es: %s\n",rival->nombre);
			printf("Tipo: %s\n",rival->tipo);
			printf("Vida: %d\n",rival->vida);
			printf("Ataque: %d\n",rival->ataque);
			printf("Defensa: %d\n",rival->defensa); 
			c++;	
			printf("rival: %d\n",c);
		}
		*/
	//codigo del combate
	//if(riv<contador)
	//{
		
	//}
/*	while(i<contador)
	{
		while(player->vida>0 && seleccionado->vida>0)
		{
			printf("Turno del jugador\n");
			printf("Que quieres hacer?\n");
			printf("opcion 1: atacar\n");
			printf("opcion 2: defender\n");
			scanf("%d",&op);
			//ataque
			if(op==1)
			{
				if(player!=NULL)
				{
					dado = getRollResult();
					printf("Resultado del lanzamiento de dados: %d\n",dado);
					Ataque(player,oponente,dado);	
				}
				if(seleccionado!=NULL)
				{
					dado = getRollResult();
					printf("Resultado del lanzamiento de dados: %d\n",dado);
					Ataque(seleccionado,oponente,dado);		
				}

			}
			//defensa
			if(op==2)
			{
				if(player!=NULL)
				{
					dado = getRollResult();
					printf("Resultado del lanzamiento de dados: %d\n",dado);
					Defensa(player,dado);		
				}
				if(seleccionado!=NULL)
				{
					dado = getRollResult();
					printf("Resultado del lanzamiento de dados: %d\n",dado);
					Defensa(seleccionado,dado);	
				}		
			}
			
			printf("turno del rival\n");
			printf("rival: %s",oponente->nombre);
			srand(time(NULL));
			int randop=0;
			randop=rand()%2+1;
			if(randop==1)
			{
				if(player!=NULL)
				{
				dado_rival = getRollResult();
				printf("Resultado del lanzamiento de dados: %d\n",dado_rival);
				Ataque(oponente,player,dado_rival);
				}
				if(seleccionado!=NULL)
				{
				dado_rival = getRollResult();
				printf("Resultado del lanzamiento de dados: %d\n",dado_rival);
				Ataque(oponente,seleccionado,dado_rival);
				}
			}
			if(randop==2)
			{
				dado_rival = getRollResult();
				printf("Resultado del lanzamiento de dados: %d\n",dado_rival);
				Defensa(oponente,dado_rival);
			}
			if(oponente->vida==0)
			{
				i++;
				sacar_personaje(&headRef,oponente->nombre);
			}
			if(seleccionado->vida == 0)
			{
				printf("has perdido\n");
				sacar_personaje(&headRef,seleccionado->nombre);
			}
			if(player->vida == 0)
			{
				printf("has perdido\n");
				sacar_personaje(&headRef,player->nombre);
			}
		}
	}
	*/
		//Guardian *rival = headRef;  
		//while(rival)
		//{
		//	printf("nombre del rival: %s\n",rival->nombre);
		//	printf("tipo del rival: %s\n",rival->tipo);
		//	printf("vida del rival: %d\n",rival->vida);
		//	printf("ataque del rival: %d\n",rival->ataque);
		//	printf("defensa del rival: %d\n",rival->defensa);
		//	rival = rival->next;
		//	printf("----------------------------------------------\n");
		//}
		
		/*	printf("Turno del jugador\n");
			printf("Que quieres hacer?\n");
			printf("opcion 1: atacar\n");
			printf("opcion 2: defender\n");
			scanf("%d",&op);
			//ataque
			if(op==1)
			{
				if(player!=NULL)
				{
					dado = getRollResult();
					printf("Resultado del lanzamiento de dados: %d\n",dado);
					Ataque(player,oponente,dado);	
				}
				if(seleccionado!=NULL)
				{
					dado = getRollResult();
					printf("Resultado del lanzamiento de dados: %d\n",dado);
					Ataque(seleccionado,oponente,dado);		
				}

			}
			//defensa
			if(op==2)
			{
				if(player!=NULL)
				{
					dado = getRollResult();
					printf("Resultado del lanzamiento de dados: %d\n",dado);
					Defensa(player,dado);		
				}
				if(seleccionado!=NULL)
				{
					dado = getRollResult();
					printf("Resultado del lanzamiento de dados: %d\n",dado);
					Defensa(seleccionado,dado);	
				}		
			}
		*/	
		
		
		
		
		
		
		
		
		
		
		
		
		
