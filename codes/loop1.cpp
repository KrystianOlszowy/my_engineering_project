unsigned long drawButtonTimestamp{0};
unsigned long drawIrTimestamp{0};

void loop()
{
  if (connection->isConnectionEvent())
  {
    connection->drawServerEvent(display, connection->getConnectedDevices());
    connection->resetConnnectionEvent();
  }

  if (connection->isButtonTypeEvent())
  {
    controller.updateButtonType();
    connection->resetButtonTypeEvent();
    int buttonType = controller.getButtonType();

    switch (buttonType)
    {
    case bt2ir::ButtonType::ZERO:
    // kolejne przypadki dla innych przycisków numerycznych
    //...
    case bt2ir::ButtonType::NINE:
      display.drawDigit(buttonType);
      break;

    case bt2ir::ButtonType::POWER:
      display.drawPower();
      break;
    // kolejne przypadki dla innych przycisków podstawowych
    //...
    default:
      Serial.println("Wrong ButtonType value!");
      break;
    }
    drawButtonTimestamp = millis();
    drawIrTimestamp = 0;
  }