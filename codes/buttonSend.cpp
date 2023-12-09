 onPressed: () async {
                      if (!isSending) {
                        isSending = true;
                        await _bleService.sendButtonIdToDevice(
                            TVModelHandle.selectedTVModel.one.getId());
                        await _bleService.sendIrCodeToDevice(
                            TVModelHandle.selectedTVModel.one.getIrCode());
                        isSending = false;
                      }
                    },