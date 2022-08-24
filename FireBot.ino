int relayPin = 3; // salida de señal hacia la bobina del rele
int digitalPin = 5; // KY-026 entrada digital del sensor de flama en el pin 5
int analogPin = A1; // KY-026 Salida análoga del sensor de flama en el pin A0 
int digitalVal; // lectura digital 
int analogVal; // lectura análoga 

void setup()
{
  pinMode(relayPin, OUTPUT); // Definimos relayPin en salida del arduino al relay
  pinMode(digitalPin, INPUT); // Definimos digitalPin en entrada del sensor al arduino
  pinMode(analogPin, OUTPUT); //Definimos analogPin en salida para imprimir los valores en el monitor serial
  Serial.begin(9600); //Velocidad de transmisión en baudios
}  


void loop()
{
  // lectura entrada digital
  digitalVal = digitalRead(digitalPin); 
  if(digitalVal == HIGH) // si el valor de digitalVal es igual a "HIGH" o la flama es detectada
  {
    digitalWrite(relayPin, HIGH); // energiza la bobina del relay para cerrar el circuito normalmente abierto 
  }
  else //Si el valor de digitalVal no es igual a "HIGH" o la flama no es detectada
  {
    digitalWrite(relayPin, LOW); // no energiza la bobina del relay y el circuito continua abierto
  }

  // lectura entrada análoga
  analogVal = analogRead(analogPin); 
  Serial.println(analogVal); // imprime valor analogico que se puede observar en el monitor serial

  delay(100);
}
