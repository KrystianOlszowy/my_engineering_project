// biblioteki wyświetlacza
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

namespace bt2ir
{
    class Display : public Adafruit_SH1106G
    {
    public:
        // kontruktor inicjujący elementy dziedziczone z klasy Adafruit_SH1106G
        Display(const uint16_t width, const uint16_t height, TwoWire *twoWire, const int8_t resetPin = -1) : Adafruit_SH1106G{width, height, twoWire, resetPin}
        {
        }
        //rysowanie odebranego kodu IR w postaci heksadecymalnej
        void drawReceivedIrCode(uint64_t irCode);

        // rysowanie konkretnych przycisków kontroli
        void drawMoveUp();
        void drawMoveDown();
        void drawMoveRight();
        void drawMoveLeft();
        void drawPower();
        void drawOK();
        void drawMenu();
        void drawMute();
        void drawVolumeDown();
        void drawVolumeUp();
        void drawChannelDown();
        void drawChannelUp();

        // rysowanie stanu połączenia
        void drawBluetoothDisconnected();
        void drawBluetoothConnected(const int connectedDevices);
        void drawBluetoothInitializing();

        // rysowanie konretnych przycisków wprowadzania cyfr
        void drawDigit(int digitToPrint);