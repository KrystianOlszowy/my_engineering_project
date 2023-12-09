Future<void> scanBleDevices() async {
    await checkLocationEnabled();
    FlutterBluePlus.scanResults.listen((results) {
      availableDevices = results
          .map((scanResult) => scanResult.device)
          .where(
              (device) => device.platformName.contains("Bluetooth2IR for TV"))
          .toList();
    });

    if (!_isScanning && _isBluetoothOn && _locationEnabled) {
      _isScanning = true;
      await FlutterBluePlus.startScan(timeout: const Duration(seconds: 3));
      await FlutterBluePlus.isScanning.where((value) => value == false).first;
      _isScanning = false;
    }
  }