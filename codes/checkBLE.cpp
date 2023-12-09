Future<void> initCheckingBleAdapter() async {
    _alreadyAsked = false;
    FlutterBluePlus.adapterState.listen((state) {
      _isBluetoothOn = state == BluetoothAdapterState.on;
      if (!_isBluetoothOn) {
        FlutterBluePlus.stopScan();
        if (!_alreadyAsked) {
          _alreadyAsked = true;
          FlutterBluePlus.turnOn();
        }
      } else {
        _alreadyAsked = false;
      }
    });
  }