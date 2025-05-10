/*
   -- Control de LEDs con RemoteXY via BLE --
   
   Este código controla LEDs en los pines GPIO4 y GPIO5 del ESP32
   mediante botones en una aplicación móvil usando RemoteXY con BLE.
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_BLE
#include <BLEDevice.h>

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"

#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 58 bytes
  { 255,2,0,0,0,51,0,19,0,0,0,77,111,116,111,114,0,31,1,106,
  200,1,1,2,0,1,16,79,24,24,0,2,31,65,118,97,110,99,101,0,
  1,65,79,24,24,0,2,31,82,101,116,114,111,99,101,115,111,0 };
  
// this structure defines all the variables and events of your control interface 
struct {
    // input variables
  uint8_t avance;    // =1 si el botón está presionado, =0 si no
  uint8_t retroceso; // =1 si el botón está presionado, =0 si no

    // other variable
  uint8_t connect_flag;  // =1 si está conectado, =0 si no
} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

// Definición de pines para los LEDs
#define PIN_LED_AVANCE    4  // GPIO4 para el LED de avance
#define PIN_LED_RETROCESO 5  // GPIO5 para el LED de retroceso

void setup() 
{
  // Inicializar RemoteXY
  RemoteXY_Init(); 
  
  // Configurar pines de los LEDs como salida
  pinMode(PIN_LED_AVANCE, OUTPUT);
  pinMode(PIN_LED_RETROCESO, OUTPUT);
  
  // Apagar ambos LEDs inicialmente
  digitalWrite(PIN_LED_AVANCE, LOW);
  digitalWrite(PIN_LED_RETROCESO, LOW);
  
  // Inicializar comunicación serial para depuración (opcional)
  Serial.begin(115200);
  Serial.println("Sistema iniciado - Esperando conexión BLE...");
}

void loop() 
{ 
  // Manejar la comunicación con RemoteXY
  RemoteXY_Handler();
  
  // Controlar el LED de avance (GPIO4)
  if (RemoteXY.avance == 1) {
    digitalWrite(PIN_LED_AVANCE, HIGH);
    Serial.println("Botón Avance presionado - LED GPIO4 ON");
  } else {
    digitalWrite(PIN_LED_AVANCE, LOW);
  }
  
  // Controlar el LED de retroceso (GPIO5)
  if (RemoteXY.retroceso == 1) {
    digitalWrite(PIN_LED_RETROCESO, HIGH);
    Serial.println("Botón Retroceso presionado - LED GPIO5 ON");
  } else {
    digitalWrite(PIN_LED_RETROCESO, LOW);
  }
  
  // Pequeña pausa para evitar fluctuaciones
  RemoteXY_delay(10);
}
