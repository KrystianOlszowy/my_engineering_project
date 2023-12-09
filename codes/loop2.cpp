if (connection->isButtonIrCodeEvent())
  {
    controller.updateButtonIrCode();
    connection->resetButtonIrCodeEvent();
    IRSender.sendNEC(controller.getButtonIrCode());
  }

  if (IRReceiver.decode(&receivedIrCode))
  {
    display.drawReceivedIrCode(receivedIrCode.value);
    drawIrTimestamp = millis();
    drawButtonTimestamp = 0;
    IRReceiver.resume();
  }

  if ((millis() - drawButtonTimestamp >= 500UL && drawButtonTimestamp != 0) || (millis() - drawIrTimestamp >= 7000UL && drawIrTimestamp != 0))
  {
    connection->drawServerEvent(display, connection->getConnectedDevices());
    drawButtonTimestamp = 0;
    drawIrTimestamp = 0;
  }
}