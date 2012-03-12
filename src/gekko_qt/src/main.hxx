#include <QMainWindow>

#include "ui_main.h"

class QFileSystemModel;
class GImageInfo;
class EmuThread;

class GMainWindow : public QMainWindow
{
    Q_OBJECT

    // TODO: Make use of this!
    enum {
        UI_IDLE,
        UI_EMU_BOOTING,
        UI_EMU_RUNNING,
        UI_EMU_STOPPING,
    };

public:
    GMainWindow();
    ~GMainWindow();

private:
	void BootGame(const char* filename);

private slots:
    void OnStartGame();
	void OnMenuLoadImage();
    void OnFileBrowserDoubleClicked(const QModelIndex&);
	void OnFileBrowserSelectionChanged();

signals:
//    UpdateUIState();

private:
    Ui::MainWindow ui;
    QFileSystemModel* file_browser_model;
	GImageInfo* image_info;

	EmuThread* emu_thread;
};
