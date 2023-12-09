private:
        // podstawowe operacje rysowania
        void drawCenteredString(const std::string &text, const int field_width, const int start_x, const int field_height, const int start_y);
        void drawBigDigit(const int digit, const int field_width, const int start_x, const int start_y);

        // złożone operacje rysowania
        void drawIconWithDescription(const unsigned char icon[], const std::string &description_text);
        void drawBigDigitWithDescription(const int digit, const std::string &description_text);
    };