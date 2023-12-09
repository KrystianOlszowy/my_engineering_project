// biblioteki sygnałów podczerwonych
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRsend.h>

// własne bliblioteki
#include "bt2ir_graphics.hpp"
#include "bt2ir_connection.hpp"
#include "bt2ir_controller.hpp"

// globalne definicje dotyczące ekranu
#define i2c_Address 0x3c
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

// inicjalizacja obiektów zarządzających urządzeniem
bt2ir::Display display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
bt2ir::Connection *connection = bt2ir::Connection::getInstance();
bt2ir::Controller controller{};

// globalne definicje dotyczące transmitera IR
const uint16_t receiverPin{5};
IRrecv IRReceiver(receiverPin);
decode_results receivedIrCode{};

// globalne definicje dotyczące odbiornika IR
const uint16_t senderPin{4};
IRsend IRSender(senderPin);