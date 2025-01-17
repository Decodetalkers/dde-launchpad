// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QObject>
#include <QList>

class ItemsPage : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int pageCount READ pageCount NOTIFY pageCountChanged)
    Q_PROPERTY(int maxItemCountPerPage READ maxItemCountPerPage CONSTANT)

public:
    explicit ItemsPage(int maxItemCountPerPage, QObject * parent = nullptr);
    explicit ItemsPage(const QString & name, int maxItemCountPerPage, QObject * parent = nullptr);
    ~ItemsPage();

    QString name() const;
    void setName(const QString & name);

    int maxItemCountPerPage() const;

    int pageCount() const;
    QStringList items(int page = 0);
    QStringList firstNItems(int count = 4);

    void appendPage(const QStringList items);
    void appendItem(const QString id, int page = -1);
    void insertItem(const QString id, int page, int pos = 0);
    void moveItem(int from_page, int from_index, int to_page, int to_index);
    void removeItem(const QString id, bool removePageIfPageIsEmpty = true);

    std::tuple<int, int> findItem(const QString & id) const;
    bool contains(const QString & id) const;

signals:
    void nameChanged();
    void pageCountChanged();

private:
    int m_maxItemCountPerPage;
    QString m_displayName;
    QList<QStringList> m_pages;
};
