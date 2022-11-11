/***********************************************************************************************************************
**
** Copyright (C) 2022 BaseALT Ltd. <org@basealt.ru>
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
***********************************************************************************************************************/

#ifndef SCRIPTS_CONTENT_WIDGET_H
#define SCRIPTS_CONTENT_WIDGET_H

#include <QtWidgets>

#include "../../../src/core/common.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class ScriptsContentWidget;
}
QT_END_NAMESPACE

class QDataWidgetMapper;

namespace ModelView
{
class ViewModel;
class ViewModelDelegate;
class SessionItem;
class SessionModel;
} // namespace ModelView

namespace scripts_plugin
{
class GPUI_SYMBOL_EXPORT ScriptsContentWidget : public QWidget
{
public:
    Q_OBJECT

public:
    explicit ScriptsContentWidget(QWidget *parent                         = nullptr,
                                  ModelView::SessionModel *newSourceModel = nullptr);
    ~ScriptsContentWidget() override;

    void setItem(ModelView::SessionItem *item);
    void setSelectionModel(QItemSelectionModel *newSelectionModel);

signals:
    void onAccepted();

private slots:
    void on_listView_doubleClicked(const QModelIndex &index);

    void on_buttonBox_accepted();

private:
    ScriptsContentWidget(const ScriptsContentWidget &) = delete;            // copy ctor
    ScriptsContentWidget(ScriptsContentWidget &&)      = delete;            // move ctor
    ScriptsContentWidget &operator=(const ScriptsContentWidget &) = delete; // copy assignment
    ScriptsContentWidget &operator=(ScriptsContentWidget &&) = delete;      // move assignment

private:
    ModelView::SessionModel *sourceModel = nullptr;

    std::unique_ptr<ModelView::ViewModel> viewModel;
    std::unique_ptr<ModelView::ViewModelDelegate> delegate;
    std::unique_ptr<QDataWidgetMapper> mapper;

private:
    QItemSelectionModel *selectionModel = nullptr;

private:
    Ui::ScriptsContentWidget *ui{nullptr};
};

} // namespace scripts_plugin

Q_DECLARE_METATYPE(scripts_plugin::ScriptsContentWidget *)

#endif //SCRIPTS_CONTENT_WIDGET_H
