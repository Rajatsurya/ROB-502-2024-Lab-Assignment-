#include <memory>
#include <QPainter>
#include <QApplication>
#include <iostream>
#include <thread>
#include <stdio.h>
#include <lcm/lcm-cpp.hpp>
#include <QWidget>

class RobotVisualizer : public QWidget
{

public:
    RobotVisualizer(QWidget *parent = 0) : QWidget(parent) {}

    void handleMessage(const lcm::ReceiveBuffer *rbuf,
                       const std::string &chan,
                       const lab21::viz_robot_t *msg)
    {
        std::cout << "got message! " << msg->x << std::endl;
        emit repaint();
    }

protected:
    void paintEvent(QPaintEvent *e)
    {
        QPainter qp(this);

        QColor color{0, 0, 0};
        qp.setBrush(color);

        // 150 is the center x and y of the window, in pixels
        // 10 is the radius, again in pixels.
        // you need to conver the x,y and radius from meters to pixels
        // which you can do by multiplying by m2pix.
        qp.drawEllipse(QPointF(150, 150), 10, 10);
    }

private:
    double m2pix{100};
};

void lcm_handler_func(std::shared_ptr<RobotVisualizer> const &visualizer)
{
    lcm::LCM lcm;
    if (!lcm.good())
    {
        throw std::runtime_error("LCM is not good!");
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    auto visualizer = std::make_shared<RobotVisualizer>();

    std::thread lcm_handler(lcm_handler_func, visualizer);

    visualizer->resize(300, 300);
    visualizer->setWindowTitle("Visualizer");
    visualizer->show();

    app.exec();

    lcm_handler.join();

    return EXIT_SUCCESS;
}
