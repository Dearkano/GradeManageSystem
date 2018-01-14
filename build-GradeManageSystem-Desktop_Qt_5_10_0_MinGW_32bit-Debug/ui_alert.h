/********************************************************************************
** Form generated from reading UI file 'alert.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALERT_H
#define UI_ALERT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Alert
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *Alert)
    {
        if (Alert->objectName().isEmpty())
            Alert->setObjectName(QStringLiteral("Alert"));
        Alert->resize(332, 179);
        buttonBox = new QDialogButtonBox(Alert);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-80, 120, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Alert);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 60, 72, 15));

        retranslateUi(Alert);
        QObject::connect(buttonBox, SIGNAL(accepted()), Alert, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Alert, SLOT(reject()));

        QMetaObject::connectSlotsByName(Alert);
    } // setupUi

    void retranslateUi(QDialog *Alert)
    {
        Alert->setWindowTitle(QApplication::translate("Alert", "Dialog", nullptr));
        label->setText(QApplication::translate("Alert", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Alert: public Ui_Alert {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALERT_H
