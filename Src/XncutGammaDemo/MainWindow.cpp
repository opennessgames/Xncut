/*
 * @Author: xixi_
 * @Date: 2026-10-03 22:50:54
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-06 16:03:05
 * @FilePath: /Xncut/Src/XncutGammaDemo/MainWindow.cpp
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#include "MainWindow.h"
#include <QToolBar>
#include <QGridLayout>
#include "XncutImageWidget.h"
#include <QFormLayout>
#include <QDoubleSpinBox>
#include <QFileDialog>
#include "MilkshakeGamma.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QToolBar *mainToolBar = addToolBar("Main Tool Bar");
    mainToolBar->addAction("Open", this, &MainWindow::onOpenTriggered);
    mainToolBar->addAction("Reset", this, &MainWindow::onResetTriggered);
    mainToolBar->addAction("Clear", this, &MainWindow::onClearTriggered);
    mainToolBar->addAction("Save", this, &MainWindow::onSaveTriggered);

    QWidget *centralWidget = new QWidget();
    setCentralWidget(centralWidget);

    m_imgWidget = new XncutImageWidget();
    m_imgWidget->setMinimumWidth(570);
    m_imgWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_gammaSpinBox = new QDoubleSpinBox();
    m_gammaSpinBox->setRange(0.00, 2.20);
    m_gammaSpinBox->setSingleStep(0.01);
    m_gammaSpinBox->setValue(1.0);

    QFormLayout *m_formLayout = new QFormLayout();
    m_formLayout->insertRow(0, "伽马值:", m_gammaSpinBox);

    QGridLayout *centralLayout = new QGridLayout();
    centralLayout->addWidget(m_imgWidget, 0, 0, 1, 1);
    centralLayout->addLayout(m_formLayout, 0, 1, 1, 1);
    centralLayout->setColumnMinimumWidth(1, 300);
    centralLayout->setColumnStretch(0, 1);
    centralLayout->setColumnStretch(1, 0);
    centralWidget->setLayout(centralLayout);

    connect(m_gammaSpinBox, &QDoubleSpinBox::valueChanged,
            this, &MainWindow::onGammaSpinBoxValueChanged,
            Qt::UniqueConnection);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onOpenTriggered()
{
    const QString filePath = QFileDialog::getOpenFileName(this);
    m_rawImg.load(filePath);
    emit m_gammaSpinBox->valueChanged(m_gammaSpinBox->value());
}

void MainWindow::onResetTriggered()
{
    if (m_rawImg.isNull())
    {
        return;
    }

    m_imgWidget->setImages(m_rawImg);

    QSignalBlocker SignalBlocker(m_gammaSpinBox);
    m_gammaSpinBox->setValue(1.0);
}

void MainWindow::onClearTriggered()
{
    m_rawImg = QImage();
    m_imgWidget->setImages(QImage());
}

void MainWindow::onSaveTriggered()
{
}

void MainWindow::onGammaSpinBoxValueChanged(double Gamma)
{
    if (m_rawImg.isNull())
    {
        return;
    }

    /* 获取查找表 */
    unsigned char Lookup[256];
    MilkshakeGammaGetLookup(Gamma, Lookup);

    /* 执行映射 */
    QImage workImg = m_rawImg.copy();
    MilkshakeGammaMapper(workImg.bits(),
                         workImg.width(), workImg.height(),
                         workImg.bytesPerLine() / workImg.width(),
                         Lookup);

    /* 渲染出来 */
    m_imgWidget->setImages(workImg);
}
