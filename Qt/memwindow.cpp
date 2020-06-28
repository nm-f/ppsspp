#include <Common/CommonTypes.h>
#include <Core/MemMap.h>
#include <Core/System.h>
#include "memwindow.h"

MemWindow::MemWindow(QWidget* parent) {
    isHidden = true;
    this->setParent(parent);
    this->resize(320, 480);
    InitGuiElements();
    this->show();
    isHidden = false;
}

void MemWindow::toggleVisible(){
    if (isHidden) {
        this->show();
        isHidden = false;
    } else {
        this->hide();
        isHidden = true;
    }
}

void MemWindow::InitGuiElements() {
    mainLayout = new QVBoxLayout(this);
    buttonBox = new QHBoxLayout(this);
    contentBox = new QHBoxLayout(this);

    mainLayout->addLayout(buttonBox);
    mainLayout->addLayout(contentBox);

    imageLabel = new QLabel(this);
    QImage image("happyguy.png");
    imageLabel->setPixmap(QPixmap::fromImage(image));

    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    contentBox->addWidget(scrollArea);
    scrollArea->show();

    searchButton = new QPushButton(QString("Search"), this);
    buttonBox->addWidget(searchButton);

    checkbox = new QCheckBox("Case sensitive", this);
    buttonBox->addWidget(checkbox);
    checkbox->show();

    searchBox = new QLineEdit(this);
    buttonBox->addWidget(searchBox,0);
    searchBox->show();

    searchResultList = new QListWidget(this);
    searchResultList->addItem(QString('item1'));
    searchResultList->addItem(QString('item2'));
    searchResultList->addItem(QString('item3'));
    contentBox->addWidget(searchResultList);
    searchResultList->show();
}

MemWindow::~MemWindow() = default;

std::vector<u32> MemWindow::searchString(std::string searchQuery)
{
    std::vector<u32> searchResAddrs;
    std::vector<u8> searchData;

    auto memLock = Memory::Lock();
    if (!PSP_IsInited())
        return searchResAddrs;

    size_t queryLength = searchQuery.length();
    u32 segmentStart = PSP_GetKernelMemoryBase(); //RAM start
    const u32 segmentEnd = PSP_GetUserMemoryEnd() - (u32)queryLength; //RAM end
    u8* ptr;

    //redraw();
    for (segmentStart = PSP_GetKernelMemoryBase(); segmentStart < segmentEnd; segmentStart++) {
//        if (KeyDownAsync(VK_ESCAPE))
//        {
//            return searchResAddrs;
//        }

        ptr = Memory::GetPointer(segmentStart);
        if (memcmp(ptr, searchQuery.c_str(), queryLength) == 0) {
            searchResAddrs.push_back(segmentStart);
        }
    };
    //redraw();

    return searchResAddrs;
};