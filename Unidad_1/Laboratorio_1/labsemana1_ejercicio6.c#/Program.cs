using System;
namespace ex6
{
    class jugador 
    {
       //Atributos
        private string _tipo;

        private string _nombre;

        private int _vida;

        private int _poder;

        private int _velocidad;

        //Propiedades
        public string Tipo
        {
            get{return this._tipo;}
            set{this._tipo = value;}
        }
      public string Nombre
        {
            get{return this._nombre;}
            set{this._nombre = value;}
        }        
      public int Vida
        {
            get{return this._vida;}
            set{this._vida = value;}
        }
      public int Poder
        {
            get{return this._poder;}
            set{this._poder = value;}
        }
      public int Velocidad
        {
            get{return this._velocidad;}
            set{this._velocidad = value;}
        }    
        
        //Metodos
        //Constructor Por defecto
        public jugador()
        {
            _tipo = "guerrero";
            _nombre = "Solaire";
            _vida = 20;
            _poder = 9000;
            _velocidad = 355;
            
        }           
        //constructo por parametros 
        public jugador( string _tipo, string _nombre,int _vida, int _poder, int _velocidad)
        {
            this._tipo = Tipo;
            this._nombre = Nombre;
            this._vida = Vida;
            this._poder = Poder;
            this._velocidad = Velocidad;
        }
        //metodos
        public void descansar()
        {
         Console.WriteLine("Recuperando energia");
        }
        
        public void atacar()
        {
            Console.WriteLine("Has usado lanza de la luz solar");
        }
        public string MostrarDetalles()
        {
        return $"Tipo de personaje: {this._tipo}\n Nombre:{this._nombre}\n Vida:{this._vida}\n Poder:{this._poder}\n Velocidad: {this._velocidad}";
        }
        
    
    class Program
    {
        public static void Main(string[] args)
        {
            //Creando el Objeto jugador
            jugador j1 = new jugador();

            var end = 0; 
            var op = 0;

            Console.WriteLine("Bienvenido al Simulador de juego de rol");

            while(end != 1)
            {
                op = 0;
                Console.WriteLine("Por favor ingresa una opcion");
                Console.WriteLine("op 1= Recuperarte ");
                Console.WriteLine("op 2= Atacar ");
                Console.WriteLine("op 3= Terminar la simulacion ");


                op = Convert.ToInt32(Console.ReadLine());

                if(op ==1)
                {
                    j1.descansar();
                    Console.WriteLine(j1.MostrarDetalles());
                }
                if(op == 2)
                {
                    j1.atacar();
                    Console.WriteLine(j1.MostrarDetalles());
                }
                if(op ==3)
                {
                    end = 1;
                }
                
                }
  
            }
        }
    }
}
