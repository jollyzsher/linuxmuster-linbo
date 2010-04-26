#ifndef LINBOINPUTBOXIMPL_HH
#define LINBOINPUTBOXIMPL_HH

#include "ui_linboInputBox.h"

#include <qobject.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qvariant.h>
#include <qwidget.h>
#include <qdialog.h>
#include <q3textbrowser.h>
#include <qstringlist.h>
#include <qstring.h>
#include <QProcess>
#include "linboGUIImpl.hh"
#include "linboProgressImpl.hh"
#include "linboDialog.hh"

class linboInputBoxImpl : public QWidget, public Ui::linboInputBox, public linboDialog
{
  Q_OBJECT

private:
  QString line;
  QStringList myCommand;
  QStringList arguments;
  linboProgressImpl *progwindow;
  QProcess *process;
  linboGUIImpl* app;
  QWidget *myMainApp,*myParent;
  Q3TextBrowser *Console;

public slots:
  void readFromStdout();
  void readFromStderr();
  void processFinished( int retval,
                        QProcess::ExitStatus status);
  virtual void precmd();
  virtual void postcmd();



public:
  linboInputBoxImpl( QWidget* parent = 0);
  ~linboInputBoxImpl();

  void setTextBrowser( Q3TextBrowser* newBrowser );
  virtual void setCommand(const QStringList& arglist);
  virtual QStringList getCommand();
  void setMainApp( QWidget* newMainApp );
  

};
#endif
