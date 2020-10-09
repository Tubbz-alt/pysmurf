/**
 *-----------------------------------------------------------------------------
 * Title      : Python Module for Filters
 * ----------------------------------------------------------------------------
 * File       : module.cpp
 * Created    : 2019-09-27
 * ----------------------------------------------------------------------------
 * Description:
 *   Python module setup
 * ----------------------------------------------------------------------------
 * This file is part of the smurf software platform. It is subject to
 * the license terms in the LICENSE.txt file found in the top-level directory
 * of this distribution and at:
 *    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html.
 * No part of the smurf software platform, including this file, may be
 * copied, modified, propagated, or distributed except according to the terms
 * contained in the LICENSE.txt file.
 * ----------------------------------------------------------------------------
**/

#include <boost/python.hpp>
#include <smurf/core/engines/module.h>
#include <smurf/core/engines/SysgenCryo.h>

namespace bp  = boost::python;
namespace sce = smurf::core::engines;

void sce::setup_module()
{
    // map the IO namespace to a sub-module
    bp::object module(bp::handle<>(bp::borrowed(PyImport_AddModule("smurf.core.engines"))));

    // make "from mypackage import class1" work
    bp::scope().attr("engines") = module;

    // set the current scope to the new sub-module
    bp::scope io_scope = module;

    sce::SysgenCryo::setup_python();
}
