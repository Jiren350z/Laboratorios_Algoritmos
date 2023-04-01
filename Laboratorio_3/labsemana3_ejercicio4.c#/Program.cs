using System;

namespace ex4
{
    class Jugador
    {
        //string nombre;
        private string _nombre="";

        private int _salud;

        private int _nivel;

        private int _puntaje;

        private int _ataque;

        private int _defensa;
        
        private int _equipo;

        //Propiedades
        public string Nombre
        {
            get{return this._nombre;}
            set{this._nombre = value;}
        }
        public int Salud 
        {
            get{return this._salud;}
            set{this._salud = value;}
        }
        public int Nivel
        {
            get{return this._nivel;}
            set{this._nivel = value;}
        }
        public int Puntaje 
        {
            get{return this._puntaje;}
            set{this._puntaje = value;}
        }
        public int Ataque  
        {
            get{return this._ataque;}
            set{this._ataque = value;}
        }
        public int Defensa 
        {
            get{return this._defensa;}
            set{this._defensa = value;}
        }
        public int Equipo 
        {
            get{return this._equipo;}
            set{this._equipo = value;}
        }
        //Constructor Por defecto
        public Jugador()
        {
            _nombre = "";
            _salud = 0;
            _nivel = 0;
            _puntaje = 0;
            _ataque = 0;
            _defensa = 0;
            _equipo = 0;
            
        }           
        //constructo por parametros 
        public Jugador( string _nombre, int _salud,int _nivel, int _puntaje, int _ataque, int _defensa, int _equipo)
        {
            this._nombre = Nombre;
            this._salud = Salud;
            this._nivel = Nivel;
            this._puntaje = Puntaje;
            this._ataque = Ataque;
            this._defensa = Defensa;
            this._equipo = Equipo;
        }
        //metodos
    //    public override string ToString()
    //    {
    //        return $"Nombre:{this._nombre} \n Salud:{this._salud} \n Nivel:{this._nivel} Puntaje:{this._puntaje} \n Ataque:{this._ataque} \n Defensa:{this._defensa} \n Equipo:{this._equipo} \n"; 
    //    }


        //random.Next(1,800000), random del puntaje
        class Program
        {
            static int turnoactual = 0;
            static bool gameover = false;
            //Dado de seleccion
            static int LanzarDados() 
            {
            Random rnd = new Random();
            return rnd.Next(1, 7) + rnd.Next(1, 7);
            }
            public static void Main(string[] args)
            {
                Random random = new Random();
                int max=0; //variable que determina el maximo de jugadores
	            int t1=0; //equipo 1
	            int t2=0; //equipo2
	            int es=0; //variable usada para mostrar las estadisticas
                int act=0; //variable usada para actualizar
                int pt1=0; //puntaje total del equipo 1
                int pt2=0; //púntaje total del equipo 2
                int k=0;
                int sel;
                int selr;
                Console.WriteLine("Defina la cantidad de jugadores");
                max=Convert.ToInt32(Console.ReadLine());
                Jugador[] jugadores = new Jugador[10];
                //metodo que determina los datos generales
                for(int i=0;i<max;i++)
                {
                    string nom = " ";
                    Console.WriteLine("Defina el nombre");
                    Console.WriteLine($"Ingrese el nombre del jugador:{i+1}");
                    nom= nom + Console.ReadLine();
                    jugadores[i] = new Jugador
                    {
                    Nombre = nom,
                    Salud = random.Next(1,2100),
                    Nivel = random.Next(1,713),
                    Puntaje = 0,
                    Ataque = random.Next(1,16000),
                    Defensa = random.Next(1,9000),
                    Equipo = random.Next(1,3)
                    };
                    //metodo encargado de balancear los equipos
                    if(jugadores[i].Equipo == 1 )
		            {
			            t1++;
		            }
		            else if(jugadores[i].Equipo == 2)
		            {
			            t2++;
		            }
		            if(t1>max/2) 
		            {
			            jugadores[i].Equipo=2;
		            }
		            else if(t2>max/2)
		            {
			            jugadores[i].Equipo=1;
		            }
                    //metodo encargado de sumar el puntaje obtenido
                    //if(jugadores[i].Equipo==1)
		            //{
			        //    pt1=pt1+jugadores[i].Puntaje;
		            //}
		            //else if(jugadores[i].Equipo==2)
		            //{
			        //    pt2=pt2+jugadores[i].Puntaje;
		            //}
                }
                for(int i=0;i<max;i++)
                {
                    Console.WriteLine($"----------JUGADOR:{i+1}----------");
                    Console.Write("Nombre:");
                    Console.WriteLine(jugadores[i].Nombre);
                    Console.Write("Salud:");
                    Console.WriteLine(jugadores[i].Salud);
                    Console.Write("Nivel:");
                    Console.WriteLine(jugadores[i].Nivel);
                    Console.Write("Puntaje:");
                    Console.WriteLine(jugadores[i].Puntaje);
                    Console.Write("Ataque:");
                    Console.WriteLine(jugadores[i].Ataque);
                    Console.Write("Defensa:");
                    Console.WriteLine(jugadores[i].Defensa);
                    Console.Write("Equipo:");
                    Console.WriteLine(jugadores[i].Equipo);
                }
                Console.WriteLine("---------------------------------------------");
                //se imprime el puntaje total de cada equipo
                //Console.WriteLine($"Puntaje total equipo 1: {pt1}");
                //Console.WriteLine($"Puntaje total equipo 2: {pt2}");

                //codigo inutil ya que no se logro aplicar el sistema de combate a los equipos
                if(pt1>pt2)
	            {
		            Console.WriteLine("El Equipo 1 es el ganador");
	            }
	            if(pt2>pt1)
	            {
		            Console.WriteLine("El Equipo 2 es el ganador");
	            }
	            Console.WriteLine("+++++++++++++++++++++++++++++++++++++++++++++++++++++");
                //sistema de ataque por turnos
                //seleccion de jugador
                Console.WriteLine("Seleccione el numero del jugador para usar:");
                Console.WriteLine("Recuerde que no puede ser del mismo equipo");
                sel = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine($"Jugador seleccionado:{sel}");
                Console.Write("Nombre:");
        	    Console.WriteLine(jugadores[sel-1].Nombre);
                Console.Write("Salud:");
        	    Console.WriteLine(jugadores[sel-1].Salud);
                Console.Write("Nivel:");
        	    Console.WriteLine(jugadores[sel-1].Nivel);
                Console.Write("Puntaje:");
        	    Console.WriteLine(jugadores[sel-1].Puntaje);
                Console.Write("Ataque:");
        	    Console.WriteLine(jugadores[sel-1].Ataque);
                Console.Write("Defensa:");
        	    Console.WriteLine(jugadores[sel-1].Defensa);
                Console.Write("Equipo:");
        	    Console.WriteLine(jugadores[sel-1].Equipo);
                //seleccion del rival
                Console.WriteLine("Seleccione el numero del jugador rival para atacar:");
                Console.WriteLine("Recuerde que no puede ser del mismo equipo");
                selr = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine($"Jugador Rival seleccionado:{selr}");
                Console.Write("Nombre:");
        	    Console.WriteLine(jugadores[selr-1].Nombre);
                Console.Write("Salud:");
        	    Console.WriteLine(jugadores[selr-1].Salud);
                Console.Write("Nivel:");
        	    Console.WriteLine(jugadores[selr-1].Nivel);
                Console.Write("Puntaje:");
        	    Console.WriteLine(jugadores[selr-1].Puntaje);
                Console.Write("Ataque:");
        	    Console.WriteLine(jugadores[selr-1].Ataque);
                Console.Write("Defensa:");
        	    Console.WriteLine(jugadores[selr-1].Defensa);
                Console.Write("Equipo:");
        	    Console.WriteLine(jugadores[selr-1].Equipo);
                if(jugadores[sel-1].Equipo == jugadores[selr-1].Equipo)
                {
                    Console.WriteLine("NO PUEDE SER DEL MISMO EQUIPO");
                    return;
                }
                //CODIGO DE COMBATE POR TURNOS
                    ///////////////////////////////////////////////////////////
                    
                    Console.WriteLine("presione enter para lanzar los dados");
                    Console.ReadLine();
                    int resultado = LanzarDados();
                    Console.WriteLine("Resultado:" + resultado);
                    if(resultado %2 == 0 && jugadores[sel-1].Equipo == 2)
                    {
                        Console.WriteLine("Turno del jugador del equipo 2");
                        if(jugadores[sel-1].Ataque > jugadores[selr-1].Defensa)
                        {
                        Console.WriteLine($"el jugador rival:{selr} ya no tiene defensas");
                        int atk = jugadores[sel-1].Ataque;
                        int vidarival = jugadores[selr-1].Salud;
                        vidarival = vidarival - atk;
                        if(vidarival<0)
                        {
                            vidarival = 0;
                        }
                        jugadores[selr-1].Salud = vidarival;
                        jugadores[selr-1].Defensa = 0;
                        
                        Console.WriteLine($"el jugador rival:{selr} ha perdido puntos de vida");
                        Console.Write("Nombre:");
                        Console.WriteLine(jugadores[selr-1].Nombre);
                        Console.Write("Salud:");
                        Console.WriteLine(jugadores[selr-1].Salud);
                        Console.Write("Puntaje:");
                        Console.WriteLine(jugadores[selr-1].Puntaje);
                        Console.Write("Ataque:");
                        Console.WriteLine(jugadores[selr-1].Ataque);
                        Console.Write("Defensa:");
                        Console.WriteLine(jugadores[selr-1].Defensa);
                        Console.Write("Equipo:");
                        Console.WriteLine(jugadores[selr-1].Equipo);

                        if(jugadores[selr-1].Salud == 0)
                        {
                            Console.WriteLine($"el jugador rival:{selr} ya no puede continuar");
                            Console.WriteLine($"el jugador:{sel} es el ganador");
                            pt1=random.Next(1,800000);
                            pt2=random.Next(1,800000);
                            if(jugadores[sel-1].Equipo==1)
                            {
                            pt1=pt1+jugadores[sel-1].Puntaje;
                            Console.WriteLine($"Puntaje total equipo 1: {pt1}");
                            }
                            if(jugadores[sel-1].Equipo==2)
                            {
                            pt2=pt2+jugadores[sel-1].Puntaje;
                            Console.WriteLine($"Puntaje total equipo 2: {pt2}");
                            }
                        }
                    }
                    if(jugadores[sel-1].Ataque<jugadores[selr-1].Defensa)
                    {
                        Console.WriteLine("Ataque fallido");
                    }
                }
                 if(resultado %2 == 0 && jugadores[selr-1].Equipo == 2 )
                {
                    Console.WriteLine("Turno del jugador rival del equipo 2");
                    if(jugadores[selr-1].Ataque > jugadores[sel-1].Defensa)
                        {
                        
                        Console.WriteLine($"el jugador seleccionado:{sel} ya no tiene defensas");
                        int atk = jugadores[selr-1].Ataque;
                        int vidarival = jugadores[sel-1].Salud;
                        vidarival = vidarival - atk;
                        if(vidarival<0)
                        {
                            vidarival = 0;
                        }
                        jugadores[sel-1].Salud = vidarival;
                        jugadores[sel-1].Defensa = 0;
                        
                        Console.WriteLine($"el jugador seleccionado:{sel} ha perdido puntos de vida");
                        Console.Write("Nombre:");
                        Console.WriteLine(jugadores[sel-1].Nombre);
                        Console.Write("Salud:");
                        Console.WriteLine(jugadores[sel-1].Salud);
                        Console.Write("Puntaje:");
                        Console.WriteLine(jugadores[sel-1].Puntaje);
                        Console.Write("Ataque:");
                        Console.WriteLine(jugadores[sel-1].Ataque);
                        Console.Write("Defensa:");
                        Console.WriteLine(jugadores[sel-1].Defensa);
                        Console.Write("Equipo:");
                        Console.WriteLine(jugadores[sel-1].Equipo);

                        if(jugadores[sel-1].Salud == 0)
                        {
                            Console.WriteLine($"el jugador seleccionado:{sel} ya no puede continuar");
                            Console.WriteLine($"el jugador rival:{selr} es el ganador");
                            pt1=random.Next(1,800000);
                            pt2=random.Next(1,800000);
                            if(jugadores[selr-1].Equipo==1)
                            {
                            pt1=pt1+jugadores[sel-1].Puntaje;
                            Console.WriteLine($"Puntaje total equipo 1: {pt1}");
                            }
                            if(jugadores[selr-1].Equipo==2)
                            {
                            pt2=pt2+jugadores[selr-1].Puntaje;
                            Console.WriteLine($"Puntaje total equipo 2: {pt2}");
                            }
                        }
                    }
                    if(jugadores[selr-1].Ataque<jugadores[sel-1].Defensa)
                    {
                        Console.WriteLine("Ataque fallido");
                    }                
                }
                if(resultado %2!=0 && jugadores[sel-1].Equipo == 1)
                {
                    Console.WriteLine("Turno del jugador del equipo 1");
                    if(jugadores[sel-1].Ataque > jugadores[selr-1].Defensa)
                        {
                        Console.WriteLine($"el jugador rival:{selr} ya no tiene defensas");
                        int atk = jugadores[sel-1].Ataque;
                        int vidarival = jugadores[selr-1].Salud;
                        vidarival = vidarival - atk;
                        if(vidarival<0)
                        {
                            vidarival = 0;
                        }
                        jugadores[selr-1].Salud = vidarival;
                        jugadores[selr-1].Defensa = 0;
                        
                        Console.WriteLine($"el jugador rival:{selr} ha perdido puntos de vida");
                        Console.Write("Nombre:");
                        Console.WriteLine(jugadores[selr-1].Nombre);
                        Console.Write("Salud:");
                        Console.WriteLine(jugadores[selr-1].Salud);
                        Console.Write("Puntaje:");
                        Console.WriteLine(jugadores[selr-1].Puntaje);
                        Console.Write("Ataque:");
                        Console.WriteLine(jugadores[selr-1].Ataque);
                        Console.Write("Defensa:");
                        Console.WriteLine(jugadores[selr-1].Defensa);
                        Console.Write("Equipo:");
                        Console.WriteLine(jugadores[selr-1].Equipo);

                        if(jugadores[selr-1].Salud == 0)
                        {
                            Console.WriteLine($"el jugador rival:{selr} ya no puede continuar");
                            Console.WriteLine($"el jugador seleccionado:{sel} es el ganador");
                            pt1=random.Next(1,800000);
                            pt2=random.Next(1,800000);
                            if(jugadores[sel-1].Equipo==1)
                            {
                            pt1=pt1+jugadores[sel-1].Puntaje;
                            Console.WriteLine($"Puntaje total equipo 1: {pt1}");
                            }
                            if(jugadores[sel-1].Equipo==2)
                            {
                            pt2=pt2+jugadores[sel-1].Puntaje;
                            Console.WriteLine($"Puntaje total equipo 2: {pt2}");
                            }
                        }
                    }
                    if(jugadores[sel-1].Ataque<jugadores[selr-1].Defensa)
                    {
                        Console.WriteLine("Ataque fallido");
                    }
                }
                if(resultado %2!=0 && jugadores[selr-1].Equipo == 1)
                {
                    Console.WriteLine("Turno del jugador rival del equipo 1");
                    if(jugadores[selr-1].Ataque > jugadores[sel-1].Defensa)
                        {
                        
                        Console.WriteLine($"el jugador seleccionado:{sel} ya no tiene defensas");
                        int atk = jugadores[selr-1].Ataque;
                        int vidarival = jugadores[sel-1].Salud;
                        vidarival = vidarival - atk;
                        if(vidarival<0)
                        {
                            vidarival = 0;
                        }
                        jugadores[sel-1].Salud = vidarival;
                        jugadores[sel-1].Defensa = 0;
                        
                        Console.WriteLine($"el jugador seleccionado:{sel} ha perdido puntos de vida");
                        Console.Write("Nombre:");
                        Console.WriteLine(jugadores[sel-1].Nombre);
                        Console.Write("Salud:");
                        Console.WriteLine(jugadores[sel-1].Salud);
                        Console.Write("Puntaje:");
                        Console.WriteLine(jugadores[sel-1].Puntaje);
                        Console.Write("Ataque:");
                        Console.WriteLine(jugadores[sel-1].Ataque);
                        Console.Write("Defensa:");
                        Console.WriteLine(jugadores[sel-1].Defensa);
                        Console.Write("Equipo:");
                        Console.WriteLine(jugadores[sel-1].Equipo);

                        if(jugadores[sel-1].Salud == 0)
                        {
                            Console.WriteLine($"el jugador seleccionado:{sel} ya no puede continuar");
                            Console.WriteLine($"el jugador rival:{selr} es el ganador");
                            pt1=random.Next(1,800000);
                            pt2=random.Next(1,800000);
                            if(jugadores[selr-1].Equipo==1)
                            {
                            pt1=pt1+jugadores[sel-1].Puntaje;
                            Console.WriteLine($"Puntaje total equipo 1: {pt1}");
                            }
                            if(jugadores[selr-1].Equipo==2)
                            {
                            pt2=pt2+jugadores[selr-1].Puntaje;
                            Console.WriteLine($"Puntaje total equipo 2: {pt2}");
                            }
                        }
                    }
                    if(jugadores[selr-1].Ataque<jugadores[sel-1].Defensa)
                    {
                        Console.WriteLine("Ataque fallido");
                    }                
                }
                 Console.WriteLine("+++++++++++++++++++++++++++++++++++++++++++++++++++++");
                ///////////////////////////////////////////////////////////////////////////
                //menu que se encargara de saber que es lo que quiere hacer el usuario(codigo antiguo)
	            while(k!=3)
	            {
		            Console.WriteLine("si desea mostrar las estadisticas de un jugador marque 1:");
		            Console.WriteLine("si desea actualizar las estadisticas de un jugador marque 2:");
		            Console.WriteLine("si no desea hacer nada marque 3:");
		            k=Convert.ToInt32(Console.ReadLine());
	    	        if(k==1)
    		        {
    			        //mostrar estadisticas de un jugador seleccionado
        			    Console.WriteLine("De que jugador desea ver las estadistcas?:");
        			    es=Convert.ToInt32(Console.ReadLine());
        			    Console.WriteLine($"Estadisticas del Jugador:{es}");
                        Console.Write("Nombre:");
        			    Console.WriteLine(jugadores[es-1].Nombre);
                        Console.Write("Salud:");
        			    Console.WriteLine(jugadores[es-1].Salud);
                        Console.Write("Nivel:");
        			    Console.WriteLine(jugadores[es-1].Nivel);
                        Console.Write("Puntaje:");
        			    Console.WriteLine(jugadores[es-1].Puntaje);
                        Console.Write("Ataque:");
        			    Console.WriteLine(jugadores[es-1].Ataque);
                        Console.Write("Defensa:");
        			    Console.WriteLine(jugadores[es-1].Defensa);
                        Console.Write("Equipo:");
        			    Console.WriteLine(jugadores[es-1].Equipo);
        			    Console.WriteLine("---------------------------------------------");
		            }
		            if(k==2)
		            {
                        string nomact=" ";
		        	    //actualizar estadisticas de un jugador seleccionado
        			    Console.WriteLine("A que jugador quiere cambiarle las estadisticas?");
        			    act=Convert.ToInt32(Console.ReadLine());
        			    Console.WriteLine($"Jugador {act} Seleccionado para cambiar estadisticas");
        			    Console.WriteLine("Introduzca su nuevo nombre o mantenga el que ya tiene");
                        nomact = nomact + Console.ReadLine();
                        jugadores[act].Nombre = nomact;
        			    jugadores[act].Salud=random.Next(1,2100);
        			    jugadores[act].Nivel=random.Next(1,713);
        			    jugadores[act].Puntaje=0;
        			    jugadores[act].Ataque=random.Next(1,16000);
        			    jugadores[act].Defensa=random.Next(1,9000);
        			    Console.WriteLine("---------------------------------------------");
	        		    Console.WriteLine("Estadisticas actualizadas:");
                        Console.Write("Nombre:");
	        		    Console.WriteLine(jugadores[act].Nombre);
                        Console.Write("Salud:");
        			    Console.WriteLine(jugadores[act].Salud);
                        Console.Write("Nivel:");
        			    Console.WriteLine(jugadores[act].Nivel);
                        Console.Write("Puntaje:");
        			    Console.WriteLine(jugadores[act].Puntaje);
                        Console.Write("Ataque:");
        			    Console.WriteLine(jugadores[act].Ataque);
                        Console.Write("Defensa:");
        			    Console.WriteLine(jugadores[act].Defensa);
                        Console.Write("Equipo:");
			            Console.WriteLine(jugadores[act-1].Equipo);
			            Console.WriteLine("---------------------------------------------");
		            }
		            if(k==3)
		            {
                        return;
		            }
	            }
	
            }
        }
    }
}
