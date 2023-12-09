// rysowanie ikony przycisku przejścia w górę i jego opisu
void bt2ir::Display::drawMoveUp()
{
    this->clearDisplay();
    const std::string description_text{"Move Up"};
    drawIconWithDescription(moveUp_icon, description_text);
    this->display();
}