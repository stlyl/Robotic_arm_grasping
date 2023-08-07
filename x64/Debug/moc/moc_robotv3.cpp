/****************************************************************************
** Meta object code from reading C++ file 'robotv3.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../robotv3.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robotv3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_robotv3_t {
    QByteArrayData data[16];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_robotv3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_robotv3_t qt_meta_stringdata_robotv3 = {
    {
QT_MOC_LITERAL(0, 0, 7), // "robotv3"
QT_MOC_LITERAL(1, 8, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(4, 55, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(5, 79, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(6, 103, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(7, 127, 23), // "on_pushButton_8_clicked"
QT_MOC_LITERAL(8, 151, 16), // "Deep_Camera_play"
QT_MOC_LITERAL(9, 168, 3), // "Mat"
QT_MOC_LITERAL(10, 172, 6), // "update"
QT_MOC_LITERAL(11, 179, 9), // "Recognize"
QT_MOC_LITERAL(12, 189, 5), // "moveL"
QT_MOC_LITERAL(13, 195, 4), // "data"
QT_MOC_LITERAL(14, 200, 10), // "Delay_MSec"
QT_MOC_LITERAL(15, 211, 4) // "msec"

    },
    "robotv3\0on_pushButton_clicked\0\0"
    "on_pushButton_5_clicked\0on_pushButton_6_clicked\0"
    "on_pushButton_7_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_8_clicked\0Deep_Camera_play\0"
    "Mat\0update\0Recognize\0moveL\0data\0"
    "Delay_MSec\0msec"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_robotv3[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
      10,    0,   76,    2, 0x08 /* Private */,
      11,    0,   77,    2, 0x08 /* Private */,
      12,    1,   78,    2, 0x08 /* Private */,
      14,    1,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::UInt,   15,

       0        // eod
};

void robotv3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<robotv3 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_5_clicked(); break;
        case 2: _t->on_pushButton_6_clicked(); break;
        case 3: _t->on_pushButton_7_clicked(); break;
        case 4: _t->on_pushButton_3_clicked(); break;
        case 5: _t->on_pushButton_8_clicked(); break;
        case 6: { Mat _r = _t->Deep_Camera_play();
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->update(); break;
        case 8: _t->Recognize(); break;
        case 9: _t->moveL((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->Delay_MSec((*reinterpret_cast< uint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject robotv3::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_robotv3.data,
    qt_meta_data_robotv3,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *robotv3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *robotv3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_robotv3.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int robotv3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
