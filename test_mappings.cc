#include <array>
#include <cmath>
#include <iostream>

#include "mappings.h"

class Pendulum : public dynamics::MappingAutonomousEndogenous<double, 2> {
  public:
    Pendulum(double l, double g = 9.81) : _l(l), _g(g) {}
    virtual void ComputeRHS(const std::array<double, 2> & x,
                            std::array<double, 2> & rhs)
    {
      rhs[0] = x[1];
      rhs[1] = -_g/_l*std::sin(x[0]);
    }

  private:
    double _l, _g;
};

class PendulumWithTorque : public dynamics::MappingAutonomousExogenous<double, 2, 1> {
  public:
    PendulumWithTorque(double l, double g = 9.81, double m = 1.0)
      : _l(l), _g(g), _m(m) {}

    virtual void ComputeRHS(const std::array<double, 2> & x,
                            const std::array<double, 1> & u,
                            std::array<double, 2> & rhs)
    {
      rhs[0] = x[1];
      rhs[1] = -_g/_l*std::sin(x[0]) + u[0]/(_m*_l*_l);
    }

  private:
    double _l, _g, _m;
};

class Henon : public dynamics::MappingAutonomousEndogenous<double, 2> {
  public:
    Henon(double a = 1.4, double b = 0.3) : _a(a), _b(b) {}
    virtual void ComputeRHS(const std::array<double, 2> & x,
                            std::array<double, 2> & rhs)
    {
      rhs[0] = x[1] + 1.0 - _a*x[0]*x[0];
      rhs[1] = _b * x[0];
    }

  private:
    double _a, _b;
};

int main(void)
{
  Pendulum p0(1.0, 1.0);
  std::array<double, 2> x = {{M_PI/2.0, 0.0}};
  std::array<double, 2> dxdt;
  p0.ComputeRHS(x, dxdt);
  std::cout << "Pendulum (autonomous, endogenous)" << std::endl;
  std::cout << dxdt[0] << std::endl << dxdt[1] << std::endl;
  
  PendulumWithTorque p1(1.0, 1.0, 1.0);
  std::array<double, 1> u = {{2.0}};
  dxdt[0] = dxdt[1] = -2.0;
  p1.ComputeRHS(x, u, dxdt);
  std::cout << "Pendulum (autonomous, exogenous)" << std::endl;
  std::cout << dxdt[0] << std::endl << dxdt[1] << std::endl;

  Henon h;
  x[0] = x[1] = 0.0;
  h.ComputeRHS(x, dxdt);
  std::cout << "Henon (autonomous, endogenous)" << std::endl;
  std::cout << dxdt[0] << std::endl << dxdt[1] << std::endl;

  return EXIT_SUCCESS;
}
