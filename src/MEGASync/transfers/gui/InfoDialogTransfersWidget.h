#ifndef INFODIALOGTRANSFERSWIDGET_H
#define INFODIALOGTRANSFERSWIDGET_H

#include <QWidget>
#include <QSortFilterProxyModel>

#include "MegaTransferDelegate.h"
#include "MegaDelegateHoverManager.h"

namespace Ui {
class InfoDialogTransfersWidget;
}

class MegaDelegateHoverManager;
class MegaApplication;
class InfoDialogTransfersProxyModel;

class InfoDialogTransfersWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InfoDialogTransfersWidget(QWidget *parent = 0);
    void setupTransfers();
    ~InfoDialogTransfersWidget();

protected:
    void showEvent(QShowEvent *) override;

private:
    Ui::InfoDialogTransfersWidget *mUi;
    InfoDialogTransfersProxyModel *mProxyModel;
    MegaDelegateHoverManager mViewHoverManager;

private:
    void configureTransferView();
};

#endif // INFODIALOGTRANSFERSWIDGET_H
