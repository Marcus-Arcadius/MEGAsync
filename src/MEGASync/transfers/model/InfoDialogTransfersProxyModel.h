#ifndef INFODIALOGCURRENTTRANSFERSPROXYMODEL_H
#define INFODIALOGCURRENTTRANSFERSPROXYMODEL_H

#include "TransfersManagerSortFilterProxyModel.h"

class TransferBaseDelegateWidget;
class MegaDelegateHoverManager;

class InfoDialogTransfersProxyModel : public TransfersSortFilterProxyBaseModel
{
    Q_OBJECT

public:
    InfoDialogTransfersProxyModel(QObject* parent);
    ~InfoDialogTransfersProxyModel();

    TransferBaseDelegateWidget* createTransferManagerItem(QWidget *parent) override;

    void setSourceModel(QAbstractItemModel* sourceModel) override;

protected slots:
    void onCopyTransferLinkRequested();
    void onOpenTransferFolderRequested();
    void onRetryTransferRequested();

protected:
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;
    bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const override;

private slots:
    void onUpdateMostPriorityTransfer(int tag);

private:
    mutable int mNextTransferSourceRow;

};

#endif // INFODIALOGCURRENTTRANSFERSPROXYMODEL_H
