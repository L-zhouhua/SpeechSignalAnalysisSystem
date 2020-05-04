#include <QtCore/QByteArray>
#include <QtCore/QProcess>
#include <QtWidgets/QMessageBox>
#include "assistant.h"

Assistant::Assistant() : proc(0)
{
}

Assistant::~Assistant()
{
	if (proc && proc->state() == QProcess::Running)
	{
		// ��ͼ��ֹ����
		proc->terminate();
		proc->waitForFinished(3000);
	}
	// ����proc
	delete proc;
}

// ��ʾ�ĵ�
void Assistant::showDocumentation(const QString& page)
{
	if (!startAssistant())
		return;

	QByteArray ba("SetSource ");
	ba.append("qthelp://bookmisClient.myhelp/doc/");
	proc->write(ba + page.toLocal8Bit() + '\n');
}

// ����Qt Assistant
bool Assistant::startAssistant()
{
	// ���û�д������̣����´���һ��
	if (!proc)
		proc = new QProcess();
	// �������û�����У�������assistant������Ӳ���
	if (proc->state() != QProcess::Running)
	{
		QString app = QLatin1String("assistant.exe");
		QStringList args;
		args << QLatin1String("-collectionFile")
			<< QLatin1String("help.qhc");
		proc->start(app, args); // �൱��ִ�����assistant �CcollectionFile myHelp.qhc
		if (!proc->waitForStarted())
		{
			QMessageBox::critical(0, QObject::tr("my help"),
				QObject::tr("Unable to launch Qt Assistant (%1)").arg(app));
			return false;
		}
	}
	return true;
}