Future<void> checkLocationEnabled() async {
    _locationEnabled = await Location().serviceEnabled();
    if (!_locationEnabled) {
      Location().requestService();
    }
  }