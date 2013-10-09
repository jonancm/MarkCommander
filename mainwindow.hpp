// Copyright 2011 Jonán C. Martín
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTemporaryFile>
#include <QVBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QProgressDialog>

#include "terminal.hpp"
#include "rhinoprog.hpp"
#include "rhino_xr4.hpp"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Terminal          terminal;
    RhinoProg        *editorProg;
    QString           receivedProgFilePath;
    bool              showFileOnTerminal;
    QLabel           *connectionStatus;
    QLabel           *editorFileStatus;
    QDialog          *errorCodesDialog;
    QDialog          *cmdRefDialog;

    QProgressDialog  *getConfigProgressDialog;
    QTimer           *getConfigTimer;

    QDialog          *configureControllerDialog;
    QVBoxLayout      *layout;
    QGridLayout      *grid;
    QHBoxLayout      *hbox;
    QComboBox        *configBits[6];
    bool              configBitChanged[6];
    QPushButton      *applyBtn;
    QPushButton      *closeBtn;
    QPushButton      *revertBtn;

    RhinoXR4          xr4;

    double            dirkinOldValue[5];

    //bool              alreadyGoneToKinHome;

    void insertPrompt();
    void lockTerminal();
    void unlockTerminal();
    void closeConnection();
    void insertTxtIntoTerm(QString txt);
    void enableTerminalActions();
    void disableTerminalActions();
    void createConfigurationDialog();
    void showGetConfigProgressDialog();
    void closeGetConfigProgressDialog();
    void updateDirkin();
    void updateInvkin();
    void enableKinematics();
    void disableKinematics();

    void moveMotorB(int steps, bool keepKin);
    void moveMotorC(int steps, bool keepKin);
    void moveMotorD(int steps, bool keepKin);
    void moveMotorE(int steps, bool keepKin);
    void moveMotorF(int steps, bool keepKin);
    void moveMotorCRel(int steps, bool keepKin);
    void moveMotorDRel(int steps, bool keepKin);

private slots:
    void on_pushButton_computeInvKin_clicked();
    void on_pushButton_computeDirKin_clicked();
    void on_comboBox_invkinVersion_currentIndexChanged(int index);
    void on_pushButton_copyInvkin_clicked();
    void on_actionSetSoftHome_triggered();
    void on_actionGoToKinHome_triggered();
    void on_pushButton_copyDirkin_clicked();
    void on_pushButton_invkinGoToPos_clicked();
    void on_lineEdit_invkinArmMatrixP3_textChanged(QString newText);
    void on_lineEdit_invkinArmMatrixP2_textChanged(QString newText);
    void on_lineEdit_invkinArmMatrixP1_textChanged(QString newText);
    void on_lineEdit_invkinArmMatrixA3_textChanged(QString newText);
    void on_lineEdit_invkinArmMatrixA2_textChanged(QString newText);
    void on_lineEdit_invkinArmMatrixA1_textChanged(QString newText);
    void on_lineEdit_invkinArmMatrixS3_textChanged(QString newText);
    void on_lineEdit_invkinArmMatrixS2_textChanged(QString newText);
    void on_lineEdit_invkinArmMatrixS1_textChanged(QString newText);
    void on_lineEdit_invkinArmMatrixN3_textChanged(QString newText);
    void on_lineEdit_invkinArmMatrixN2_textChanged(QString newText);
    void on_lineEdit_invkinArmMatrixN1_textChanged(QString newText);
    void on_doubleSpinBox_invkinTheta5B_valueChanged(double angle);
    void on_doubleSpinBox_invkinTheta4C_valueChanged(double angle);
    void on_doubleSpinBox_invkinTheta3D_valueChanged(double angle);
    void on_doubleSpinBox_invkinTheta2E_valueChanged(double angle);
    void on_doubleSpinBox_invkinTheta1F_valueChanged(double angle);
    void on_pushButton_dirkinGoToPos_clicked();
    void on_dial_dirkinTheta5B_valueChanged(int value);
    void on_dial_dirkinTheta4C_valueChanged(int value);
    void on_dial_dirkinTheta3D_valueChanged(int value);
    void on_dial_dirkinTheta2E_valueChanged(int value);
    void on_dial_dirkinTheta1F_valueChanged(int value);
    void on_doubleSpinBox_dirkinTheta5B_valueChanged(double angle);
    void on_doubleSpinBox_dirkinTheta4C_valueChanged(double angle);
    void on_doubleSpinBox_dirkinTheta3D_valueChanged(double angle);
    void on_doubleSpinBox_dirkinTheta2E_valueChanged(double angle);
    void on_doubleSpinBox_dirkinTheta1F_valueChanged(double angle);
    void on_actionInvKin_triggered();
    void on_actionDirKin_triggered();
    void on_actionTerminal_triggered();
    void on_actionConfigureController_triggered();
    void on_actionSoftHome_triggered();
    void on_actionHardHome_triggered();
    void on_actionCommandRef_triggered();
    void on_actionAboutThisApp_triggered();
    void on_actionErrorCodes_triggered();
    void on_actionClearTerminal_triggered();
    void on_actionSaveTerminalOutput_triggered();
    void on_actionCloseConnection_triggered();
    void on_actionConnectToController_triggered();
    void on_actionReceiveProgram_triggered();
    void on_actionTransmitProgram_triggered();
    void on_pushButton_sendCmd_clicked();
    void quitApp();

public slots:
    void getCmdResponse(QString response);
    void handleTimeout(int time);
    void getProgram(RhinoProg *prog);
    void getConfiguration(QString configString);
    void handleConfigurationTimeout(int time);
    void on_actionApplyConfiguration_triggered();
    void on_actionRevertConfiguration_triggered();
    void on_actionCloseConfiguration_triggered();
    void restoreSlotsAfterConfig();
    void systemModeChanged(int curIndex);
    // void pendantStatusChanged(int curIndex);
    void controllerModeChanged(int curIndex);
    void robotTypeChanged(int curIndex);
    void gripperModeChanged(int curIndex);
    void jointModeChanged(int curIndex);
    void getConfigTimerTimeout();

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
