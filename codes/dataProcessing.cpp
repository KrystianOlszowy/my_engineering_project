void bt2ir::Controller::updateButtonType()
{
    NimBLECharacteristic *characteristic = connection->getButtonTypeCharacteristic();

    if (characteristic->getValue<uint8_t>() >= ButtonType::ZERO && characteristic->getValue<uint8_t>() < ButtonType::LIMIT)
    {
        this->buttonType = characteristic->getValue<uint8_t>();
        connection->setButtonTypeEvent();
    }
    else
    {
        this->buttonType = ButtonType::LIMIT;
    }
}