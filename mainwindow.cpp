#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , my_complex_tree(nullptr)
    , my_numbers_tree(nullptr)
    , my_words_tree(nullptr)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_to_creat_root_clicked()
{
    // check that user selected number children and type
    bool select_type_tree = true;
    bool select_max_children = true;
    if(!ui->select_complex_numbers->isChecked()&&!ui->select_numbers->isChecked()&&!ui->select_words->isChecked()) {select_type_tree = false;}
    if(ui->button_number_children->value()<=0) {select_max_children = false;}
    if(!select_max_children||!select_type_tree) {
        QString error = "";
        if(!select_type_tree) {error = error + "you must choose tree type.\n";}
        if(!select_max_children) {error = error + "you must choose number above 0 for max children.\n";}
        QMessageBox::information(this, "Error", error+"try agian...");
    }
    else {
        int k = ui->button_number_children->value();
        if(ui->select_complex_numbers->isChecked()) {
            my_complex_tree = new Tree<Complex>(k);
            my_words_tree = nullptr;
            my_numbers_tree = nullptr;
            ui->stackedWidget->setCurrentIndex(3);
        }
        else {
            if(ui->select_numbers->isChecked()) {
                my_numbers_tree = new Tree<double>(k);
                my_words_tree = nullptr;
                my_complex_tree = nullptr;
                ui->stackedWidget->setCurrentIndex(2);
            }
            else {
                if(ui->select_words->isChecked()) {
                    my_words_tree = new Tree<string>(k);
                    my_numbers_tree = nullptr;
                    my_complex_tree = nullptr;
                     ui->stackedWidget->setCurrentIndex(2);
                }
            }
        }
    }
}


void MainWindow::on_button_go_to_menu2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_button_go_to_menu3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_button_go_to_menu1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_button_go_to_menu4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_button_go_to_menu5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_button_create_root_continue_to_creat_tree_clicked()
{
    QString input = ui->input_root_value->text();
    if(input.isEmpty()) {
        QMessageBox::information(this, "Error", "you must enter value to creat root! lets try agian...");
    }
    else {
        if(this->my_numbers_tree) {
            bool isDouble;
            double doubleValue = input.toDouble(&isDouble);
            if(isDouble) {
                this->my_numbers_tree->add_root(doubleValue);
                QTreeWidgetItem* root = new QTreeWidgetItem(ui->treeWidget);
                root->setText(0, input);
                ui->treeWidget->addTopLevelItem(root);
                ui->input_root_value->clear();
                ui->stackedWidget->setCurrentIndex(4);
            }
            else {
                QMessageBox::information(this, "Error", "the input box should contian number(double)! lets try agian...");
            }
        }
        else {
            this->my_words_tree->add_root(input.toStdString());
            QTreeWidgetItem* root = new QTreeWidgetItem(ui->treeWidget);
            root->setText(0, input);
            ui->treeWidget->addTopLevelItem(root);
            ui->input_root_value->clear();
            ui->stackedWidget->setCurrentIndex(4);
        }
    }
}


void MainWindow::on_go_to_add_complex_nodes_clicked()
{
    QString input1 = ui->input_complex_root_value1->text();
    QString input2 = ui->input_complex_root_value2->text();
    if(input1.isEmpty()||input2.isEmpty()) {
        QMessageBox::information(this, "Error", "you must enter value to creat root! lets try agian...");
    }
    else {
        bool isDouble1;
        bool isDouble2;
        double doubleValue1 = input1.toDouble(&isDouble1);
        double doubleValue2 = input2.toDouble(&isDouble2);
        if(isDouble1&&isDouble2) {
            Complex node(doubleValue1, doubleValue2);
            this->my_complex_tree->add_root(node);
            QTreeWidgetItem* root = new QTreeWidgetItem(ui->treeWidget_complex);
            root->setText(0, "("+input1+", "+input2+"i)");
            ui->treeWidget_complex->addTopLevelItem(root);
            ui->input_complex_root_value1->clear();
            ui->input_complex_root_value2->clear();
            ui->stackedWidget->setCurrentIndex(5);
        }
        else {
            QMessageBox::information(this, "Error", "both of the input box should contian number(double)! lets try agian...");
        }
    }
}


void MainWindow::on_button_continue_to_print_page_clicked()
{
    ui->input_value_Node_father->clear();
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_button_go_to_print_page_clicked()
{
    ui->input_value_conmplex_father_node_1->clear();
    ui->input_value_conmplex_father_node_2->clear();
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_button_to_add_Node_page_clicked()
{
    if(!this->my_complex_tree) {ui->stackedWidget->setCurrentIndex(4);;}
    else {ui->stackedWidget->setCurrentIndex(5);}
}


void MainWindow::on_button_create_complex_node_clicked()
{

    QString input_value_node1 = ui->input_value_conmplex_node_1->text();
    QString input_value_node2 = ui->input_value_conmplex_node_2->text();
    QString input_value_father_node1 = ui->input_value_conmplex_father_node_1->text();
    QString input_value_father_node2 = ui->input_value_conmplex_father_node_2->text();
    if(input_value_node1.isEmpty()||input_value_node2.isEmpty()||input_value_father_node1.isEmpty()||input_value_father_node2.isEmpty()) {
        QMessageBox::information(this, "Error", "you must enter value of node and his father to creat node! lets try agian...");
    }
    else {
        bool isDouble1;
        bool isDouble2;
        bool isDouble3;
        bool isDouble4;
        double doubleValue1_node = input_value_node1.toDouble(&isDouble1);
        double doubleValue2_node = input_value_node2.toDouble(&isDouble2);
        double doubleValue1_father = input_value_father_node1.toDouble(&isDouble3);
        double doubleValue2_father = input_value_father_node2.toDouble(&isDouble4);
        if(isDouble1&&isDouble2&&isDouble3&&isDouble4) {
            Complex node(doubleValue1_node, doubleValue2_node);
            Complex father(doubleValue1_father, doubleValue2_father);
            if(this->my_complex_tree->add_sub_node(father, node)){
                this->add_child_node("("+input_value_father_node1+", "+input_value_father_node2+"i)", "("+input_value_node1+", "+input_value_node2+"i)");
                this->ui->input_value_conmplex_node_1->clear();
                this->ui->input_value_conmplex_node_2->clear();
            }
        }
        else {
            QMessageBox::information(this, "Error", "the input boxs should contain numbers(double)! lets try agian...");
        }
    }
}


void MainWindow::on_button_create_Node_clicked()
{

    QString input_value_node = ui->input_new_Node_value->text();
    QString input_value_father = ui->input_value_Node_father->text();
    if(input_value_father.isEmpty()||input_value_node.isEmpty()) {
        QMessageBox::information(this, "Error", "you must enter value of node and his father to creat node! lets try agian...");
    }
    else {
        if(this->my_numbers_tree) {
            bool isDouble1;
            bool isDouble2;
            double doubleValue_node = input_value_node.toDouble(&isDouble1);
            double doubleValue_father = input_value_father.toDouble(&isDouble2);
            if(isDouble1&&isDouble2) {
                if(this->my_numbers_tree->add_sub_node(doubleValue_father, doubleValue_node)) {
                    this->add_child_node(input_value_father, input_value_node);
                }
            }
            else {
                QMessageBox::information(this, "Error", "the input boxs should contain numbers(double)! lets try agian...");
            }
        }
        else {
            if(this->my_words_tree->add_sub_node(input_value_father.toStdString(), input_value_node.toStdString())) {
                this->add_child_node(input_value_father, input_value_node);
            }
        }
    }
}

void MainWindow::add_child_node(const QString& father, const QString& node) {
    QTreeWidgetItem* parentItem = findTreeItemByValue(father);
    if (!parentItem) {
        QMessageBox::warning(this, "Parent "+father+" Not Found", "The specified parent node was not found.");
        return;
    }

    QTreeWidgetItem* childItem = new QTreeWidgetItem();
    childItem->setText(0, node);
    parentItem->addChild(childItem);
}

QTreeWidgetItem* MainWindow::findTreeItemByValue(const QString& value)
{
    QList<QTreeWidgetItem*> items;
    if(this->my_complex_tree) {
        items = ui->treeWidget_complex->findItems(value, Qt::MatchContains | Qt::MatchRecursive, 0);
    }
    else {
        items = ui->treeWidget->findItems(value, Qt::MatchContains | Qt::MatchRecursive, 0);
    }
    if (!items.isEmpty()) {
        return items.first();
    }
    return nullptr;
}


void MainWindow::on_button_print_begin_end_clicked()
{
    std::ostringstream output;
    if(this->my_complex_tree) {this->my_complex_tree->printTreeBaseoNumber(output, 0);}
    else if(this->my_numbers_tree) {this->my_numbers_tree->printTreeBaseoNumber(output, 0);}
    else {this->my_words_tree->printTreeBaseoNumber(output, 0);}

    this->ui->textEdit_output_tree->setPlainText(this->streamToQString(output));
}

void MainWindow::on_button_print_BFS_clicked()
{
    std::ostringstream output;
    if(this->my_complex_tree) {this->my_complex_tree->printTreeBaseoNumber(output, 1);}
    else if(this->my_numbers_tree) {this->my_numbers_tree->printTreeBaseoNumber(output, 1);}
    else {this->my_words_tree->printTreeBaseoNumber(output, 1);}

    this->ui->textEdit_output_tree->setPlainText(this->streamToQString(output));
}


void MainWindow::on_button_print_DFS_clicked()
{
    std::ostringstream output;
    if(this->my_complex_tree) {this->my_complex_tree->printTreeBaseoNumber(output, 2);}
    else if(this->my_numbers_tree) {this->my_numbers_tree->printTreeBaseoNumber(output, 2);}
    else {this->my_words_tree->printTreeBaseoNumber(output, 2);}

    this->ui->textEdit_output_tree->setPlainText(this->streamToQString(output));
}


void MainWindow::on_button_print_in_order_clicked()
{
    std::ostringstream output;
    if(this->my_complex_tree) {this->my_complex_tree->printTreeBaseoNumber(output, 3);}
    else if(this->my_numbers_tree) {this->my_numbers_tree->printTreeBaseoNumber(output, 3);}
    else {this->my_words_tree->printTreeBaseoNumber(output, 3);}

    this->ui->textEdit_output_tree->setPlainText(this->streamToQString(output));
}


void MainWindow::on_button_print_pre_order_clicked()
{
    std::ostringstream output;
    if(this->my_complex_tree) {this->my_complex_tree->printTreeBaseoNumber(output, 4);}
    else if(this->my_numbers_tree) {this->my_numbers_tree->printTreeBaseoNumber(output, 4);}
    else {this->my_words_tree->printTreeBaseoNumber(output, 4);}

    this->ui->textEdit_output_tree->setPlainText(this->streamToQString(output));
}


void MainWindow::on_button_print_post_order_clicked()
{
    std::ostringstream output;
    if(this->my_complex_tree) {this->my_complex_tree->printTreeBaseoNumber(output, 5);}
    else if(this->my_numbers_tree) {this->my_numbers_tree->printTreeBaseoNumber(output, 5);}
    else {this->my_words_tree->printTreeBaseoNumber(output, 5);}

    this->ui->textEdit_output_tree->setPlainText(this->streamToQString(output));
}


void MainWindow::on_button_print_and_tree_to_min_heap_clicked()
{
    std::ostringstream output;
    if(this->my_complex_tree) {
        this->my_complex_tree->printTreeBaseoNumber(output, 6);}
    else if(this->my_numbers_tree) {this->my_numbers_tree->printTreeBaseoNumber(output, 6);}
    else {output << "Error this is a string tree you can not convort to min heap...";}

    this->ui->textEdit_output_tree->setPlainText(this->streamToQString(output));
}



QString MainWindow::streamToQString(std::ostringstream& stream) {
    std::string str = stream.str();
    return QString::fromStdString(str);
}

