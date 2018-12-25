#include <iostream>
#include <memory>

#include "mainwindow.hh"
#include "sprite.hh"


int main()
{
    auto m = std::make_unique<Ui::MainWindow>();

    m->start();

    return 0;
}