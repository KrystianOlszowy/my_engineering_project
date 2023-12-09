void setup()
{
  Serial.begin(115200);
  delay(250);

  if (!display.begin(i2c_Address, true))
  {
    Serial.print("Couldn't connect to the OLED display at address: ");
    Serial.print(i2c_Address, HEX);
  }
  else
  {
    display.drawBluetoothInitializing();
  }

  // inicjalizacja serwera BLE
  connection->setupConnection();
  Serial.println("Advertising Started");

  // inicjalizacja odbierania i wysyłania kodów IR
  IRReceiver.enableIRIn();
  IRSender.begin();
  Serial.println("\n IRReceiver and IRSender started. Waiting for signals..");
}