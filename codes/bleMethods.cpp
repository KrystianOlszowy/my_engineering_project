namespace bt2ir
{
    class Connection
    {
    public:
        static Connection *getInstance();

        void setupConnection();

        void initConnectedDevices();
        void addDeviceToCounter();
        void removeDeviceFromCounter();
        int getConnectedDevices();

        void setConnectionEvent();
        void resetConnnectionEvent();
        bool isConnectionEvent();

        void setButtonTypeEvent();
        void resetButtonTypeEvent();
        bool isButtonTypeEvent();

        void setButtonIrCodeEvent();
        void resetButtonIrCodeEvent();
        bool isButtonIrCodeEvent();

        NimBLECharacteristic *getButtonTypeCharacteristic();
        NimBLECharacteristic *getButtonIrCodeCharacteristic();

        void drawServerEvent(Display &display, bool deviceConnected);