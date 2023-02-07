#ifndef HELPWIDGET_H
#define HELPWIDGET_H

#include <QWidget>

namespace Ui {
class WhatInputWindow;
}

class WhatInputWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WhatInputWindow(QWidget *parent = nullptr);
    ~WhatInputWindow();

private:
    Ui::WhatInputWindow *ui;
};

#endif // HELPWIDGET_H
