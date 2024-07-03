#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <sstream>
#include <QMainWindow>
#include <QTreeWidget>
#include "complex.hpp"
#include "Tree.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_to_creat_root_clicked();

    void on_button_go_to_menu2_clicked();

    void on_button_go_to_menu3_clicked();

    void on_button_go_to_menu1_clicked();

    void on_button_go_to_menu4_clicked();

    void on_button_go_to_menu5_clicked();

    void on_button_create_root_continue_to_creat_tree_clicked();

    void on_go_to_add_complex_nodes_clicked();

    void on_button_continue_to_print_page_clicked();

    void on_button_go_to_print_page_clicked();

    void on_button_to_add_Node_page_clicked();

    void on_button_create_complex_node_clicked();

    void on_button_create_Node_clicked();

    QString streamToQString(std::ostringstream& stream);

    void on_button_print_begin_end_clicked();

    void on_button_print_BFS_clicked();

    void on_button_print_DFS_clicked();

    void on_button_print_in_order_clicked();

    void on_button_print_pre_order_clicked();

    void on_button_print_post_order_clicked();

    void on_button_print_and_tree_to_min_heap_clicked();

private:
    Ui::MainWindow *ui;
    Tree<Complex>* my_complex_tree;
    Tree<double>* my_numbers_tree;
    Tree<string>* my_words_tree;

    void add_child_node(const QString& father, const QString& node);
    QTreeWidgetItem* findTreeItemByValue(const QString& value);

};
#endif // MAINWINDOW_H
