#include "QtScatterPlot.h"
#include "QtScatterPlotPlugin.h"

#include <QtCore/QtPlugin>

QtScatterPlotPlugin::QtScatterPlotPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void QtScatterPlotPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool QtScatterPlotPlugin::isInitialized() const
{
    return initialized;
}

QWidget *QtScatterPlotPlugin::createWidget(QWidget *parent)
{
    return new QtScatterPlot(parent);
}

QString QtScatterPlotPlugin::name() const
{
    return "QtScatterPlot";
}

QString QtScatterPlotPlugin::group() const
{
    return "My Plugins";
}

QIcon QtScatterPlotPlugin::icon() const
{
    return QIcon();
}

QString QtScatterPlotPlugin::toolTip() const
{
    return QString();
}

QString QtScatterPlotPlugin::whatsThis() const
{
    return QString();
}

bool QtScatterPlotPlugin::isContainer() const
{
    return false;
}

QString QtScatterPlotPlugin::domXml() const
{
    return "<widget class=\"QtScatterPlot\" name=\"QtScatterPlot\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>100</width>\n"
        "   <height>100</height>\n"
        "  </rect>\n"
        " </property>\n"
        "</widget>\n";
}

QString QtScatterPlotPlugin::includeFile() const
{
    return "QtScatterPlot.h";
}
