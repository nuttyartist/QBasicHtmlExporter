#ifndef QBASICHTML_H
#define QBASICHTML_H
#include <QTextDocument>
#include <QTextFrame>

class QBasicHtmlExporter
{
public:
    QBasicHtmlExporter(QTextDocument *_doc);
    enum ExportMode {
        ExportEntireDocument,
        ExportFragment
    };
    QString toHtml();

private:
    enum StyleMode { EmitStyleTag, OmitStyleTag };
    enum FrameType { TextFrame, TableFrame, RootFrame };
    enum Heading {h1,h2,h3,h4,h5}; // Unfortunately Qt won't allow us to accurately find h6

    void emitFrame(const QTextFrame::Iterator &frameIt);
    void emitTextFrame(const QTextFrame *f);
    void emitBlock(const QTextBlock &block);
    void emitFragment(const QTextFragment &fragment);
    void emitAttribute(const char *attribute, const QString &value);

    QStringList emitCharFormatStyle(const QTextCharFormat &format);

    QString html;
    QTextCharFormat defaultCharFormat;
    const QTextDocument *doc;
    bool fragmentMarkers;
};

#endif // QBASICHTML_H