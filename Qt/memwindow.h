#pragma once
class MemWindow : public QWidget{
    Q_OBJECT
public:

    //MemWindow();
    explicit MemWindow(QWidget* parent = nullptr);

    ~MemWindow() override;

    void toggleVisible();
private:
    bool isHidden;
    void InitGuiElements();

};