#include <QtWidgets>
#pragma once
class MemWindow : public QWidget{
    Q_OBJECT
public:
    explicit MemWindow(QWidget* parent = nullptr);

    ~MemWindow() override;

    void toggleVisible();
private:
    bool isHidden;
    void InitGuiElements();

    QLabel *imageLabel;
    QScrollArea *scrollArea;
    QCheckBox *checkbox;
    QListWidget *searchResultList;

    //string search
    QPushButton *searchButton;
    QLineEdit *searchBox;

    QVBoxLayout * mainLayout;
    QHBoxLayout * buttonBox;
    QHBoxLayout * contentBox;

    std::vector<u32> searchString(std::string searchQuery);
};