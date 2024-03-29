#include <SoftwareSerial.h>
/* Create object named SIM900 of the class SoftwareSerial */
SoftwareSerial SIM900(9,10);
void setup() {
  SIM900.begin(9600);  /* Define baud rate for software serial communication */
  Serial.begin(9600); /* Define baud rate for serial communication */
}

void loop() {
  Serial.println("TCP Receive :");
  Serial.print("AT\\r\\n");
  SIM900.println("AT"); /* Check Communication */
  delay(5000);
  ShowSerialData(); /* Print response on the serial monitor */
  delay(5000);
  Serial.print("AT+CIPMODE=0\\r\\n"); 
  SIM900.println("AT+CIPMODE=0"); /* Non-Transparent (normal) mode for TCP/IP application */
  delay(5000);
  ShowSerialData();  
  delay(5000);
  Serial.print("AT+CIPMUX=0\\r\\n");
  SIM900.println("AT+CIPMUX=0");  /* Single TCP/IP connection mode */
  delay(5000);
  ShowSerialData();
  delay(5000);
  Serial.print("AT+CGATT=1\\r\\n");
  SIM900.println("AT+CGATT=1"); /* Attach to GPRS Service */
  delay(5000);
  ShowSerialData();
  delay(5000);
  Serial.print("AT+CREG?\\r\\n");
  SIM900.println("AT+CREG?"); /* Network registration status */
  delay(5000);
  ShowSerialData();
  delay(5000);
  Serial.print("AT+CGATT?\\r\\n");
  SIM900.println("AT+CGATT?");  /* Attached to or detached from GPRS service */ 
  delay(5000); 
  ShowSerialData();
  delay(5000);
  Serial.print("AT+CSTT=\"airtelgprs.com\",\"\",\"\"\\r\\n");
  SIM900.println("AT+CSTT=\"airtelgprs.com\",\"\",\"\""); /* Start task and set APN */
  delay(5000);
  ShowSerialData();
  delay(5000);
  Serial.print("AT+CIICR\\r\\n");
  SIM900.println("AT+CIICR"); /* Bring up wireless connection with GPRS */
  delay(5000);
  ShowSerialData();
  delay(5000);
  Serial.print("AT+CIFSR\\r\\n");
  SIM900.println("AT+CIFSR"); /* Get local IP address */
  delay(5000);
  ShowSerialData();
  delay(5000);
  Serial.print("AT+CIPSTART=\"TCP\",\"35.154.40.208\",\"80\"\\r\\n");
  SIM900.println("AT+CIPSTART=\"TCP\",\"35.154.40.208\",\"80\"");  /* Start up TCP connection */
  delay(5000);
  ShowSerialData();
  delay(5000);
  Serial.print("AT+CIPSEND\\r\\n");
  SIM900.println("AT+CIPSEND"); /* Send data through TCP connection */
  delay(2000);
  ShowSerialData();
  delay(2000);
  Serial.print("GET /cgi-bin/upload.py?lat=26&lon=75\r\\n");
  SIM900.print("GET /cgi-bin/upload.py?lat=26&lon=75\r\n\x1A");  /* URL for data to be read from */
  delay(5000);
  ShowSerialData();
  delay(5000);
  Serial.print("AT+CIPSHUT\\r\\n");
  SIM900.println("AT+CIPSHUT"); /* Deactivate GPRS PDP content */
  delay(5000);
  ShowSerialData();
  delay(5000);
}

void ShowSerialData()
{
  while(SIM900.available()!=0)  /* If data is available on serial port */
  Serial.write(char (SIM900.read())); /* Print character received on to the serial monitor */
}