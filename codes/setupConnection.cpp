void bt2ir::Connection::setupConnection()
{
    this->initConnectedDevices();
    NimBLEDevice::init(this->serverName);

    this->serverBt2ir = NimBLEDevice::createServer();
    this->serverBt2ir->setCallbacks(new bt2ir::ServerCallbacks());

    NimBLEService *serviceB2tir{serverBt2ir->createService(this->serviceBt2ir_UIID)};

    this->buttonTypeCharacteristic = serviceB2tir->createCharacteristic(
        this->buttonTypeCharacteristic_UUID, NIMBLE_PROPERTY::WRITE);
    this->buttonTypeCharacteristic->setCallbacks(new ButtonTypeCharacteristicCallbacks);

    this->buttonIrCodeCharacteristic = serviceB2tir->createCharacteristic(
        this->irCodeCharacteristic_UUID, NIMBLE_PROPERTY::WRITE);
    this->buttonIrCodeCharacteristic->setCallbacks(new IrCodeCharacteristicCallbacks);
    serviceB2tir->start();

    NimBLEAdvertising *advertising{NimBLEDevice::getAdvertising()};
    advertising->addServiceUUID(serviceB2tir->getUUID());
    advertising->setScanResponse(true);
    advertising->start();
}