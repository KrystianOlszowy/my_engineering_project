Future<void> sendIrCodeToDevice(int irCode) async {
  Uint8List irCodeUint64List = Uint8List(8);
  irCodeUint64List.buffer.asByteData().setUint64(0, irCode, Endian.little);
  await _characteristicIrCode?.write(irCodeUint64List, withoutResponse: false);
}
