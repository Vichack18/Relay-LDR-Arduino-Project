
const int rele=8;
int fotores=A5;
int resultado=0;

void setup() {
  // put your setup code here, to run once:
 pinMode ( rele, OUTPUT);
 Serial.begin (9600);
 pinMode (fotores , INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 resultado=analogRead (fotores); // nos va a mostrar entre 0 y 1023 la fotoresistencia //

// Ahora necesitamos saber con precision la luz del ambiente, ya que 500 es un estimativo que pusimos //
// Necesitamos calibrarlo //
 Serial.println ( resultado );

 if (resultado >= 800){ // cuanta mayor oscuridad, mayor va a ser el numero //
 
  digitalWrite (rele, LOW); // algunas placas de rele se prenden con un LOW o con un HIGH ( analizar segun fabricante)
  // o verificar probando primero antes que nada, para no generar problemas de conexion despues //
  delay (500); // siempre tener un minimo de 500 de t al ser un dispositivo que trabaja con imanes, etc //
 }

 else {
  digitalWrite ( rele , HIGH);
  delay (500);
 }

}