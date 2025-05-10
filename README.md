# Control-Bluetooth-con-ESP32-C3
Te comparto todos los archivos para esta practica de controlar leds o motores via Bluetooth
With this PCB you can connect motors and invert the motor's rotation with the L9110 H bridge, in addition to sending via Bluetooth
Con esta tarjeta puedes controlar vía Bluetooth motores o luces led con ayuda del ESP32 C3 (yo utilizo la versión super mini), para ello necesitamos crear una App, yo utilice la plataforma de RemoteXY.
Aparte realice un mecanismo de piñón cremallera para poder controlarlo con motor, el diseño lo corte con CNC Router, y te comparto también el archivo.
Aquí encuentras todo lo que necesitas para llevar a cabo la practica en protoboard de encender Leds vía Bluetooth y el controlar motor con un circuito hecho en PCB.
Para la creación de la App me apoye de la AI, para completar el promp necesitas sacar el código de RemoteXY (Te enseño como hacerlo en el vídeo)

Materiales para practica en Protoboard:

1 Esp 32 C3
2 leds 5mm
2 Resistencias 1K
1 Smartphone


Materiales circuito PCB para motores:

1 Esp32 C3
5 Borneras
1 Buzzer 9650
2 Resistencias 1206
2 Capacitores 1206
1 Puente H L9110
1 Regulador voltaje AMS1117


Promp DeepSeek:

Tengo un circuito en el que el ESP32 C3 tiene conectado en el gpio 4 un led y en el gpio 5 otro led, estos leds serán activados por una aplicación de remotexy cuando se presiona el botón 1 enciende el led de gpio4 y cuando se suelta deja de encender, el otro botón controla al led gpio5 completa el programa si tengo ya esta parte del código /*

(Aquí se pega la parte del código que generas en RemoteXY)

![photo_4969881785949335180_x](https://github.com/user-attachments/assets/6a8af830-f38f-45dd-9ece-8003ed895aef)


