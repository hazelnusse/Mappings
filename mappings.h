/*! \mainpage Dynamic system mapping classes
 *
 * This project provides four abstract base classes for the following types of
 * dynamic system mappings:
 *   - Non-autonomous, exogenous: \f$\frac{dx}{dt}=f(t, x(t), u(t))\f$ or \f$x_{i+1}
 *   = f(i, x_{i}, u_{i})\f$
 *   - Autonomous, exogenous: \f$\frac{dx}{dt}=f(x(t), u(t))\f$ or \f$x_{i+1} =
 *   f(x_{i}, u_{i})\f$
 *   - Non-autonomous, endogenous: \f$\frac{dx}{dt}=f(t, x(t))\f$ or \f$x_{i+1}
 *   = f(i, x_{i})\f$
 *   - Autonomous, endogenous: \f$\frac{dx}{dt}=f(x(t))\f$ or \f$x_{i+1} =
 *   f(x_{i})\f$
 *
 *   Autonomous implies the mapping is not explicitly dependent upon of the
 *   independent variable; for continuous time systems, this is analogous to
 *   time-invariant.  Non-autonomous implies that the mapping explicitly
 *   depends upon the independent variable; for continuous time systems this is
 *   analogous to time-varying.  Exogenous implies there are external inputs
 *   that are not explained by the model.  Endogenous is the opposite of
 *   exogenous, it implies that there are no external inputs that affect the
 *   mapping.
 *
 *   Note that all of the classes in this project assume that the mapping is
 *   dependent on the state; this covers most interesting cases, but not ones
 *   which purely depend upon the independent variable or on exogenous inputs.
 */

#ifndef __MAPPINGS_H__
#define __MAPPINGS_H__
#include <array>
  /*! \namespace dynamics
   *  \brief A namespace for classes and functions useful for dynamics.
   */
namespace dynamics {
  /*! \class MappingNonAutonomousExogenous
   *  \brief An abstract base class for ODE's and discrete maps.
   *  \tparam I Data type of independent variable (typically double or int)
   *  \tparam T Data type of state variables (typically double).
   *  \tparam N Dimension of the state space.
   *  \tparam M Dimension of exogenous inputs.
   *
   *  This class is intended to be subclassed by clients that need to implement
   *  a class to represent a model of a system that whose behavior is described
   *  either by a set of ordinary differential equations or discrete maps.
   *
   *  This class encompasses non-autonomous systems with exogenous inputs.
   */
  template <class I, class T, int N, int M>
  class MappingNonAutonomousExogenous {
    public:
      /*!
       * Pure virtual method that must be implemented by clients subclassing
       * Mapping.  This method should compute the right hand side of
       * ordinary differential equations of the form:
       *
       * \f[
       *   \frac{dx}{dt} = f(t, x(t), u(t))
       * \f]
       *
       * or discrete maps of the form
       *
       * \f[
       *   x_{i+1} = f(i, x_{i}, u_{i})
       * \f]
       *
       * \param[in] ti Independent parameter; typically time (for ODE's) or index
       *            (for discrete maps).
       * \param[in] x States, \f$x\in\mathbf{R}^{n}\f$.
       * \param[in] u Exogenous inputs \f$u\in\mathbf{R}^{m}\f$.
       * \param[out] rhs Right hand side of the mapping.
       */
      virtual void ComputeRHS(const I & ti,
                              const std::array<T, N> & x,
                              const std::array<T, M> & u,
                              std::array<T, N> & rhs) = 0;
      /*!
       * Destructor
       */
      virtual ~MappingNonAutonomousExogenous() {};
  };

  /*! \class MappingAutonomousExogenous
   *  \brief An abstract base class for ODE's and discrete maps.
   *  \tparam T Data type of state variables (typically double).
   *  \tparam N Dimension of the state space.
   *  \tparam M Dimension of exogenous inputs.
   *
   *  This class is intended to be subclassed by clients that need to implement
   *  a class to represent a model of a system that whose behavior is described
   *  either by a set of ordinary differential equations or discrete maps.
   *
   *  This class encompasses autonomous systems with exogenous inputs.
   */
  template <class T, int N, int M>
  class MappingAutonomousExogenous {
    public:
      /*!
       * Pure virtual method that must be implemented by clients subclassing
       * MappingAutonomous.  This method should compute the right hand side of
       * ordinary differential equations of the form:
       *
       * \f[
       *   \frac{dx}{dt} = f(x(t), u(t))
       * \f]
       *
       * or discrete maps of the form
       *
       * \f[
       *   x_{i+1} = f(x_{i}, u_{i})
       * \f]
       *
       * \param[in] x States, \f$x\in\mathbf{R}^{n}\f$.
       * \param[in] u Exogenous inputs \f$u\in\mathbf{R}^{m}\f$.
       * \param[out] rhs Right hand side of the mapping.
       * */
      virtual void ComputeRHS(const std::array<T, N> & x,
                              const std::array<T, M> & u,
                              std::array<T, N> & rhs) = 0;
      /*!
       * Destructor
       */
      virtual ~MappingAutonomousExogenous() {};
  };

  /*! \class MappingAutonomousEndogenous
   *  \brief An abstract base class for ODE's and discrete maps.
   *  \tparam T Data type of state variables (typically double).
   *  \tparam N Dimension of the state space.
   *
   *  This class is intended to be subclassed by clients that need to implement
   *  a class to represent a model of a system that whose behavior is described
   *  either by a set of ordinary differential equations or discrete maps.
   *
   *  This class encompasses autonomous, endogenous (no external inputs)
   *  systems.
   */
  template <class T, int N>
  class MappingAutonomousEndogenous {
    public:
      /*!
       * Pure virtual method that must be implemented by clients subclassing
       * MappingAutonomousEndogenous.  This method should compute the right
       * hand side of ordinary differential equations of the form:
       *
       * \f[
       *   \frac{dx}{dt} = f(x(t))
       * \f]
       *
       * or discrete maps of the form
       *
       * \f[
       *   x_{i+1} = f(x_{i})
       * \f]
       *
       * \param[in] x States, \f$x\in\mathbf{R}^{n}\f$.
       * \param[out] rhs Right hand side of the mapping.
       */
      virtual void ComputeRHS(const std::array<T, N> & x,
                              std::array<T, N> & rhs) = 0;
      /*!
       * Destructor
       */
      virtual ~MappingAutonomousEndogenous() {};
  };

  /*! \class MappingNonAutonomousEndogenous
   *  \brief An abstract base class for ODE's and discrete maps.
   *  \tparam I Data type of independent variable (typically double or int)
   *  \tparam T Data type of state variables (typically double).
   *  \tparam N Dimension of the state space.
   *
   *  This class is intended to be subclassed by clients that need to implement
   *  a class to represent a model of a system that whose behavior is described
   *  either by a set of ordinary differential equations or discrete maps.
   *
   *  This class encompasses non-autonomous, endogenous (no external inputs)
   *  systems.
   */
  template <class I, class T, int N>
  class MappingNonAutonomousEndogenous {
    public:
      /*!
       * Pure virtual method that must be implemented by clients subclassing
       * MappingEndogenous.  This method should compute the right hand side of
       * ordinary differential equations of the form:
       *
       * \f[
       *   \frac{dx}{dt} = f(t, x(t))
       * \f]
       *
       * or discrete maps of the form
       *
       * \f[
       *   x_{i+1} = f(i, x_{i})
       * \f]
       *
       * \param[in] ti Independent parameter; typically time (for ODE's) or index
       *            (for discrete maps).
       * \param[in] x States, \f$x\in\mathbf{R}^{n}\f$.
       * \param[out] rhs Right hand side of the mapping.
       */
      virtual void ComputeRHS(const I & ti,
                              const std::array<T, N> & x,
                              std::array<T, N> & rhs) = 0;
      /*!
       * Destructor
       */
      virtual ~MappingNonAutonomousEndogenous() {};
  };
}
#endif

/*! \example test_mappings.cc
 * This is an example of how to use the MappingAutonomousEndogenous class for a
 * pendulum and for the Henon map.
 */
