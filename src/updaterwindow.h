/*********************************************************************************************
* Mozila License
* Just a meantime project to see the ability of qt, the framework that my OS might be based on
* And for those linux users that beleive in the power of notes
*********************************************************************************************/

#ifndef UPDATERWINDOW_H
#define UPDATERWINDOW_H

#include <QWidget>

namespace Ui {
class UpdaterWindow;
}

class QMouseEvent;
class QNetworkReply;
class QSimpleUpdater;
class QNetworkAccessManager;

class UpdaterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UpdaterWindow (QWidget *parent = 0);
    ~UpdaterWindow();

public slots:
    void checkForUpdates (bool silent);

private slots:
    void resetControls();
    void updateTitleLabel();
    void onUpdateAvailable();
    void onDownloadButtonClicked();
    void startDownload (const QUrl& url);
    void openDownload(const QString &file);
    void onCheckFinished (const QString& url);
    void saveFile (qint64 received, qint64 total);
    void calculateSizes (qint64 received, qint64 total);
    void updateProgress (qint64 received, qint64 total);
    void calculateTimeRemaining (qint64 received, qint64 total);

protected:
    void mouseMoveEvent (QMouseEvent* event) Q_DECL_OVERRIDE;
    void mousePressEvent (QMouseEvent* event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent (QMouseEvent *event) Q_DECL_OVERRIDE;

private:
    qreal round (const qreal& input);

private:
    QString m_fileName;
    Ui::UpdaterWindow *m_ui;

    QPoint m_dragPosition;

    bool m_silent;
    int m_mousePressX;
    int m_mousePressY;
    bool m_canMoveWindow;
    bool m_checkingForUpdates;

    uint m_startTime;
    QNetworkReply* m_reply;
    QSimpleUpdater* m_updater;
    QNetworkAccessManager* m_manager;
};

#endif
