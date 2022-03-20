/****************************************************************************
** Meta object code from reading C++ file 'videochat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QQ/videochat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videochat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VideoChat_t {
    QByteArrayData data[7];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoChat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoChat_t qt_meta_stringdata_VideoChat = {
    {
QT_MOC_LITERAL(0, 0, 9), // "VideoChat"
QT_MOC_LITERAL(1, 10, 18), // "image_process_done"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "close_sig"
QT_MOC_LITERAL(4, 40, 12), // "displayImage"
QT_MOC_LITERAL(5, 53, 5), // "image"
QT_MOC_LITERAL(6, 59, 12) // "process_data"

    },
    "VideoChat\0image_process_done\0\0close_sig\0"
    "displayImage\0image\0process_data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoChat[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   36,    2, 0x0a /* Public */,
       6,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,    2,    5,
    QMetaType::Void,

       0        // eod
};

void VideoChat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoChat *_t = static_cast<VideoChat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->image_process_done(); break;
        case 1: _t->close_sig(); break;
        case 2: _t->displayImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2]))); break;
        case 3: _t->process_data(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VideoChat::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoChat::image_process_done)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (VideoChat::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoChat::close_sig)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject VideoChat::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VideoChat.data,
      qt_meta_data_VideoChat,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VideoChat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoChat::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VideoChat.stringdata0))
        return static_cast<void*>(const_cast< VideoChat*>(this));
    return QWidget::qt_metacast(_clname);
}

int VideoChat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void VideoChat::image_process_done()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void VideoChat::close_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
