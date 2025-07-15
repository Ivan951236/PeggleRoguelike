// main.cpp
#include <gtkmm.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>

class MainWindow : public Gtk::Window
{
public:
  MainWindow();
  virtual ~MainWindow() {}

protected:
  // Signal handler
  void on_generate_clicked();

  // Widgets
  Gtk::Box      m_vbox;            // vertical container
  Gtk::Button   m_button;          // “Generate” button
  Gtk::Notebook m_notebook;        // holds three pages

  // Grids for each page
  Gtk::Grid     m_grid_inv;        // Inventory: 3 cols × 1 row
  Gtk::Grid     m_grid_peggle;     // Peggle Levels: 8 cols × 2 rows
  Gtk::Grid     m_grid_boss;       // Boss Level: 1 × 1
};

MainWindow::MainWindow()
: m_vbox(Gtk::ORIENTATION_VERTICAL, 10),
  m_button("Generate")
{
  set_title("Inventory / Peggle / Boss Generator");
  set_default_size(600, 300);

  // pack button and notebook into vbox
  m_vbox.pack_start(m_button, Gtk::PACK_SHRINK);
  m_vbox.pack_start(m_notebook, Gtk::PACK_EXPAND_WIDGET);
  add(m_vbox);

  // prepare each grid’s spacing
  for (auto* g : { &m_grid_inv, &m_grid_peggle, &m_grid_boss })
  {
    g->set_row_spacing(5);
    g->set_column_spacing(5);
    g->set_border_width(10);
  }

  // add pages to notebook
  m_notebook.append_page(m_grid_inv,    "Inventory");
  m_notebook.append_page(m_grid_peggle, "Peggle Levels");
  m_notebook.append_page(m_grid_boss,   "Boss Level");

  // connect signal
  m_button.signal_clicked().connect(
    sigc::mem_fun(*this, &MainWindow::on_generate_clicked));

  // seed RNG once at startup
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  show_all_children();
}

void MainWindow::on_generate_clicked()
{
  // clear any previous children
  for (auto* w : m_grid_inv.get_children())    m_grid_inv.remove(*w);
  for (auto* w : m_grid_peggle.get_children()) m_grid_peggle.remove(*w);
  for (auto* w : m_grid_boss.get_children())   m_grid_boss.remove(*w);

  //
  // 1) Inventory (3×1): single number between 1–10
  //
  for (int i = 0; i < 3; ++i)
  {
    int n = (std::rand() % 10) + 1;
    auto lbl = Gtk::make_managed<Gtk::Label>(std::to_string(n));
    lbl->set_justify(Gtk::JUSTIFY_CENTER);
    m_grid_inv.attach(*lbl, i, 0, 1, 1);
  }

  //
  // 2) Peggle Levels (8×2, 15 cells): first digit 1–45, second 1–10
  //
  for (int i = 0; i < 15; ++i)
  {
    int d1 = (std::rand() % 45) + 1;
    int d2 = (std::rand() % 10) + 1;
    std::ostringstream ss;
    ss << std::setfill('0') << std::setw(2) << d1
       << ", " 
       << std::setfill('0') << std::setw(2) << d2;
    auto lbl = Gtk::make_managed<Gtk::Label>(ss.str());
    lbl->set_justify(Gtk::JUSTIFY_CENTER);
    int col = i % 8;
    int row = i / 8;
    m_grid_peggle.attach(*lbl, col, row, 1, 1);
  }

  //
  // 3) Boss Level (1×1): first digit 50–55, second 1–10
  //
  {
    int d1 = (std::rand() % 6) + 50;  // 50–55
    int d2 = (std::rand() % 10) + 1;  // 1–10
    std::ostringstream ss;
    ss << std::setfill('0') << std::setw(2) << d1
       << ", "
       << std::setfill('0') << std::setw(2) << d2;
    auto lbl = Gtk::make_managed<Gtk::Label>(ss.str());
    lbl->set_justify(Gtk::JUSTIFY_CENTER);
    m_grid_boss.attach(*lbl, 0, 0, 1, 1);
  }

  // refresh the display
  show_all_children();
}

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create(
    argc, argv, "com.example.inventory_peggle_boss");

  MainWindow window;
  return app->run(window);
}