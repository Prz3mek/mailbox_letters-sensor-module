// Program obsługujący moduł czujnika obecności listów.
// Autor: Przemysław Kusa

#define detect 9    // Definicja wyprowadzenia, do którego podłączony jest detektor

int detect_state = 0;

void setup() 
{
  pinMode (detect, INPUT); // Inicjalizacja wyprowadzenia oraz trybu pracy detektora
  Serial.begin(9600);   // Inicjalizacja połączenie Bluetooth
}

void loop() 
{
    detector();   // Wywołanie funkcji detector
} 

void detector()
{
  detect_state = digitalRead(detect);   // Odczyt wartości z wyprowadzenia, do którego podłączony jest detektor
   
    if(detect_state == LOW)           // Jeżeli stan jest niski, wysyłane jest 0, w przeciwnym razie wysyłane jest 1
      {
        Serial.print('0');
      }
      else
        {
          Serial.print('1');
        }
    delay(500);                    // Czekanie 500ms
}
