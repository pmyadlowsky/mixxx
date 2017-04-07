#ifndef WBEATSPINBOX_H
#define WBEATSPINBOX_H

#include "control/controlobject.h"
#include "control/controlproxy.h"
#include "widget/wbasewidget.h"
#include "skin/skincontext.h"
#include <QDoubleSpinBox>

class ControlProxy;

class WBeatSpinBox : public QDoubleSpinBox, public WBaseWidget {
    Q_OBJECT
  public:
    WBeatSpinBox(QWidget *parent=nullptr,
                        ControlObject* pValueControl=nullptr,
                        int decimals=5,
                        double minimum=0.03125, double maximum=512.00);

    void setup(const QDomNode& node, const SkinContext& context);

  private slots:
    void slotSpinboxValueChanged(double newValue);
    void slotControlValueChanged(double newValue);

    QString textFromValue(double value) const override;
    double valueFromText(const QString& text) const override;
    QValidator::State validate(QString& input, int& pos) const override;

  private:
    void stepBy(int steps) override;
    QString fractionString(int numerator, int denominator) const;

    ControlProxy m_valueControl;
    static QRegExp s_regexpBlacklist;

    // for font scaling
    bool event(QEvent* pEvent) override;
    double m_scaleFactor;
};

#endif
