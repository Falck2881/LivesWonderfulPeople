#include "WhatInputWindow.h"
#include "ui_WhatInputWindow.h"

WhatInputWindow::WhatInputWindow(QWidget *parent):QWidget(parent),ui(new Ui::WhatInputWindow)
{
    ui->setupUi(this);
    move(50,100);
    setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
}

WhatInputWindow::~WhatInputWindow()
{
    delete ui;
}
