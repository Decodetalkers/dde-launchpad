// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QSortFilterProxyModel>

class FavoritedProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    static FavoritedProxyModel &instance()
    {
        static FavoritedProxyModel _instance;
        return _instance;
    }

    Q_INVOKABLE bool exists(const QString & desktopId);
    Q_INVOKABLE void addFavorite(const QString & desktopId);
    Q_INVOKABLE void removeFavorite(const QString & desktopId);

    // QSortFilterProxyModel interface
protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
    bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const override;

private:
    explicit FavoritedProxyModel(QObject *parent = nullptr);

    void load();
    void save();

    QStringList m_favoritedAppIds;
};
