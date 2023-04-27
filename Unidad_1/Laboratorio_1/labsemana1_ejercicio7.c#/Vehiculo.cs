using System;
namespace ex7
{
    class vehiculo
    {
       //Atributos
        private string _fabricante;

        private string _modelo;

        private int _anio;

        private double _velocidad;

        private double _maniobrabilidad;

        //Propiedades
        public string Fabricante 
        {
            get{return this._fabricante;}
            set{this._fabricante = value;}
        }
      public string Modelo 
        {
            get{return this._modelo;}
            set{this._modelo = value;}
        }        
      public int Anio
        {
            get{return this._anio;}
            set{this._anio = value;}
        }
      public double Velocidad
        {
            get{return this._velocidad;}
            set{this._velocidad = value;}
        }
         public double Maniobrabilidad
        {
            get{return this._maniobrabilidad;}
            set{this._maniobrabilidad = value;}
        }    
        
        //Metodos
        //Constructor Por defecto
        public vehiculo()
        {
            _fabricante = " ";
            _modelo = " ";
            _anio = 0;
            _velocidad = 0;
            _maniobrabilidad = 0;           
        }           
        //constructo por parametros 
        public vehiculo( string _fabricante, string _modelo,int _anio, double _velocidad, double _maniobrabilidad)
        {
            this._fabricante = Fabricante;
            this._modelo = Modelo;
            this._anio = Anio;
            this._velocidad = Velocidad;
            this._maniobrabilidad = Maniobrabilidad;
        }
        
        public void encender()
        {
            Console.WriteLine("motor encendido");
        }
        
        public void acelerar()
        {
            Console.WriteLine("acelerando");
        }
        public void frenar()
        {
            Console.WriteLine("frenando");
        }
        public string MostrarDetalles()
        {
        return $"Fabricante: {this._fabricante}\n Modelo:{this._modelo}\n Año:{this._anio}\n Velocidad:{this._velocidad}\n Maniobrabilidad: {this._maniobrabilidad}";
        }
        
    
    class Program
    {
            public static void Main(string[] args)
            {
                //Creando los vehiculos
                vehiculo v1 = new vehiculo();
                vehiculo v2 = new vehiculo();
                vehiculo v3 = new vehiculo();
                Console.WriteLine("BIENVENIDO AL SIMULADOR DE AUTOS");
                Console.WriteLine("Elige tu auto");
                //asignado atributos a los vehiculos
                Console.WriteLine("-----------------");
                Console.WriteLine("VEHICULO NUMERO 1");
                v1.Fabricante = "Koenigsegg";
                v1.Modelo = "Agera R";
                v1.Anio = 2011;
                v1.Velocidad = 401;
                v1.Maniobrabilidad = 80;
                Console.WriteLine(v1.MostrarDetalles());
                v1.encender();
                v1.acelerar();
                v1.frenar();
                Console.WriteLine("-----------------");
                Console.WriteLine("VEHICULO NUMERO 2"); 
                v2.Fabricante = "Lamborghini";
                v2.Modelo = "Sesto Elemento";
                v2.Anio = 2010;
                v2.Velocidad = 350;
                v2.Maniobrabilidad = 95;
                Console.WriteLine(v2.MostrarDetalles());
                v2.encender();
                v2.acelerar();
                v2.frenar();
                Console.WriteLine("-----------------");
                Console.WriteLine("VEHICULO NUMERO 3"); 
                v3.Fabricante = "Mclaren";
                v3.Modelo = "P1";
                v3.Anio = 2012;
                v3.Velocidad = 362;
                v3.Maniobrabilidad = 85;
                Console.WriteLine(v3.MostrarDetalles());
                v3.encender();
                v3.acelerar();
                v3.frenar();
                Console.WriteLine("-----------------");
                int op=0;
                Console.WriteLine("op 1= Vehiculo 1");
                Console.WriteLine("op 2= Vehiculo 2");
                Console.WriteLine("op 3= Vehiculo 3");
                op = Convert.ToInt32(Console.ReadLine());
                //opciones de seleccion para el vehiculo
                if(op == 1)
                {
                    Console.WriteLine("VEHICULO ELEGIDO: KOENIGSEGG AGERA R");
                } 
                if(op == 2)
                {
                    Console.WriteLine("VEHICULO ELEGIDO: LAMBORGHINI SESTO ELEMENTO");
                } 
                if(op == 3)
                {
                    Console.WriteLine("VEHICULO ELEGIDO: MCLAREN P1");
                } 
                  
            }
        }
    }
}
