#pragma once

#include <QMainWindow>
#include <QWebEngineView>
#include <QWebEngineProfile>

class FreezerWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit FreezerWindow(QWidget *parent = nullptr);

private:
    QWebEngineView *view;
    QWebEngineProfile *profile;
};
